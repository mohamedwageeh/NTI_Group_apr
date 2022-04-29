/*
 * UART.c
 *
 * Created: 4/20/2022 10:49:05 AM
 *  Author: user
 */ 

#include "UART.h"

void M_UARTInit(void)
{
	u8 u8_Local_UCSRCValue = 0b10000000; //set bit no. 7 to select UCSRC register not UBRRH register
	
	
	//to enable input circuit
	ClrBit(DDRD,0);
	//to enable output circuit
	SetBit(DDRD,1);
	
	//to select asynchronous mode
	ClrBit(u8_Local_UCSRCValue,6);
	
	#if   CHARACTER_SIZE == 7
	ClrBit(UCSRB,2);
	ClrBit(u8_Local_UCSRCValue,1);
	SetBit(u8_Local_UCSRCValue,2);
	#elif CHARACTER_SIZE == 8
	ClrBit(UCSRB,2);
	SetBit(u8_Local_UCSRCValue,1);
	SetBit(u8_Local_UCSRCValue,2);
	#endif
	
	#if   PARITY_CHECK == EVEN
    ClrBit(u8_Local_UCSRCValue,4);
    SetBit(u8_Local_UCSRCValue,5);
	#elif PARITY_CHECK == ODD
	SetBit(u8_Local_UCSRCValue,4);
	SetBit(u8_Local_UCSRCValue,5);
	#elif PARITY_CHECK == OFF
	ClrBit(u8_Local_UCSRCValue,4);
	ClrBit(u8_Local_UCSRCValue,5);
	#endif
	
	#if   STOP_BITS == 1
	ClrBit(u8_Local_UCSRCValue,3);
	#elif STOP_BITS == 2
	SetBit(u8_Local_UCSRCValue,3);
	#endif
	
	#if   BAUD_RATE == 9600
	UBRRL = 103;
	#elif BAUD_RATE == 115200
	UBRRL = 8;
	#endif
	
	UCSRC = u8_Local_UCSRCValue;
	
	//to enable receiver circuit
	SetBit(UCSRB,4);
	//to enable transmitter circuit
	SetBit(UCSRB,3);	
}

void M_UARTSend(u8 u8_LocalData)
{
	UDR = u8_LocalData;
	while((GetBit(UCSRA,6)) == 0); //stuck in this while loop till data is fully sent -> (UCSRA,6) bit is a flag for (transmission is finished)
}

u8 M_UARTReceive(void)
{
	while((GetBit(UCSRA,7)) == 0); //stuck in this while loop till data is fully received -> (UCSRA,7) bit is a flag for (receiving is finished)
	return UDR;
}