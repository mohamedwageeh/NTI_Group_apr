/*
 * DC_MOTOR.c
 *
 * Created: 4/18/2022 9:44:59 AM
 *  Author: user
 */ 

#include "DC_MOTOR.h"

void H_DCMotorInit(void)
{
	M_PinMode(IN_1,OUTPUT);
	M_PinMode(IN_2,OUTPUT);
    M_PWM0Init();	
}

void H_DCMotorSetDirection(u8 u8_LocalDirection)
{
	switch(u8_LocalDirection)
	{
		case  CLK_W:
		M_PinWrite(IN_1,HIGH);
		M_PinWrite(IN_2,LOW);
		break;
		case  A_CLK_W:
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,HIGH);
		break;
		default:
		break;
	}
}

void H_DCMotorSetSpeed(u32 u32_LocalSpeed)
{
	M_PWM0SetDutyCycle(u32_LocalSpeed); //without mapping assuming speed = duty cycle
}

void H_DCMotorStart(void)
{
	M_PWM0Start();
}

void H_DCMotorStop(void)
{
	M_PWM0Stop();
}