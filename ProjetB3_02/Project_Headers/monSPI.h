/*
 * SPI.h
 *
 *  Created on: May 16, 2018
 *      Author: dwenm
 */

#ifndef MONSPI_H_
#define MONSPI_H_

#include "Cpu.h"
#include "Events.h"
#include "SPI.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "mon_SPI.h"

void SPI_init(void);
unsigned char SPI_w(unsigned char *write, unsigned char lenght);
void SPI_WRITE(unsigned char *write, unsigned char lenght);
void SPI_Read_Multiple (unsigned char *read, unsigned char lenght);
unsigned char SPI_Read(void);
void delai(unsigned char i);

#endif MONSPI_H
