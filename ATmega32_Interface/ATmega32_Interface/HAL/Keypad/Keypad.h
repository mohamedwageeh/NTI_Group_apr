/*
 * Keypad.h
 *
 * Created: 4/10/2022 10:27:34 AM
 *  Author: user
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Keypad_CFG.h"
#include "DIO.h"

void H_KeypadInit(void);
u8 H_KeypadRead(void);



#endif /* KEYPAD_H_ */