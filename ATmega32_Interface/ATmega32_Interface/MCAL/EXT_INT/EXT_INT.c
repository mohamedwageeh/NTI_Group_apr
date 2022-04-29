/*
 * EXT_INT.c
 *
 * Created: 4/11/2022 10:07:04 AM
 *  Author: user
 */ 

#include "EXT_INT.h"
#include <avr/interrupt.h>   //library for ISR function

void (*CallBack)(void);

void M_ExtInt0Init(void)
{
	#if SENSE_CONTROL == FALLING_EDGE
	ClrBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif SENSE_CONTROL == RISING_EDGE
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif SENSE_CONTROL == LOW_LEVEL
	ClrBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif SENSE_CONTROL == ANY_LOGICAL_CHANGE
	SetBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#endif
	//to enable global INT
	SetBit(SREG,7);
	//to enable ExtInt0 INT
	SetBit(GICR,6);
}

void M_EXT_INT_SetCallBack(void(*ptr)(void))
{
	CallBack = ptr;
}

ISR(INT0_vect)
{
	CallBack();
}