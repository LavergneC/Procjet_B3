/*
 * optical.h
 *
 *  Created on: Apr 27, 2018
 *      Author: CLAVERGNE
 */

#ifndef OPTICAL_H_
#define OPTICAL_H_
#include "mon_SPI.h"
#include "monSPI.h"


void sensors_init(void);
void getValues(signed char dxdy[2], Module module);

#endif /* OPTICAL_H_ */
