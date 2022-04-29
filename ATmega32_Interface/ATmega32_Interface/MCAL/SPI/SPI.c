/*
 * SPI.c
 *
 * Created: 4/21/2022 10:26:55 AM
 *  Author: user
 */ 

#include "SPI.h"

//master
void M_SPIInit(void)
{
	#if   SPI_MODE == MASTER
	SetBit(SPCR,4);
	M_PinMode(MOSI,OUTPUT);
	M_PinMode(MISO,INPUT);
	M_PinMode(SS,OUTPUT);
	M_PinMode(SCK,OUTPUT);
	//to select division factor = 128 , SPI freq. = 125 KHZ
	SetBit(SPCR,0);
	SetBit(SPCR,1);
	//to setup at leading edge
	SetBit(SPCR,2);
	#elif SPI_MODE == SLAVE
	ClrBit(SPCR,4);
	M_PinMode(MOSI,INPUT);
	M_PinMode(MISO,OUTPUT);
	M_PinMode(SS,INPUT);
	M_PinMode(SCK,INPUT);
	//to setup at leading edge
	SetBit(SPCR,2);
	#endif
	
	//to select sending from LSB (least significant bit)
	SetBit(SPCR,5);
	
	//to enable SPI circuit
	SetBit(SPCR,6);
}

u8   M_SPITransceiving(u8 u8_LocalData)
{
	SPDR = u8_LocalData;
	while((GetBit(SPSR,7)) == 0); //stuck in this while loop till transmission is finished
	
	return SPDR;  //return what you receive after transmission
}