/*
 * RF.h
 *
 *  Created on: May 16, 2018
 *      Author: dwenm
 */

#ifndef RF_H_
#define RF_H_

#include "monSPI.h"

#define SUCCES_RX 0x55
#define RX_EMPTY 0xFF
#define FAILURE_RX 0x00

#define CS PTBD_PTBD5
#define CS_LOW CS=0
#define CS_HIGH CS=1

#define CE PTAD_PTAD7

#define R_RX_PAYLOAD 0x61

#define W_TX_PAYLOAD 0xA0
#define W_TX_PAYLOAD_NO_ACK 0xB0

#define FLUSH_TX 0xE1

#define FLUSH_RX 0xE2

#define WRITE_CONFIG_RF 0x20
#define READ_CONFIG_RF 0x00
#define CONFIG_RF_RX 0x7B
#define CONFIG_RF_TX 0x7A


#define WRITE_EN_AA 0x21
#define READ_EN_AA 0x01
#define EN_AA 0x03

#define WRITE_SETUP_RETR 0x24
#define SETUP_RETR 0x0A

#define WRITE_RF_SETUP 0x26
#define RF_SETUP 0x0F

#define WRITE_FEATURE 0x3D
#define FEATURE 0x00

#define WRITE_RX_PW_P1 0x32
#define RX_PW_P1 0x04

#define WRITE_RX_PW_P2 0x33
#define RX_PW_P2 0x00

#define WRITE_RX_PW_P3 0x34
#define RX_PW_P3 0x00

#define WRITE_RX_PW_P4 0x35
#define RX_PW_P4 0x00

#define WRITE_RX_PW_P5 0x36
#define RX_PW_P5 0x00

#define READ_EN_RXADDR 0x02
#define WRITE_EN_RXADDR 0x22
#define EN_REXADDR_P0 0x03

#define READ_SETUP_AW 0x03
#define WRITE_SETUP_AW 0x23
#define SETUP_AW_3BYTES 0x03

#define READ_RF_CH 0x05
#define WRITE_RF_CH 0x25
#define RF_CH_FREQUENCY 0x03

#define READ_STATUS 0x07
#define WRITE_STATUS 0x27
#define STATUS_RST_IRQ_RX 0x70

#define READ_RX_ADDR_P0 0x0A
#define WRITE_RX_ADDR_P0 0x2A

#define WRITE_RX_ADDR_P1 0x2B

#define READ_TX_ADDR 0x10
#define WRITE_TX_ADDR 0x30

#define READ_RX_PW_P0 0x11
#define WRITE_RX_PW_P0 0x31
#define RX_PW_P0_4BYTES 0x00

#define FIFO_STATUS 0x17

#define TX_BUFFER_LENGHT 7
#define RX_BUFFER_LENGHT 4
#define UPDATED 1
#define RESET 0

#define MVT_DX 0
#define MVT_DY 1
#define ROTATION1 2
#define ROTATION2_H 3
#define ROTATION2_L 4
#define BATTERIE 5
#define KICK 6

typedef struct data{
	unsigned char tx_buffer[7]; /* data : DX, DY, ROTATION1, ROTATION2_H, ROTATION2_L */
	unsigned char rx_buffer[4]; /*data : M1, M2, M3, M4 */
	unsigned char flag_updated;
}RF_datas;

void RF_Init (void);
void Receive_Register (unsigned char Addr_reg, unsigned char *read, unsigned char lenght);
void Config_Register (unsigned char Addr_reg,unsigned char Data_reg);
void Config_ADDR (unsigned char ADDR_REG, unsigned char *Data, unsigned char lenght);
unsigned char STATUS(void);
unsigned char RX_RF (unsigned char *receive_data, unsigned char lenght);
void TX_RF (unsigned char *data, unsigned char lenght_data);
void FLUSH_TX_RF (void);
void FLUSH_RX_RF (void);
void Transmit_Data (unsigned char Addr_reg, unsigned char *data, unsigned char lenght);
void delais(unsigned long delai);
void RX_ADDR(void);
void TX_ADDR(void);
void PowerUP_TX(void);
void PowerUP_RX(void);
unsigned char Test_Sending(void);
unsigned char rxFifoEmpty(void);
unsigned char dataReady(void);

#endif /* RF_H_ */
