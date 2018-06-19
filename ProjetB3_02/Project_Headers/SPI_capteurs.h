/*
 * mon_SPI.h
 *
 *  Created on: Apr 24, 2018
 *      Author: CLAVERGNE
 */

#ifndef SPI_CAPTERUS_H_
#define SPI_CAPTEURS_H_

#include "bsp.h"

typedef enum{MODULE1=0,MODULE2=1}Module;

#define MOTION 0x02
#define DX 0x03
#define DY 0x04
#define CS_1 PTAD_PTAD7
#define CS_2 PTAD_PTAD0

/*
* SPI_init
* Permet l'initialistion du module SPI du micro-contrôleur pour notre usage
*/
void SPI_init(void);

/*
* SPI_w_r
* Fonction pour écrire et lire par SPI
* @param : unsigned char write[2] : Tableau contenant les deux valeurs qui seront écrites sur le bus (mettre le segond à 0x00 pour une lecture)
           unsigned char *read : valeur lue sur le bus lors de la seconde écriture (ignorer en cas d'écriture)
*/
void SPI_w_r(unsigned char write[2], unsigned char *read, Module module);

#endif /* MON_SPI_H_ */
