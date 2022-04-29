/*
 * I2C.c
 *
 * Created: 4/24/2022 12:56:08 PM
 *  Author: user
 */ 

#include "I2C.h"

void M_I2CInit(void)
{
	#if   I2C_MODE  ==  MASTER
	//to select Fscl = 400K
	TWBR = 12;
	#elif I2C_MODE  ==  SLAVE
	TWAR = 0b10001110; //random address, last bit from left to right (LSB) is 0 to enable general call (broadcasting)
	#endif
	
	//to enable I2C circuit
	SetBit(TWCR,2);
}

void M_I2CStartCondition(void)
{
	SetBit(TWCR,5);
	
	SetBit(TWCR,7); //to clear the flag bit before checking it (set function make the bit zero for any flag)
	while((GetBit(TWCR,7)) == 0); //must be one to exit from the loop (one means this process is ended)
	
	while( (TWSR & 0xF8) != START_ACK  ); //ANDing TWSR with ( 1111 1000 ) to check the value of first 5 bits from the left
}

void M_I2CStopCondition(void)
{
	SetBit(TWCR,4);
	
	SetBit(TWCR,7); 
	//while((GetBit(TWCR,7)) == 0);
}

void M_I2CRepeatedStart(void)
{
	SetBit(TWCR,5); //same as start condition function
	
	SetBit(TWCR,7);
	while((GetBit(TWCR,7)) == 0);
	
	while( (TWSR & 0xF8) != REP_START_ACK   );
}

void M_I2CMasterSendSlaveAddressWrite(u8 u8_LocalAddress)
{
	TWDR = (u8_LocalAddress<<1); //shifting to left to make the last bit (operation bit) zero. (sending (address bits + operation bit) from left to right)

	SetBit(TWCR,7); 
	while((GetBit(TWCR,7)) == 0);
	
	while( ( TWSR & 0xF8 ) != SLAVE_AD_AND_WR_ACK );
}

void M_I2CMasterSendSlaveAddressRead(u8 u8_LocalAddress)
{
	TWDR = ((u8_LocalAddress<<1) | 1); //(shifting to left) + (ORing with one) to make the last bit (operation bit) one. (sending (address bits + operation bit) from left to right)
	
	SetBit(TWCR,7); 
	while((GetBit(TWCR,7)) == 0);
	
	while( (TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK  );
}

void M_I2CMasterSendByte(u8 u8_LocalByte)
{
	TWDR = u8_LocalByte;
	
	ClrBit(TWCR,5); //must be cleared 
	
	SetBit(TWCR,7);
	while((GetBit(TWCR,7)) == 0);
	
	while( (TWSR & 0xF8) != WR_BYTE_ACK  );
}

u8   M_I2CMasterReadByte(void)
{
	u8 u8_LocalData = 0;
	ClrBit(TWCR,5);
	ClrBit(TWCR,4);
	SetBit(TWCR,6);
	
	SetBit(TWCR,7); 
	while((GetBit(TWCR,7)) == 0);
	
	while( (TWSR & 0xF8) != RD_BYTE_WITH_ACK  );
	
	u8_LocalData = TWDR;
	return u8_LocalData;
}
