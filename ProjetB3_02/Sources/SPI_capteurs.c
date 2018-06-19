/*
 *  SPI_capteurs.c
 *
 *  Created on: Apr 24, 2018
 *      Author: CLAVERGNE
 */
#include "SPI_capteurs.h"
#include "SPI_RF.h"

/*
* SPI_init
* Permet l'initialistion du module SPI du micro-contrôleur pour notre usage
*/
void SPI_init(void){
	PTADD_PTADD0=1;
	PTADD_PTADD7=1;
	SPIBR=0x03;
	SPIC1_MSTR=1;
	SPIC1_CPOL=1;
	SPIC1_CPHA = 1;
	SPIC1_SPE=1;
	CS_1 = 1;
	CS_2 = 1;

	return;
}

/*
* SPI_w_r
* Fonction pour écrire et lire par SPI
* @param : unsigned char write[2] : Tableau contenant les deux valeurs qui seront écrites sur le bus (mettre le segond à 0x00 pour une lecture)
           unsigned char *read : valeur lue sur le bus lors de la seconde écriture (ignorer en cas d'écriture)
*/
void SPI_w_r(unsigned char write[2], unsigned char *read, Module module){
	unsigned char i;

	if(module == MODULE1)
		CS_1 = 0;
	
	else
		CS_2 =0;

	for(i=0; i<2; i++){
		if(SPIS_SPTEF){
			SPID = write[i];
		}

		delai(83);
		if(SPIS_SPRF){
			*read = SPID;
		}
		//delai(83);
	}

	if(module == MODULE1)
		CS_1 = 1;
	else
		CS_2 =1;

	return;
}

