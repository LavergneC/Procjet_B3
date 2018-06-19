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

/*
* sensors_init
* Permet d'initialiser le registre de configuration des deux capteurs optiques
*/
void sensors_init(void);

/*
* getValues
* Fonciton pour récupérer les valeurs de déplacement d'un capteur optique
* @param : signed char dxdy[2] : tableau où seront stocké les valeurs lues
           Module module : Permet de sélectionner le module que l'on veut interroger
*/
void getValues(signed char dxdy[2], Module module);

#endif /* OPTICAL_H_ */
