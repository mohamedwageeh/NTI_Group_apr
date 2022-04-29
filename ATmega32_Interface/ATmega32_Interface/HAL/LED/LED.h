/*
 * LED.h
 *
 * Created: 4/5/2022 5:28:39 PM
 *  Author: user
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"
#include "LED_CFG.h"

#define R_LED      1
#define G_LED      2
#define B_LED      3

void H_LedInit(u8);
void H_LedOn(u8);
void H_LedOff(u8);
void H_LedTog(u8);
void H_LedBlink(u8);



#endif /* LED_H_ */