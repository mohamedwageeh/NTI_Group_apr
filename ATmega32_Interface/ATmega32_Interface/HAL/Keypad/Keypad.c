/*
 * Keypad.c
 *
 * Created: 4/10/2022 10:26:59 AM
 *  Author: user
 */ 

#include "Keypad.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void H_KeypadInit(void)
{
	M_PinMode(Keypad_R0,OUTPUT);
	M_PinMode(Keypad_R1,OUTPUT);
	M_PinMode(Keypad_R2,OUTPUT);
	M_PinMode(Keypad_R3,OUTPUT);
	
	M_PinMode(Keypad_C0,INPUT);
	M_PinMode(Keypad_C1,INPUT);
	M_PinMode(Keypad_C2,INPUT);
	M_PinMode(Keypad_C3,INPUT);
	
	M_PinPullUp(Keypad_C0,ENABLE);
	M_PinPullUp(Keypad_C1,ENABLE);
	M_PinPullUp(Keypad_C2,ENABLE);
	M_PinPullUp(Keypad_C3,ENABLE);
}

u8 H_KeypadRead(void)
{
	u8 Keypad_arr[4][4] = {{'7' , '8' , '9' , '/'},
		                   {'4' , '5' , '6' , '*'},
						   {'1' , '2' , '3' , '-'},
						   {'C' , '0' , '=' , '+'}};  
	u8 row = 0;
	u8 col = 0;
	u8 reading = 1;
	u8 data;
	
	for(row = Keypad_R0 ; row <= Keypad_R3 ; row++)
	{
		M_PinWrite(row,LOW);
		
		for(col = Keypad_C0 ; col <= Keypad_C3 ; col++)
		{
			reading = M_PinRead(col);
			
			if(reading==0)
			{
				_delay_ms(150);           //to solve Bouncing problem
				reading = M_PinRead(col);
				if(reading==0)
				{
				 while(M_PinRead(col) == 0); //to display after pressing the button (LCD doesn't display till the finger is far enough from the button)
				 data = Keypad_arr[row - Keypad_R0][col - Keypad_C0];
				}
			}
		}
		
		M_PinWrite(row,HIGH);
	}
	return data;
}