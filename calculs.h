#include <stdio.h>
#include <math.h>

#define PERIODE_ECH (double)0.006 //6µs

#define M1DX (double)-0.36650
#define M1DY (double)0.930417
#define M2DX (double)-0.36650
#define M2DY (double)-0.930417
#define M3DX (double)0.707106
#define M3DY (double)-0.707106
#define M4DX (double)0.707106
#define M4DY (double)0.707106

#define Tech_centrale 0.024 //Temps entre chaque recureration de donne sur le MPU-6050
#define Tech_capteur 0.003 //Temps entre chaque recureration de donne sur les capteurs


typedef struct {
    signed short errors[100];   
    double kp;
    double ki;
    double kd;
    unsigned char i;
}VariablesPID;

/*
*initPID 
* La fonction permet d'initialiser la variable suite à sa création en initialisant toutes les variables de la structure
* @param : *vars : les variables PID correspondantes au processus souhaité
            double kp, ki, kd : Facteurs obtenus suite à la calibration utils pour le calcul
*/
void initPID(VariablesPID *vars, double kp, double ki, double kd);

/*
*getMoteurs
* La fonction permet d'obtenir les puissance à appliquer aux moteur à partir des informations de la manette
* @param : signed short dx : deplacement horizontale souhaité
           signed short dy : deplacement vertical souhaité
           signed short rotation : rotation souhaitée
           signed char VMoteurs[4] : tableau permetant de stocker les quatres valeurs obtenues
*/
void getVMoteurs(signed short dx, signed short dy, signed short rot, signed char VMoteurs[4]);

/*
* calculPID
* La fonction effectue le calcul de PID en mattant à jour l variable
* @param : signed short commande : valeur envoyer par la manette (dx ou dy ou rot)
*          signed short retourCapteur : deplacement mesurer grâce à un capteur optique par example
*          VariablesPID *variablesPID : Variable stockant toutes les valeurs persistantes utiles au calcul du PID
* @return : signed short : valeur de la nouvelle commande ajustée
*/
signed short calculPID(signed short commande, signed short retourCapteur, VariablesPID *variablesPID);

/*
* convertionCapteurToPID
* Cette fonciton permet de convertir une mesure d'un capteur optique afin de l'injecter dans un calcul de PID
* @param : signed char data : la donnée en provenance d'un capteur
* @return signed short : la valeur convertie
*/
signed short convertionCapteurToPID(signed char data);

/*
* getvitesse
* permet d'obtenir la vitesse du robot grâce aux valeurs des capteurs
* @param : signed char dx : mesure de deplacement horizontal
*          signed char dy : mesure de deplacement vertical
* @return : double : vitesse en m/s
*/
double getVitesse(signed char dx, signed char dy);


/*
* convAngleAbsolu
* Permet d'obtenir l'angle absolu du robot par rapport à sa position de départ ou depuis le dernier reset
* @param : signed short vitesse : valeur meusurée par la centrale inertielle (GYRO_Z)
           unsigned char reset : si reset !=0 la position actuelle devient la position de référence
           signed short * angle : valeur absolu de l'angle du robot
*/
void convAngleAbsolu(signed short vitesse, unsigned char reset, signed short * angle);