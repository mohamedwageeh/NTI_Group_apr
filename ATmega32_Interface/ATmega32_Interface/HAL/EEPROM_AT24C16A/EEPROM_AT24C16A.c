/*
 * EEPROM_AT24C16A.c
 *
 * Created: 4/25/2022 3:50:29 PM
 *  Author: user
 */ 

#include "EEPROM_AT24C16A.h"

void H_EEPROM16K_Init(void)
{
	M_I2CInit();
}

void H_EEPROM16K_Write(u8 u8_LocalPage , u8 u8_LocalByte , u8 u8_LocalData) //local byte means word address that data will be stored in
{
	M_I2CStartCondition();
	M_I2CMasterSendSlaveAddressWrite( 0x50 | u8_LocalPage ); //(0101 0000) = (0x50) ORing with page 2 for example (0000 0010) --> result = (0101 0010) and this result will be shifted to left inside the function -> (1010 0100)
	M_I2CMasterSendByte(u8_LocalByte);
	M_I2CMasterSendByte(u8_LocalData);
	M_I2CStopCondition();
}

u8   H_EEPROM16K_Read(u8 u8_LocalPage, u8 u8_LocalByte)
{
	u8 u8_LocalData = 0;
	M_I2CStartCondition();
	M_I2CMasterSendSlaveAddressWrite( 0x50 | u8_LocalPage ); //write first
	M_I2CMasterSendByte(u8_LocalByte); //then send word address that contains data which master wants
	
	M_I2CRepeatedStart(); //start again for reading process
	M_I2CMasterSendSlaveAddressRead(0x50 | u8_LocalPage); //(0101 0000) = (0x50) ORing with page 2 for example (0000 0010) --> result = (0101 0010) and this result will be shifted to left inside the function and then ORing with 1 -> (1010 0101)
	u8_LocalData = M_I2CMasterReadByte();
	M_I2CStopCondition();
	
	return u8_LocalData;
}