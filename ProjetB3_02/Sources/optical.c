/*
 * optical.c
 *
 *  Created on: Apr 27, 2018
 *      Author: CLAVERGNE
 */


#include "optical.h"

void sensors_init(){
	unsigned char writeConf[2] = {0x8A, 0x50};
	unsigned char data = 0x00;

	SPI_w_r(writeConf, &data, MODULE1);
	SPI_w_r(writeConf, &data, MODULE2);

	return;
}

void getValues(signed char dxdy[2], Module module){
	unsigned char data;
	unsigned char read[2]={MOTION,0x00};

	SPI_w_r(read, &data, module);

	if(data & 0x80){
		read[0]=DX;
		SPI_w_r(read, &data, module);
		dxdy[0] = (signed char)data;
		read[0]= DY;
		SPI_w_r(read, &data, module);
		dxdy[1] = (signed char)data;
	}
	else {
		dxdy[0] = 0;
		dxdy[1] = 0;
	}
	return;
}

