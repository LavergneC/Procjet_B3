#include "calculs.h"

/*
*getMoteurs
* La fonction permet d'obtenir les puissance à appliquer aux moteur à partir des informations de la manette
* @param : signed short dx : deplacement horizontale souhaité
           signed short dy : deplacement vertical souhaité
           signed short rotation : rotation souhaitée
           signed char VMoteurs[4] : tableau permetant de stocker les quatres valeurs obtenues
*/
void getVMoteurs(signed short dx, signed short dy, signed short rot, signed char VMoteurs[4]){
    unsigned char i,j;
    signed long temp[4]={0,0,0,0};
    signed short depacement =0;

    rot = (signed char)(rot/254);
    temp[0] = dx * M1DX + dy * M1DY;
    temp[1] = dx * M2DX + dy * M2DY;
    temp[2] = dx * M3DX + dy * M3DY;
    temp[3] = dx * M4DX + dy * M4DY;

    for(i=0; i<4;i++){
        temp[i]/=364; //On remet temp à l'echelle [-128,+127]
        if((temp[i] + rot ) < -128 || (temp[i] + rot )>127){ // Si la rotation fait sorir de l'interval
            for(j=0; j<4; j++) /*on diminue toutes les valeurs d'un quart*/
                temp[j] -= temp[j]/4;
        }
    }
     for(i=0; i<4;i++){
          if((temp[i] + rot ) < -128 || (temp[i] + rot )>127){
            depacement = fabs(temp[i]+rot) - 127;
            if(temp[i]>0)
                rot -= depacement;
            else
                rot += depacement;
          }
     }
        
    for(i=0; i<4; i++){
         temp[i] += rot;
         VMoteurs[i] = temp[i];
    }
}

/*
*initPID 
* La fonction permet d'initialiser la variable suite à sa création en initialisant toutes les variables de la structure
* @param : *vars : les variables PID correspondantes au processus souhaité
            double kp, ki, kd : Facteurs obtenus suite à la calibration utils pour le calcul
*/
void initPID(VariablesPID *vars, double kp, double ki, double kd){ 
    unsigned char i;

    for(i=0; i<100; i++)
        vars->errors[i] = 0;
    vars->kp = kp;
    vars->ki = ki;
    vars->kd = kd;
    vars->i = 0;
}

/*
* calculPID
* La fonction effectue le calcul de PID en mattant à jour l variable
* @param : signed short commande : valeur envoyer par la manette (dx ou dy ou rot)
*          signed short retourCapteur : deplacement mesurer grâce à un capteur optique par example
*          VariablesPID *variablesPID : Variable stockant toutes les valeurs persistantes utiles au calcul du PID
* @return : signed short : valeur de la nouvelle commande ajustée
*/
signed short calculPID(signed short commande, signed short retourCapteur, VariablesPID *variablesPID){
    unsigned char j;
    double P, I, D;
    signed short somme;
    signed char error = commande - retourCapteur;

    I=0;
    variablesPID->i = (variablesPID->i+1)%100;
    variablesPID->errors[variablesPID->i] = error;

    P = variablesPID->kp * error;
    
    for(j=0; j<100; j++)
        I+= variablesPID->errors[j] * PERIODE_ECH;
    I *= variablesPID->ki;

    D = (error - variablesPID->errors[variablesPID->i-1]) / PERIODE_ECH;
    D *= variablesPID->kd;
    

    if (P+I+D>32767)
        somme = 32767;
    else if (P+I+D <-32767)
        somme = -32767;
    else  
        somme = (signed short) P+I+D;

    return somme;
}

/*
* convertionCapteurToPID
* Cette fonciton permet de convertir une mesure d'un capteur optique afin de l'injecter dans un calcul de PID
* @param : signed char data : la donnée en provenance d'un capteur
* @return signed short : la valeur convertie
*/
signed short convertionCapteurToPID(signed char data){
    double tempData = data;

    tempData *=34.6784; /* x0.0254/400*3276.7/0.006 */

    return (signed short)tempData;
}

/*
* convAngleAbsolu
* Permet d'obtenir l'angle absolu du robot par rapport à sa position de départ ou depuis le dernier reset
* @param : signed short vitesse : valeur meusurée par la centrale inertielle (GYRO_Z)
           unsigned char reset : si reset !=0 la position actuelle devient la position de référence
           signed short * angle : valeur absolu de l'angle du robot
*/
void convAngleAbsolu(signed short vitesse, unsigned char reset, signed short * angle){
    float decalage=0;
    signed short newAngle;
    if(reset)
        *angle=0;
    decalage = vitesse*Tech_centrale;
    newAngle= *angle + decalage;
    newAngle/=131; //131 count /°/s
    *angle = newAngle;
    return;
}

/*
* getvitesse
* permet d'obtenir la vitesse du robot grâce aux valeurs des capteurs
* @param : signed char dx : mesure de deplacement horizontal
*          signed char dy : mesure de deplacement vertical
* @return : double : vitesse en m/s
*/
double getVitesse(signed char dx, signed char dy){
    signed short normeV = sqrt(dx*dx + dy*dy);
    double distance = (normeV * 2.54)/400; //une valeur de 400 correspond à un pied (2.25 cm)
    return distance/Tech_capteur;
}