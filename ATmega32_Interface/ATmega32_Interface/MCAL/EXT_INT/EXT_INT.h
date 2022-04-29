/*
 * EXT_INT.h
 *
 * Created: 4/11/2022 10:08:01 AM
 *  Author: user
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_CFG.h"
#include "LED.h"
#include "BIT_MATH.h"
#include "REG.h"


void M_ExtInt0Init(void);
void M_EXT_INT_SetCallBack(void(*)(void));

#define FALLING_EDGE        1
#define RISING_EDGE         2
#define LOW_LEVEL           3
#define ANY_LOGICAL_CHANGE  4



#endif /* EXT_INT_H_ */