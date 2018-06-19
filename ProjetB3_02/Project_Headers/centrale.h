/*
 * centrale.h
 *
 *  Created on: Mar 29, 2018
 *      Author: CLAVERGNE
 */
#include "I2C.h"

#ifndef CENTRALE_H_
#define CENTRALE_H_

#define PWR_MGMT_1 0x6B
#define INT_PIN_CRG 0x37
#define ACCEL_CONFIG 0x1C
#define GYRO_CONFIG 0x1B
#define CONFIG 0x1A

#define ACCEL_X 0x3B
#define ACCEL_Y 0x3D
#define GIRO_Z 0x47

#define CENTRALE_TIMEOUT 10

/*
* initCentrale
* fonction pour initialiser les registres de configuraiton du module
* @param : I2C_Status *status : Variable permetant de s'assurer que les communicatin I2C ont fonctionés
*/
void initCentrale(I2C_Status *status);

/*
* getData
* Permet de lire une donnée stockée sur deux registres se suivant;
* @param : unsigned char registre : adresse du premier registre à lire
* 		   unsigned char *data1 : valeur de retour pour le premier registre lu à l'adresse 'regsitre'
		   unsigned char *data2 : valeur de retour pour le second registre lu à l'adresse 'regsitre'+1
*/
void getData(unsigned char registre, unsigned char *data1, unsigned char *data2);

/*
* visuAcce
* Routine permettant de tester les communication avec la centrale en affichant par liaison série ACCEL_X, ACCLE_Y et GYRO_Z
*/
void visuAcce(void);

#endif /* CENTRALE_H_ */
