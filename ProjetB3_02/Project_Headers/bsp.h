/*
 * bsp.h
 *
 *  Created on: Oct 6, 2017
 *      Author: Clément
 */

#ifndef BSP_H_
#define BSP_H_

#include "Cpu.h"
#include "Events.h"
#include "SCI.h"

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define VT100_ESC       (27) 
#define VT100_FORM_FEED (12)

#define putc(ch) {				\
	while (SCIS1_TDRE == 0);	\
		SCID = (ch);		\
}

void move(unsigned char x, unsigned char y);
void clear_screen(void);
//void delai(unsigned short delay);

void putHex(unsigned char ch);
void putSSort(signed short ss);

void draw(void);

#endif /* BSP_H_ */
