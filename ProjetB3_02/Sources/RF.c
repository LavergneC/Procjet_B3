/*
 * RF.c
 *
 *  Created on: May 16, 2018
 *      Author: dwenm
 */

#include "RF.h"

unsigned char ADDR_RF[]={0x51,0x51,0x51,0x51,0x51};

unsigned char ADDR_RF_RX[]={0xB3,0xB3,0xB3,0xB3,0xB3};

unsigned char ADDR_RF_TX[]={0x42,0x42,0x42,0x42,0x42};

void Receive_Register (unsigned char Addr_reg, unsigned char *read, unsigned char lenght){
	CS_LOW;
	SPI_w(&Addr_reg,1);
	SPI_Read_Multiple(read,lenght);
	CS_HIGH;
}

void Config_Register (unsigned char Addr_reg,unsigned char Data_reg){
	CS_LOW;
	SPI_w(&Addr_reg,1);
	SPI_w(&Data_reg,1);
	CS_HIGH;
	//delai(50);
	return;
}

void Transmit_Data (unsigned char Addr_reg, unsigned char *data, unsigned char lenght){
	CS_LOW;
	SPI_w(&Addr_reg,1);
	SPI_WRITE(data,lenght);
	CS_HIGH;
	return;
}

void Config_ADDR (unsigned char ADDR_REG, unsigned char *Data, unsigned char lenght){
	CS_LOW;
	SPI_w(&ADDR_REG,1);
	SPI_WRITE(Data, lenght);
	CS_HIGH;
	return;
}

unsigned char STATUS(void){
	unsigned char NOP=0xFF;
	volatile unsigned char status;
	CS_LOW;
	status = SPI_w(&NOP,1);
	CS_HIGH;
	return status;
}

unsigned char RX_RF (unsigned char *receive_data, unsigned char lenght){
	volatile unsigned char status,result;
	CE=0;
	/*Config_Register(WRITE_CONFIG_RF,CONFIG_RF_RX);
	CE=1;
	delais(25000);*/
	//*$delai(10);
	if (dataReady()){
		Receive_Register(R_RX_PAYLOAD,&receive_data[0],lenght);

		status = STATUS();
		if ((status&0x40) != 0x40)
			result = SUCCES_RX;
		else 
			result = RX_EMPTY;
	}
	else 
		result = FAILURE_RX;
	CE=1;
	return result;
}

unsigned char dataReady() {
	volatile unsigned char status;

	status=STATUS();
	if ( status & 0x40 ) 
	{
		return 1;
	}

	return !rxFifoEmpty();
}

unsigned char rxFifoEmpty(){
	volatile unsigned char fifoStatus;

	Receive_Register(FIFO_STATUS,&fifoStatus,1);

	return (fifoStatus & 0x01);
}

void TX_RF (unsigned char *data, unsigned char lenght_data){
	CE=0;
	Config_Register(WRITE_CONFIG_RF,CONFIG_RF_TX);
	Transmit_Data(W_TX_PAYLOAD,&data[0],lenght_data);
	CE=1;
	while(Test_Sending());
	Config_Register(WRITE_STATUS,0x70);
	CE=0;
	Config_Register(WRITE_CONFIG_RF,CONFIG_RF_RX);
	CE=1;
	delais(250000);
}

unsigned char Test_Sending(void){
	volatile unsigned char status;
	status=STATUS();
	if ((status & 0x20) || (status & 0x10)){
		return 0;
	}
	return 1;
}

void FLUSH_TX_RF (void){
	unsigned char flush_tx = FLUSH_TX;
	CS=0;
	SPI_w(&flush_tx,1);
	CS=1;
	return;
}

void FLUSH_RX_RF (void){
	unsigned char flush_rx = FLUSH_RX;
	CS=0;
	SPI_w(&flush_rx,1);
	CS=1;
	return;
}

void RF_Init (void){
	CE=0;
	CS=1;
	Config_Register(WRITE_RF_CH,RF_CH_FREQUENCY);
	Config_Register(WRITE_RX_PW_P0,RX_PW_P0_4BYTES);
	Config_Register(WRITE_RX_PW_P1,RX_PW_P1);
	Config_Register(WRITE_RX_PW_P2,RX_PW_P2);
	Config_Register(WRITE_RX_PW_P3,RX_PW_P3);
	Config_Register(WRITE_RX_PW_P4,RX_PW_P4);
	Config_Register(WRITE_RX_PW_P5,RX_PW_P5);
	Config_Register(WRITE_RF_SETUP,RF_SETUP);
	Config_Register(WRITE_CONFIG_RF,0x78);
	Config_Register(WRITE_EN_AA, EN_AA);
	Config_Register(WRITE_EN_RXADDR,EN_REXADDR_P0);
	Config_Register(WRITE_SETUP_RETR,SETUP_RETR);
	Config_Register(WRITE_SETUP_AW,SETUP_AW_3BYTES);
	PowerUP_RX();

	return;
}

void RX_ADDR(void){
	CE=0;
	Config_ADDR(WRITE_RX_ADDR_P1,&ADDR_RF_RX[0],5);
	CE=1;
}

void TX_ADDR(void){
	Config_ADDR(WRITE_RX_ADDR_P0,&ADDR_RF_TX[0],5);
	Config_ADDR(WRITE_TX_ADDR,&ADDR_RF_TX[0],5);
}

void PowerUP_TX(void){
	Config_Register(WRITE_STATUS,0x70);
	Config_Register(WRITE_CONFIG_RF,CONFIG_RF_TX);
}

void PowerUP_RX(void){
	FLUSH_RX_RF();
	Config_Register(WRITE_STATUS,0x70);
	CE=0;
	Config_Register(WRITE_CONFIG_RF,CONFIG_RF_RX);
	CE=1;
}

void delais(unsigned long delai){
	unsigned long i;
	for(i=0;i==delai;i++);
	return;
}
