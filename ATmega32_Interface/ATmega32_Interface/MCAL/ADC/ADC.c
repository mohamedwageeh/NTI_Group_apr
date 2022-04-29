/*
 * ADC.c
 *
 * Created: 4/12/2022 10:25:16 AM
 *  Author: user
 */ 

#include "ADC.h"

void M_ADCInit(void)
{
	#if   VREF   == AVCC
	SetBit(ADMUX,6);
	ClrBit(ADMUX,7);
	#elif VREF   == AREF_PIN
	ClrBit(ADMUX,6);
	ClrBit(ADMUX,7);
	#elif VREF   == _2_VOLT
	SetBit(ADMUX,6);
	SetBit(ADMUX,7);
	#endif
	
	#if   RESULT_ADJUST   == RIGHT
	ClrBit(ADMUX,5);
	#elif RESULT_ADJUST   == LIFT
	SetBit(ADMUX,5);
	#endif
	
	//we use default configuration for pin choice which is ADC0 (PA0)
	
	#if   PRESCALER_DIV_FAC   == _64
	ClrBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#elif PRESCALER_DIV_FAC   == _128
	SetBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#endif
	
	#if   AUTO_TRIGGER   == ON // (ON) means taking multi-readings
	SetBit(ADCSRA,5); 
	//we use default configuration which is free running mode ( takes readings continuously)           
	#elif AUTO_TRIGGER   == OFF
	ClrBit(ADCSRA,5);
	#endif
	
	//to enable ADC (enable bit must be at the end of init. func.)
	SetBit(ADCSRA,7);
}

u16  M_ADCRead(void)
{
	//start conversion enable
	SetBit(ADCSRA,6);
	//to check flag (if flag = 1 -> conversion is started) 
	while( GetBit(ADCSRA,4) == 0 );
	return ADC_VALUE;
}