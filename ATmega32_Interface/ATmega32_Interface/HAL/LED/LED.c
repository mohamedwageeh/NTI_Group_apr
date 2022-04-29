/*
 * LED.c
 *
 * Created: 4/5/2022 5:27:55 PM
 *  Author: user
 */ 

#include "LED.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void H_LedInit(u8 LedColour)
{
	switch(LedColour)
	{
		case R_LED:
		M_PinMode(R_LedPin,OUTPUT);
		break;
		case G_LED:
		M_PinMode(G_LedPin,OUTPUT);
		break;
		case B_LED:
		M_PinMode(B_LedPin,OUTPUT);
		break;
		default:
		break;
	}
}

void H_LedOn(u8 LedColour)
{
	switch(LedColour)
	{
		case R_LED:
		M_PinWrite(R_LedPin,HIGH);
		break;
		case G_LED:
		M_PinWrite(G_LedPin,HIGH);
		break;
		case B_LED:
		M_PinWrite(B_LedPin,HIGH);
		break;
		default:
		break;
	}	
}

void H_LedOff(u8 LedColour)
{
	switch(LedColour)
	{
		case R_LED:
		M_PinWrite(R_LedPin,LOW);
		break;
		case G_LED:
		M_PinWrite(G_LedPin,LOW);
		break;
		case B_LED:
		M_PinWrite(B_LedPin,LOW);
		break;
		default:
		break;
	}
}

void H_LedTog(u8 LedColour)
{
	switch(LedColour)
	{
		case R_LED:
		M_PinTog(R_LedPin);
		break;
		case G_LED:
		M_PinTog(G_LedPin);
		break;
		case B_LED:
		M_PinTog(B_LedPin);
		break;
		default:
		break;
	}
}

void H_LedBlink(u8 LedColour)
{
	switch(LedColour)
	{
		case R_LED:
		M_PinWrite(R_LedPin,HIGH);
		_delay_ms(50);
		M_PinWrite(R_LedPin,LOW);
		break;
		case G_LED:
		M_PinWrite(G_LedPin,HIGH);
		_delay_ms(50);
		M_PinWrite(G_LedPin,LOW);
		break;
		case B_LED:
		M_PinWrite(B_LedPin,HIGH);
		_delay_ms(50);
		M_PinWrite(B_LedPin,LOW);
		break;
		default:
		break;
	}
}