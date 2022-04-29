/*
 * Buzzer.c
 *
 * Created: 4/6/2022 10:56:23 AM
 *  Author: user
 */ 


#include "Buzzer.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void H_BuzzerInit(void)
{
		M_PinMode(BuzzerPin,OUTPUT);
}

void H_BuzzerOn(void)
{
	M_PinWrite(BuzzerPin,HIGH);
}

void H_BuzzerOff(void)
{
	M_PinWrite(BuzzerPin,LOW);
}

void H_BuzzerOnce(void)
{
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
}

void H_BuzzerTwice(void)
{
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
	_delay_ms(100);
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
	
}
void H_BuzzerTriple(void)
{
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
	_delay_ms(100);
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
	_delay_ms(100);
	H_BuzzerOn();
	_delay_ms(100);
	H_BuzzerOff();
	
}
void H_BuzzerLong(void)
{
	H_BuzzerOn();
	_delay_ms(1000);
	H_BuzzerOff();
}