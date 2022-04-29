/*
 * LCD.h
 *
 * Created: 4/6/2022 2:05:58 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void H_LcdInit(void);
void H_LcdWriteCharacter(u8);
void H_LcdWriteCommand(u8);
void H_LcdWriteString(u8*);
void H_LcdWriteNumber(f64);
void H_LcdClear(void);
void H_LcdGoTo(u8,u8);

#define _4_BIT_MODE       4
#define _8_BIT_MODE       8





#endif /* LCD_H_ */