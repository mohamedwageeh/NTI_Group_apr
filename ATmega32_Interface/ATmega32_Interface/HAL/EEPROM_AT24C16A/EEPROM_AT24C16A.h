/*
 * EEPROM_AT24C16A.h
 *
 * Created: 4/25/2022 3:51:30 PM
 *  Author: user
 */ 


#ifndef EEPROM_AT24C16A_H_
#define EEPROM_AT24C16A_H_

#include "EEPROM_AT24C16A_CFG.h"
#include "I2C.h"

void H_EEPROM16K_Init(void);
void H_EEPROM16K_Write(u8 , u8 , u8);
u8   H_EEPROM16K_Read(u8 , u8);


#endif /* EEPROM_AT24C16A_H_ */