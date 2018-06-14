/*
 * SPI.c
 *
 *  Created on: May 16, 2018
 *      Author: dwenm
 */

#include "monSPI.h"

unsigned char SPI_w(unsigned char *write, unsigned char lenght){
	unsigned char read,i;
	
	for (i=0;i<lenght;i++){
		
		if(SPIS_SPTEF)
			SPID = write[i];
		
		delai(50);
		
		if(SPIS_SPRF)
			read = SPID;
		
	}
	
	return read;
}

void SPI_WRITE(unsigned char *write, unsigned char lenght){
	unsigned char read,i;
	
	for (i=0;i<lenght;i++){
		
		if(SPIS_SPTEF)
			SPID = write[i];
		
		delai(50);
		
		if(SPIS_SPRF)
			read = SPID;
		
	}
	
	return;
}

void SPI_Read_Multiple (unsigned char *read, unsigned char lenght){
	unsigned char i;
	for (i=0;i<lenght;i++){
		if(SPIS_SPTEF)
			SPID = 0x00;
		delai(50);
		if(SPIS_SPRF)
			read[i] = SPID;
	}
	return;
}

unsigned char SPI_Read(void){
	unsigned char read;
	
	if(SPIS_SPTEF){
		SPID = 0x00;
	}

	delai(50);
	if(SPIS_SPRF){
		read = SPID;
	}
	//delai(83);

	return read;
}

void delai(unsigned char i){
	while(--i);
	return;
}
