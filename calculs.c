#include "calculs.h"

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

void initPID(VariablesPID *vars, double kp, double ki, double kd){ 
    unsigned char i;

    for(i=0; i<100; i++)
        vars->errors[i] = 0;
    vars->kp = kp;
    vars->ki = ki;
    vars->kd = kd;
    vars->i = 0;
}

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

void afficherVar(VariablesPID *var, unsigned char afficherTab){
    unsigned char j;

    printf("Variable PID :\n");
    printf("    kp : %f | ki : %f | kd : %f \n i = %d \n",var->kp,var->ki,var->kd, var->i);
    if(afficherTab){
        printf("    Liste err :\n");
        for(j=0; j<100; j++)
            printf("    %d, ",var->errors[j]);
            printf("\n");
    }
}

unsigned long absL(signed long ch){
    if(ch<0)
        ch = -ch;
    return (unsigned long)ch;
}

signed short convertionCapteurToPID(signed char data){
    double tempData = data;

    tempData *=34.6784; /* x0.0254/400*3276.7/0.006 */

    return (signed short)tempData;
}

void convAngleAbsolu(signed short vitesse, unsigned char reset, signed short * angle){
    float decalage=0;
    signed short newAngle;
    if(reset)
        *angle=0;
    decalage = vitesse*Tech_centrale;
    newAngle= *angle + decalage;
    newAngle/=131;
    *angle = newAngle;
    return;
}

double getVitesse(signed char dx, signed char dy){
    signed short normeV = sqrt(dx*dx + dy*dy);
    double distance = (normeV * 2.54)/400;
    return distance/Tech_capteur;
}