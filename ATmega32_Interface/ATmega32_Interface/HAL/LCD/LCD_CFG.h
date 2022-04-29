/*
 * LCD_CFG.h
 *
 * Created: 4/6/2022 2:06:23 PM
 *  Author: user
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

// LCD_MODE options -> [ _8_BIT_MODE , _4_BIT_MODE ]
#define LCD_MODE       _4_BIT_MODE

#define  LCD_Data_Port    PORTA

#define  LCD_Data_Pin_0  PA0
#define  LCD_Data_Pin_1  PA1
#define  LCD_Data_Pin_2  PA2
#define  LCD_Data_Pin_3  PA3
#define  LCD_Data_Pin_4  PA4
#define  LCD_Data_Pin_5  PA5
#define  LCD_Data_Pin_6  PA6
#define  LCD_Data_Pin_7  PA7

#define  LCD_RS_Pin      PB1
#define  LCD_RW_Pin      PB2
#define  LCD_EN_Pin      PB3

#endif /* LCD_CFG_H_ */