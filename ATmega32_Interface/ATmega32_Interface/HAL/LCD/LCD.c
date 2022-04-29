/*
 * LCD.c
 *
 * Created: 4/6/2022 2:05:15 PM
 *  Author: user
 */ 


#include "LCD.h"

void H_LcdInit(void)
{
	M_PinMode(LCD_RS_Pin,OUTPUT);
	M_PinMode(LCD_EN_Pin,OUTPUT);
	M_PinMode(LCD_RW_Pin,OUTPUT);
	
	#if LCD_MODE     ==   _8_BIT_MODE
	M_PinMode(LCD_Data_Pin_0,OUTPUT);
	M_PinMode(LCD_Data_Pin_1,OUTPUT);
	M_PinMode(LCD_Data_Pin_2,OUTPUT);
	M_PinMode(LCD_Data_Pin_3,OUTPUT);
	M_PinMode(LCD_Data_Pin_4,OUTPUT);
	M_PinMode(LCD_Data_Pin_5,OUTPUT);
	M_PinMode(LCD_Data_Pin_6,OUTPUT);
	M_PinMode(LCD_Data_Pin_7,OUTPUT);
	
	_delay_ms(500);  //to synchronize with LCD's MC (500ms because power up & start up code need bigger delay)
	
	H_LcdWriteCommand(0x38); //to activate 8-bit mode
	H_LcdWriteCommand(0x0C); //to turn display on, cursor off
	H_LcdWriteCommand(0x02); //to return home
	H_LcdWriteCommand(0x06); //to display from left to right
	H_LcdWriteCommand(0x01); //to clear LCD
	
	#elif LCD_MODE    ==   _4_BIT_MODE
	M_PinMode(LCD_Data_Pin_4,OUTPUT);
	M_PinMode(LCD_Data_Pin_5,OUTPUT);
	M_PinMode(LCD_Data_Pin_6,OUTPUT);
	M_PinMode(LCD_Data_Pin_7,OUTPUT);
	
	_delay_ms(500);
	
	H_LcdWriteCommand(0x33);    //
	H_LcdWriteCommand(0x32);    //
	H_LcdWriteCommand(0x28);    //3 commands to activate 4-bit mode
	H_LcdWriteCommand(0x0C);    // to turn display on , cursor off
	H_LcdWriteCommand(0x02);    // to return home
	H_LcdWriteCommand(0x06);    // to display from left to right
	H_LcdWriteCommand(0x01);    // to clear LCD
	#endif
}

void H_LcdWriteCharacter(u8 U8_LocalCharacter)
{
	M_PinWrite(LCD_RS_Pin,HIGH);
	M_PinWrite(LCD_RW_Pin,LOW);
	
	#if LCD_MODE    ==  _8_BIT_MODE
	LCD_Data_Port = U8_LocalCharacter;
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);  //to synchronize with LCD's MC
	
	#elif LCD_MODE    ==   _4_BIT_MODE
	LCD_Data_Port = ((U8_LocalCharacter & 0b11110000) | (LCD_Data_Port & 0b00001111));
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);
	
	LCD_Data_Port = ( (U8_LocalCharacter << 4) | (LCD_Data_Port & 0b00001111) );
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);
	
	#endif
}

void H_LcdWriteCommand(u8 U8_LocalCommand)
{
	M_PinWrite(LCD_RS_Pin,LOW);
	M_PinWrite(LCD_RW_Pin,LOW);
	
	#if LCD_MODE    ==  _8_BIT_MODE
	LCD_Data_Port = U8_LocalCommand;
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);  //to synchronize with LCD's MC
	
	#elif LCD_MODE    ==   _4_BIT_MODE
	LCD_Data_Port = ((U8_LocalCommand & 0b11110000) | (LCD_Data_Port & 0b00001111));
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);
	
	LCD_Data_Port = ( (U8_LocalCommand << 4) | (LCD_Data_Port & 0b00001111) );
	M_PinWrite(LCD_EN_Pin,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_Pin,LOW);
	
	_delay_ms(5);
	
	#endif
}

void H_LcdWriteString(u8* U8_LocalPtr)
{
	u8 u8_LocalCounter = 0; 
	
	while(U8_LocalPtr[u8_LocalCounter] != '\0')
	{
	     H_LcdWriteCharacter(U8_LocalPtr[u8_LocalCounter]);
		 u8_LocalCounter++;
	}
}

