/*
 * ServoMotor.c
 *
 * Created: 4/17/2022 12:44:34 PM
 *  Author: user
 */ 

#include "ServoMotor.h"

void H_ServoMotorInit(void)
{
	M_PWM1Init();
}

void H_ServoMotorSetAngle(u16 u16_LocalAngle)
{ 
	f32 f32_LocalDutyCycle = ((5 * u16_LocalAngle) / 180) + 5;
	M_PWM1SetDutyCycle(f32_LocalDutyCycle);
}

void H_ServoMotorStart(void)
{
	M_PWM1Start();
}

void H_ServoMotorStop(void)
{
	M_PWM1Stop();
}