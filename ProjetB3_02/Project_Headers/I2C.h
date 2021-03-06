/*
 * I2C.h
 *
 *  Created on: Mar 28, 2018
 *      Author: CLAVERGNE
 */

#ifndef I2C_H_
#define I2C_H_

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define TIME_OUT_I2C 10
#define MPU_ADR (0x68<<1)

typedef enum{I2C_OK=0, I2C_FAILED}I2C_Status;


/*
* I2C_init
* Permet l'initialisation du module I2C du micro-contrôleur pour notre usage
*/
void I2C_init(void);

/*
* Fonctions permettant la génération de commandes I2C de base
*/
void I2C_start();
void I2C_stop();
void I2C_restart();
/*------------------------------------------------------------*/

/*
* Fonctions I2C pour la lecture/écriture d'un octect
*/
void I2C_write_oct(unsigned char oct, I2C_Status *status);
void I2C_read_oct(unsigned char * oct, I2C_Status *status,unsigned char NACK);
/*-------------------------------------------------*/

/*
* Fonctions I2C pour la lecture/écriture d'une donnée dans un registre
*/
void I2C_write(unsigned char registre, unsigned char data, I2C_Status *status);
void I2C_read(unsigned char registre, unsigned char *data, I2C_Status *status);
/*-------------------------------------------------*/

#endif /* I2C_H_ */
