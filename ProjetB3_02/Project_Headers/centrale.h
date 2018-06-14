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

typedef struct{
	signed short dx;
	signed short dy;
}Vecteur;

void initCentrale(I2C_Status *status);
void getData(unsigned char registre, unsigned char *data1, unsigned char *data2);
void visuAcce(void);

#endif /* CENTRALE_H_ */
