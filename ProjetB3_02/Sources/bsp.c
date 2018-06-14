/*
 * bps.c
 *
 *  Created on: Oct 6, 2017
 *      Author: Clément
 */
#include "bsp.h"

void move(unsigned char x, unsigned char y) 
{
	putc(VT100_ESC); 
	putc('['); 
	putc( '0' + (y / 100)); 
	putc('0' + ((y / 10) % 10));
	putc( '0' + (y % 10)); 
	putc(';'); 
	putc ('0' + (x / 100 )); 
	putc('0' + ((x / 10) % 10)); 
	putc('0' + (x % 10));
	putc('H');
}

void clear_screen(void)
{
	putc(VT100_ESC);
	putc('[');
	putc('2');
	putc('J');
	putc(VT100_ESC);
	putc('[');
	putc('?');
	putc('2');
	putc('5');
	putc('l');
}

/*void delai(unsigned short delay){
	unsigned short i;
	for (i=0; i <= delay; i++);
	return;
}*/

void putHex(unsigned char ch){
	const  unsigned char charHex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	unsigned char tempCh = ch;

	tempCh = (ch>>4);
	putc(charHex[tempCh]);
	tempCh = ch & 0x0f;
	putc(charHex[tempCh]);
}

void putSSort(signed short ss){
	signed short mask = ss;

	mask &= 0x8000;
	if(mask){
		putc('-');
		ss = ~ss;
		ss++;
	}
	else
		putc(' ');

	putHex(ss>>8);
	putHex(ss&0x00FF);
	return;
}

void draw(){
	unsigned char i;

	move(0,31);
	for(i=0;i<157; i++)
		putc('-');
	for(i=0; i<63; i++){
		move(78,i);
		putc('|');
	}

	move(0,32);
	putc('-');
	putc('4');
	move(1,31);
	putc('|');

	move(37,32);
	putc('-');
	putc('2');
	move(37,31);
	putc('|');

	move(78+37,32);
	putc('+');
	putc('2');
	move(78+37,31);
	putc('|');

	move(156,32);
	putc('+');
	putc('4');
	move(157,31);
	putc('|');

	move(78,31);
	putc('+');

	move(77,0);
	putc('4');
	putc('-');

	move(77,15);
	putc('2');
	putc('-');

	move(76,31+15);
	putc('-');
	putc('2');
	putc('-');

	move(76,62);
	putc('-');
	putc('4');
	putc('-');

	move (1,1);
	putc('r');
	putc('o');
	putc('t');
	putc('A');
	putc(' ');
	putc(':');
	putc(' ');

	move (1,2);
	putc('a');
	putc('n');
	putc('g');
	putc('l');
	putc('e');
	putc(':');
	putc(' ');
}
