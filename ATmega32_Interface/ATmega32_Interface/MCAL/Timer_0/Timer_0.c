/*
 * Timer_0.c
 *
 * Created: 4/13/2022 10:17:41 AM
 *  Author: user
 */ 
#include "Timer_0.h"
#include <avr/interrupt.h> //to include ISR function

void (*CallBack)(void);
u32 u32_Global_No_of_ov;
u8  u8_GlobalRemainTickS;
u32 u32_Global_No_of_cm;

void M_Timer0Init(void)
{
	#if TIMER0_MODE     == NORMAL_MODE
	ClrBit(TCCR0,3);
	ClrBit(TCCR0,6);
	//to enable timer0 overflow interrupt
	SetBit(TIMSK,0);
	#elif TIMER0_MODE   == CTC_MODE
	SetBit(TCCR0,3);
	ClrBit(TCCR0,6);
	//to enable timer0 compare match interrupt
	SetBit(TIMSK,1);
	#endif
	//to enable global interrupt
	SetBit(SREG,7);
}

void M_Timer0SetTime(u32 u32_LocalDesiredTime)  //u32_LocalDesiredTime is in m.sec. for ex. = 1000
{
	u32 u32_LocalTickTime = PRESCALER_DIV_FAC / CRYSTAL_FREQ; //in micro second
	u32 u32_LocalTotalTicks = (u32_LocalDesiredTime * 1000) / u32_LocalTickTime; //u32_LocalTotalTicks = 15625 ticks
	#if TIMER0_MODE     == NORMAL_MODE
	   u32_Global_No_of_ov = u32_LocalTotalTicks / 256; //each 1 overflow takes 256 ticks, u32_Global_No_of_ov = 61.03515625 overflows
	u8 u8_GlobalRemainTickS  = u32_LocalTotalTicks % 256; //u8_GlobalRemainTickS = 9 ticks
	if(u8_GlobalRemainTickS != 0)
	{
	    TCNT0                   = 256 - u8_GlobalRemainTickS; //to start from (256-9) = tick no. 247
		u32_Global_No_of_ov++;  //to make u32_Global_No_of_ov = 62 overflows
	}
	#elif TIMER0_MODE   == CTC_MODE
	u8 u8_LocalDivisionNumber = 255;
	while(u32_LocalTotalTicks % u8_LocalDivisionNumber) //while(u32_LocalTotalTicks % u8_LocalDivisionNumber = 0) CPU will not enter while loop 
	{
		u8_LocalDivisionNumber--;
	}
	u32_Global_No_of_cm = u32_LocalTotalTicks / u8_LocalDivisionNumber;
	OCR0                = u8_LocalDivisionNumber - 1; //because compare circuit increases u8_LocalDivisionNumber by (1)
	#endif
	
}

void M_Timer0Start(void)
{
	#if PRESCALER_DIV_FAC   == 1024
	//to start timer0 & select 1024 division factor
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif PRESCALER_DIV_FAC == 256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}

void M_Timer0Stop(void)
{
	//to stop timer0
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}


void M_Timer0_SetCallBack(void(*ptr)(void))
{
	CallBack = ptr;
}

#if TIMER0_MODE     == NORMAL_MODE
ISR(TIMER0_OVF_vect) //each overflow causes interrupt and CPU comes to this function
{
	static u32 u32_StaticLocalCounter = 0;
	u32_StaticLocalCounter++;
	if(u32_StaticLocalCounter == u32_Global_No_of_ov) //to check counter = 62
	{
		CallBack();
		u32_StaticLocalCounter = 0;
		TCNT0                   = 256 - u8_GlobalRemainTickS; //to start from tick no. 247 again after each (1000) m sec.
	}
}
#elif TIMER0_MODE   == CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 u32_StaticLocalCounter = 0;
	u32_StaticLocalCounter++;
	if(u32_StaticLocalCounter == u32_Global_No_of_cm) //to check counter = 62
	{
		CallBack();
		u32_StaticLocalCounter = 0;
	}
}
#endif

void M_PWM0Init(void)
{
	//to enable output circuit (all pins are input by default)
	SetBit(DDRB,3);
	
	#if   PWM0MODE == FAST_PWM_MODE
	//to select Fast PWM mode
	SetBit(TCCR0,3);
	SetBit(TCCR0,6);
	//to select non-inverted Fast PWM mode
	ClrBit(TCCR0,4);
	SetBit(TCCR0,5);
	#elif PWM0MODE == PHASE_CORRECT_PWM_MODE
	ClrBit(TCCR0,3);
	SetBit(TCCR0,6);
	//to select non-inverted Fast PWM mode
	ClrBit(TCCR0,4);
	SetBit(TCCR0,5);
	#endif
}

void M_PWM0SetDutyCycle(u8 u8_LocalDutyCycle)
{
	#if   PWM0MODE == FAST_PWM_MODE
	OCR0 = ((u8_LocalDutyCycle * 256) / 100) - 1;
	#elif PWM0MODE == PHASE_CORRECT_PWM_MODE
	OCR0 = ((u8_LocalDutyCycle * 255) / 100);
	#endif
}

void M_PWM0Start(void)
{
	M_Timer0Start();
}

void M_PWM0Stop(void)
{
	M_Timer0Stop();
}