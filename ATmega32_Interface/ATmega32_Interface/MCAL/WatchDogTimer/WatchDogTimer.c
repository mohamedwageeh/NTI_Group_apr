/*
 * WatchDogTimer.c
 *
 * Created: 4/19/2022 10:49:16 AM
 *  Author: user
 */ 

#include "WatchDogTimer.h"

void M_WDTInit(void)
{
	//to select 2.1 seconds (window time) (time to reset CPU)
	SetBit(WDTCR,0);
	SetBit(WDTCR,1);
	SetBit(WDTCR,2);
	//to enable WDT
	SetBit(WDTCR,3);
}

void M_WDTRefresh()
{
	asm("WDR"); //assembly instruction to reset WDT
}