/*
 * mon_SPI.h
 *
 *  Created on: Apr 24, 2018
 *      Author: CLAVERGNE
 */

#ifndef SPI_CAPTERUS_H_
#define SPI_CAPTEURS_H_

#include "bsp.h"
#include "SPI_RF.h"


typedef enum{MODULE1=0,MODULE2=1}Module;



#define MOTION 0x02
#define DX 0x03
#define DY 0x04
#define CS_1 PTAD_PTAD7
#define CS_2 PTAD_PTAD0

void SPI_init(void);
void SPI_w_r(unsigned char write[2], unsigned char *read, Module module);

#endif /* MON_SPI_H_ */
