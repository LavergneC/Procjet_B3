/*
 * mon_SPI.h
 *
 *  Created on: Apr 24, 2018
 *      Author: CLAVERGNE
 */

#ifndef MON_SPI_H_
#define MON_SPI_H_

//#include "SPI.h"
#include "bsp.h"
#include "monSPI.h"

typedef enum {MODULE1,MODULE2}Module;

#define MOTION 0x02
#define DX 0x03
#define DY 0x04
#define CS_1 PTAD_PTAD7
#define CS_2 PTAD_PTAD0

void SPI_init(void);
void SPI_w_r(unsigned char write[2], unsigned char *read, Module module);

#endif /* MON_SPI_H_ */
