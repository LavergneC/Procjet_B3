/*
 * centrale.c
 *
 *  Created on: Mar 29, 2018
 *      Author: CLAVERGNE
 */

#include "centrale.h"
#include "I2C.h"
#include "bsp.h"

void initCentrale(I2C_Status *status){
	I2C_write(PWR_MGMT_1, 0x09, status);
	if(*status == I2C_FAILED)
		return;

	I2C_write(INT_PIN_CRG, 0x00, status);
	if(*status == I2C_FAILED)
		return;

	I2C_write(ACCEL_CONFIG, 0x08, status); 
	if(*status == I2C_FAILED)
		return;

	I2C_write(GYRO_CONFIG, 0x08, status); 
	if(*status == I2C_FAILED)
		return;

	I2C_write(CONFIG, 0x01, status); 
	if(*status == I2C_FAILED)
		return;

	*status = I2C_OK;
	return;
}

void getData(unsigned char registre, unsigned char *data1, unsigned char *data2){
	unsigned char cpt=0;
	I2C_Status status;

	do{
		I2C_read(registre, data1, &status);
	}while(status==I2C_FAILED && cpt <CENTRALE_TIMEOUT);
	cpt=0;
	do{
		I2C_read(registre+1, data2, &status);
	}while(status==I2C_FAILED && cpt <CENTRALE_TIMEOUT);

	return;
}

void visuAcce(void){
	Vecteur v1,v2;
	unsigned char dx1,dx2,dy1,dy2,rot1,rot2;
	unsigned char who_am_i = 0x00;
	signed short rotA;
	signed short rotP = 0;
	signed short angle = 0;
	unsigned short i = 0;
	unsigned err = 0;
	I2C_Status status = I2C_OK;

	I2C_init();
	initCentrale(&status);

	clear_screen();
	I2C_read(0x75, &who_am_i, &status);

	v1.dx = 1;
	v1.dy=5;


	draw();

	for(;;){

		getData(ACCEL_X, &dx1, &dx2);
		getData(ACCEL_Y, &dy1, &dy2);
		getData(GIRO_Z, &rot1, &rot2);

		v1.dx = (signed short)(((unsigned short)dx1<<8) | (unsigned short)dx2);
		v1.dy = (signed short)(((unsigned short)dy1<<8) | (unsigned short)dy2);
		rotA = (signed short)(((unsigned short)rot1<<8) | (unsigned short)rot2);

		v1.dx /= 424;
		v1.dy /= -1056;

		move(v2.dx+77, v2.dy+31);

		if(v2.dx+77 == 78){
			putc('|');
		}
		else if(v2.dy+31 == 31){
			putc('-');
		}
		else  
			putc(' ');

		v2= v1;
		move(v1.dx + 77, v2.dy+31);
		putc('o');

		angle +=rotA/255;
		
		move(7,1);
		putSSort(rotA);
		move(7,2);
		putSSort(angle);
	}

}



