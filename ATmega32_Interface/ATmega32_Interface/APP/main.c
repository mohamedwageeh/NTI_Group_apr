/*
 * ATmega32_Interface.c
 *
 * Created: 4/5/2022 3:16:18 PM
 * Author : user
 */ 

#include "LED.h"
#include "PushButton.h"
#include "Buzzer.h"
#include "LCD.h"
#include "Keypad.h"
#include "EXT_INT.h"
#include "ADC.h"
#include "Temp.h"
#include "Timer_0.h"
#include "Timer_1.h"
#include "ServoMotor.h"
#include "DC_MOTOR.h"
#include "StepperMotor.h"
#include "WatchDogTimer.h"
#include "UART.h"
#include "SPI.h"
#include "I2C.h"
#include "EEPROM_AT24C16A.h"

#include "APP.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

//void EXT_INT_EXC(void);
//void Timer0_EXC(void);


int main(void)
{
	//H_PushButtonInit();
	//H_LedInit(R_LED);
	//H_SsdInit();
	//H_BuzzerInit();
    //H_LcdInit();
	//H_KeypadInit();
	//M_ExtInt0Init();
	//M_ADCInit(); 
	//H_TempSensorInit();
	//M_Timer0Init();
	//M_PWM0Init();
	//M_PWM1Init();
	//H_ServoMotorInit();
	//H_DCMotorInit();
	//H_StepperMotorInit();
	//M_WDTInit();
	//M_UARTInit();
	//M_SPIInit();
	//M_I2CInit();
	//H_EEPROM16K_Init();
	
	
	
	
	
	
	
	/*_delay_ms(1000);
	H_LcdInit();
	H_EEPROM16K_Init();
	u8 counter = H_EEPROM16K_Read(1,20);
	while(1)
	{
		H_EEPROM16K_Write(1,20,counter);
		H_LcdWriteNumber(counter);
		counter++;
		_delay_ms(500);
		H_LcdClear();
	}*/
	
	
	/*//master code
	H_LcdInit();
	H_LcdWriteString("MASTER MC");
	H_LcdGoTo(1,0);
    H_LcdWriteString("SLAVE DATA");
	u8 x = 0;
	x = M_SPITransceiving(5);
	H_LcdWriteNumber(x);
	while(1)
	{
	
	}*/
	
	
	/*H_LcdInit();
	M_UARTInit();
	u8 x = 0;
	while(1)
	{
		x = M_UARTReceive();
		H_LcdWriteCharacter(x);
	}*/
	

	
	/*H_ServoMotorSetAngle(180);
	H_ServoMotorStart();
	while(1);*/
	
	
	/*H_LedInit(R_LED);
	H_LedOn(R_LED);
	while(1)
	{
		M_WDTRefresh();
	}*/
	

	/*H_StepperMotorRotate(20);
	while(1);*/
	
	/*H_DCMotorSetDirection(A_CLK_W);
	H_DCMotorSetSpeed(100);
	H_DCMotorStart();
	while(1);*/
	
	
	/*H_ServoMotorSetDutyCycleAngle(80);
	H_ServoMotorStart();
	while(1);*/
	
	
	
	/*M_PWM1SetDutyCycle(100);
	M_PWM1Start();
	while(1);*/

	/*M_PWM0SetDutyCycle(100);
	M_PWM0Start();
	while(1);*/
	
	/*H_LedInit(R_LED);
	H_PushButtonInit();
	M_Timer0_SetCallBack(Timer0_EXC);
	M_Timer0SetTime(500);
	M_Timer0Start();
	while(1)
	{
		if(H_PushButtonRead() == PRESSED)
		{
			M_Timer0Stop();
		}
	}*/
	

	
	/*H_LcdInit();
	u16 temp = 0;
	while(1)
	{
		temp = H_TempSensorRead();
		H_LcdWriteNumber(temp);
		_delay_ms(500);
		H_LcdClear();
	}*/
	
	
	/*H_LcdInit();
	u16 data = 0;
	while(1)
	{
		data = M_ADCRead();
		H_LcdWriteNumber(data);
		_delay_ms(500);
		H_LcdClear();
	}*/
	
	
	/*M_EXT_INT_SetCallBack(EXT_INT_EXC);
	while(1)
	{
		
	}*/
	
	
	//u8 data = 0;
	//u8 Counter = 0;
	/*while(1)
	{
		data = H_KeypadRead();
		if(data != 0)
		{
			if(Counter==15)
			{
				H_LcdGoTo(1,0);
			}
			else if(Counter==30)
			{
				Counter = 0;
				H_LcdClear();
				H_LcdGoTo(0,0);
			}
			H_LcdWriteCharacter(data);
			Counter++;
		}
	}*/
	
	
     //u8 data = 0;
     //u8 Counter = 0;
     //u8 i=0;
     //u8 t[10];
     //u8 reading;
     //u8 NUM1,NUM2,Result;
	/*while(1)
	{
	   data = H_KeypadRead();
	   if(data != 0)
	    {
			if(Counter==15)
			{
				H_LcdGoTo(1,0);
			}
			else if(Counter==30)
			{
				Counter = 0;
				H_LcdClear();
				H_LcdGoTo(0,0);
			}
		   reading=H_LcdWriteCharacter(data);
		   Counter++;
		   if(reading != '=')
		   {
			   H_LcdWriteCharacter(data);
		       t[i]= H_LcdWriteCharacter(data);
			   i++;
			   NUM1= t[i];
			   NUM2= t[i+1];
			   Result= NUM1+NUM2;
		   }
		   else if(reading == '=')
		   {
			   H_LcdWriteCharacter(data);
			   H_LcdWriteCharacter(Result-48);
			   
		   }
		   
	    }
	}*/
	
	
    
/*while(1)
{
	reading = H_PushButtonRead();
	if(reading==0)
	{
		
		_delay_ms(150);           //to solve Bouncing problem
		reading = H_PushButtonRead();
		if(reading==0)
		{
			while(H_PushButtonRead == 0); //to be turned on after pressing the button (LED isn't on till the finger is far enough from the button)
			do
			{
			H_LedTog(R_LED);
			_delay_ms(50);
			H_LedTog(R_LED);
			_delay_ms(50);
			
			}while(H_PushButtonRead()!=1);
		}
	}
}*/
	
	
	
	/*H_LcdWriteNumber(12.2);
	while(1);*/
	
   /*u8 i,j;
   
   while(1)
   {
	for(i=0;i<16;i++)
	{
		for(j=0;j<i;j++)
		{
			H_LcdWriteCharacter(' ');
		}
		H_LcdWriteString("Wageeh");
		_delay_ms(300);
		H_LcdClear();
	}
   }*/
   
	/*H_BuzzerTriple();
	while(1);*/
	
	/*u8 x = 0;
	while (1)
	{
		H_SsdDisplayBlink(x);
		x++;
	}*/
	
		/*while(1)
		{
		   if(H_PushButtonRead() == PRESSED)
		       H_LedOn(R_LED);
		   
		   else if(H_PushButtonRead() == RELEASED)
			   H_LedOff(R_LED);
		}*/
	
	
	/*while(1)
	{
		while(H_PushButtonRead() == PRESSED)
		{
			H_LedOn(R_LED);
		}
		H_LedOff(R_LED);
	}*/

   /* while (1) 
    {
		H_LedOn(R_LED);
		_delay_ms(1250);
		H_LedOff(R_LED);
		_delay_ms(1250);
    }*/
}

/*void EXT_INT_EXC(void)
{
	H_LedOn(R_LED);
}*/

/*void Timer0_EXC(void)
{
	H_LedTog(R_LED);
}*/