void H_LcdWriteNumber(f64 f64_LocalNumber)  //124 for example
{
	s32 s32_LocalNumberCopy = f64_LocalNumber;
	//f64 f64_LocalNumberDecimalPart = f64_LocalNumber - s32_LocalNumberCopy;
	u8 u8_LocalAraay[10] = {0};
	//u8 u8_LocalAraay2[10] = {0};
	s8 s8_LocalCounter = 0;
	//s8 s8_LocalCounter2 = 0;
	
 /*if(f64_LocalNumberDecimalPart != 0.0)
 {
     while(s32_LocalNumberCopy != 0)
     {
	     u8_LocalAraay[s8_LocalCounter] = s32_LocalNumberCopy % 10;  //u8_LocalArray[0] = 4
	     s8_LocalCounter++;                                          //make s8_LocalCounter = 1
	     s32_LocalNumberCopy = s32_LocalNumberCopy / 10;             //u8_LocalArray = 12 and so on
     }                                                           //after loop: s8_LocalCounter = 4 -> u8_LocalArray[4] = garbage
     s8_LocalCounter--;                                          //make s8_LocalCounter = 3 -> u8_LocalArray[3] = 1
     
     while(s8_LocalCounter >= 0)
     {
	     H_LcdWriteCharacter(u8_LocalAraay[s8_LocalCounter]+'0'); //ASCII code of '0' = 48 -> 1+48=50 which is the ASCII code of '1'
	     s8_LocalCounter--;                                       //make s8_LocalCounter = 2 and so on
     }
	 
	 H_LcdWriteCharacter('.');
	
	s32 s32_LocalNumberIntPart;
	f64 f64_LocalNumberDecimalPart2;
	do 
	{
	 f64_LocalNumberDecimalPart = f64_LocalNumberDecimalPart * 10;
	 s32 s32_LocalNumberIntPart = f64_LocalNumberDecimalPart;
	 f64 f64_LocalNumberDecimalPart2 = f64_LocalNumberDecimalPart - s32_LocalNumberIntPart; 
	}while(f64_LocalNumberDecimalPart2 != 0.0);
	
	 while(s32_LocalNumberIntPart != 0)
	 {
		 u8_LocalAraay2[s8_LocalCounter2] = s32_LocalNumberIntPart % 10;  //u8_LocalArray[0] = 4
		 s8_LocalCounter2++;                                          //make s8_LocalCounter = 1
		 s32_LocalNumberIntPart = s32_LocalNumberIntPart / 10;             //u8_LocalArray = 12 and so on
	 }                                                           //after loop: s8_LocalCounter = 4 -> u8_LocalArray[4] = garbage
	 s8_LocalCounter2--;                                          //make s8_LocalCounter = 3 -> u8_LocalArray[3] = 1
	 
	 while(s8_LocalCounter2 >= 0)
	 {
		 H_LcdWriteCharacter(u8_LocalAraay2[s8_LocalCounter2]+'0'); //ASCII code of '0' = 48 -> 1+48=50 which is the ASCII code of '1'
		 s8_LocalCounter2--;                                       //make s8_LocalCounter = 2 and so on
	 }
	
	
 }*/
	
	if(s32_LocalNumberCopy == 0)
	{
		H_LcdWriteCharacter('0');
	}
	
	else if(s32_LocalNumberCopy < 0)
	{
		H_LcdWriteCharacter('-');
		s32_LocalNumberCopy = s32_LocalNumberCopy * (-1);
	}
	
	while(s32_LocalNumberCopy != 0)                             // 124 for example
	{
	u8_LocalAraay[s8_LocalCounter] = s32_LocalNumberCopy % 10;  //u8_LocalArray[0] = 4
	s8_LocalCounter++;                                          //make s8_LocalCounter = 1
	s32_LocalNumberCopy = s32_LocalNumberCopy / 10;             //u8_LocalArray = 12 and so on
	}                                                           //after loop: s8_LocalCounter = 4 -> u8_LocalArray[4] = garbage 
	s8_LocalCounter--;                                          //make s8_LocalCounter = 3 -> u8_LocalArray[3] = 1
	
	while(s8_LocalCounter >= 0)
	{
		H_LcdWriteCharacter(u8_LocalAraay[s8_LocalCounter]+'0'); //ASCII code of '0' = 48 -> 1+48=50 which is the ASCII code of '1' 
		s8_LocalCounter--;                                       //make s8_LocalCounter = 2 and so on
	}
 
}

void H_LcdClear(void)
{
	H_LcdWriteCommand(0x01); //0x01 is a stored command to clear LCD
}

void H_LcdGoTo(u8 u8_LocalRow,u8 u8_LocalCol)
{
	u8 arr[2] = {0x80,0xC0};
		H_LcdWriteCommand(arr[u8_LocalRow]+u8_LocalCol);
}