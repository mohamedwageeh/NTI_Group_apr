/*
 * Timer_1.c
 *
 * Created: 4/17/2022 10:11:34 AM
 *  Author: user
 */ 

#include "Timer_1.h"

void M_PWM1Init(void)
{
	//to enable output circuit (all pins are input by default)
	SetBit(DDRD,5);
	//to select mode no. 14 -> fast PWM with ICR top
	ClrBit(TCCR1A,0);
	SetBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	SetBit(TCCR1B,4);
	//to select non-inverted Fast PWM mode
	ClrBit(TCCR1A,6);
	SetBit(TCCR1A,7);
	ICR1 = 1250;     //at F(wpm) = 50 HZ for servo-motor -> where: F(pwm) = F(timer) / ICR1 = (16 MHZ / 256) / ICR1
}

void M_PWM1SetFrequency(u32 u32_LocalFrequency)
{
	//ICR1 = ( CRYSTAL_FREQ / PRESCALER_DIV_FAC ) / u32_LocalFrequency;
}

void M_PWM1SetDutyCycle(f32 f32_LocalDutyCycle)
{
	OCR1A = ((f32_LocalDutyCycle * ICR1) / 100) - 1;
}

void M_PWM1Start(void)
{
	/*//to Start & select 1024 prescaler division factor
	SetBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);*/
	//to Start & select 256 prescaler division factor
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);
}

void M_PWM1Stop(void)
{
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
}