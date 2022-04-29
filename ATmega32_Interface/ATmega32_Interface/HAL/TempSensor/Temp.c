/*
 * Temp.c
 *
 * Created: 4/12/2022 1:44:07 PM
 *  Author: user
 */ 

#include "Temp.h"

void H_TempSensorInit(void)
{
	M_ADCInit();
}

u16  H_TempSensorRead(void)
{
	u16 ADC_Reading = M_ADCRead();
	u16 Temp = ((u32)ADC_Reading * 500) / 1023;  //after mapping
	return Temp;
}