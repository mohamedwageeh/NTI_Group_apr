/*
 * StepperMotor.c
 *
 * Created: 4/19/2022 9:43:55 AM
 *  Author: user
 */ 

#include "StepperMotor.h"

#define  F_CPU 16000000UL
#include <util/delay.h>


void H_StepperMotorInit(void)
{
	M_PinMode(IN_1,OUTPUT);
	M_PinMode(IN_2,OUTPUT);
	M_PinMode(IN_3,OUTPUT);
	M_PinMode(IN_4,OUTPUT);
}

void H_StepperMotorRotate(u32 u32_LocalAngle)  //mapping is a must for the angle but here we didn't do that
{
	u32 u32_Local_i;
	
	for(u32_Local_i = 0 ; u32_Local_i < u32_LocalAngle ; u32_Local_i++)
	{
	    M_PinWrite(IN_1,HIGH); //coil 1 is high to rotate a quarter rotation and so on
	    M_PinWrite(IN_2,LOW);
	    M_PinWrite(IN_3,LOW);
	    M_PinWrite(IN_4,LOW);
	    
	    _delay_ms(2); //to give time for coils 
	    
	    M_PinWrite(IN_1,LOW); //each coil make a quarter rotation
	    M_PinWrite(IN_2,HIGH);
	    M_PinWrite(IN_3,LOW);
	    M_PinWrite(IN_4,LOW);
	    
	    _delay_ms(2);
	    
	    M_PinWrite(IN_1,LOW);
	    M_PinWrite(IN_2,LOW);
	    M_PinWrite(IN_3,HIGH);
	    M_PinWrite(IN_4,LOW);
	    
	    _delay_ms(2);
	    
	    M_PinWrite(IN_1,LOW);
	    M_PinWrite(IN_2,LOW);
	    M_PinWrite(IN_3,LOW);
	    M_PinWrite(IN_4,HIGH); //with coil 4 you make a full rotation
	    
	    _delay_ms(2);
		
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,LOW);
		M_PinWrite(IN_3,LOW);
		M_PinWrite(IN_4,LOW);
	}
}