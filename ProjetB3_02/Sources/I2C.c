/*
 * I2C.c
 *
 *  Created on: Mar 28, 2018
 *      Author: CLAVERGNE
 */
#include "I2C.h"

/*
* Fonctions permettant la génération de commandes I2C de base
*/
void I2C_start(){
	IICC1_MST = 1;
	while(!IICS_BUSY);
	return;
}

void I2C_restart(){
	IICC1_RSTA = 1;
	while(!IICS_BUSY);
	return;
}


void I2C_stop(){
	IICC1_MST = 0;
	while(IICS_BUSY);
	return;
}
/*------------------------------------------------------------*/

/*
* I2C_init
* Permet l'initialisation du module I2C du micro-contrôleur pour notre usage
*/
void I2C_init(){
	IICC1 = 0x00;
	IICC1_IICEN = 1;
	IICC1_IICIE = 0;	
	PTAPE_PTAPE2=1;
	PTAPE_PTAPE3=1;
	return;
}

/*
* Fonctions I2C pour la lecture/écriture d'un octect
*/
void I2C_write_oct(unsigned char oct, I2C_Status *status){
	unsigned char flag = 1;
	unsigned char i = 0;
	unsigned char i2 = 0;
	
	for(i=0; i<TIME_OUT_I2C && flag; i++){
		if(IICS_TCF){
			IICD = oct;
			flag = 0;
		}
	}
	if(flag){ //Si il n'y a pas eu d'�criture
		*status = I2C_FAILED;
		return;
	}
		 
	flag = 1;
	
	while(!IICS_IICIF && i < TIME_OUT_I2C) /* Attente de fin de l'envoi */
		i++;
	IICS_IICIF=1;
		
	while(
			IICS_RXAK && i2 < TIME_OUT_I2C)/* en attente du ACK */
		i2++;
		
	if(i2 == TIME_OUT_I2C || i==TIME_OUT_I2C) /* si le ACK � pas march� */
		*status = I2C_FAILED;
	
	*status = I2C_OK;
	return;
}

void I2C_read_oct(unsigned char * oct, I2C_Status *status,unsigned char NACK){
	unsigned char flag = 1;
	unsigned char i = 0;
	
	for(i=0; i<TIME_OUT_I2C && flag; i++){
		if(IICS_TCF){
			IICC_TXAK = NACK; /* Envoi d'un no acknowledge*/
			*oct = IICD; /*lecture de la donn�e*/
			flag = 0;
		}
	}
	if(flag){ //Si il n'y a pas eu d'�criture
		*status = I2C_FAILED;
		return;
	}
	
	while(!IICS_IICIF && i < TIME_OUT_I2C) /*v�rification du no ack */
			i++;
	if(i == TIME_OUT_I2C){
		*status = I2C_FAILED;
		return;
	}
	IICS_IICIF=1;
	*status = I2C_OK;
	return;
}

/*
* Fonctions I2C pour la lecture/écriture d'une donnée dans un registre
*/
void I2C_write(unsigned char registre, unsigned char data, I2C_Status *status){
	unsigned char i=0;
	unsigned char flag = 1;
	
	IICC1_TX = 1; /* Mode TX */
	I2C_start();
	I2C_write_oct(MPU_ADR, status);
	if(*status == I2C_FAILED)
		return;
	
	I2C_write_oct(registre, status);
	if (*status == I2C_FAILED)
		return;
	
	I2C_write_oct(data, status);
	if (*status == I2C_FAILED)
		return;
	
	I2C_stop();
	
	*status = I2C_OK;
	return;
	
}

void I2C_read(unsigned char registre, unsigned char *data, I2C_Status *status){
	
	IICC1_TX = 1; /* Mode TX */
	
	I2C_start();
	
	I2C_write_oct(MPU_ADR, status);
	if(*status == I2C_FAILED)
			return;
	
	I2C_write_oct(registre, status);
		if (*status == I2C_FAILED)
			return;
		
	I2C_restart();
	I2C_write_oct(MPU_ADR+1, status);
		if(*status == I2C_FAILED)
				return;
		
	IICC1_TX = 0; /* Mode RX */
	I2C_read_oct(data, status,0);
	I2C_read_oct(data, status,1);
	if (*status == I2C_FAILED)
		return;
	
	I2C_stop();
	*status = I2C_OK;
	return;
	
}

