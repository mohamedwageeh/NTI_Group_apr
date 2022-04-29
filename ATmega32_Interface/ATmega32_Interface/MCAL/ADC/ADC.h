/*
 * ADC.h
 *
 * Created: 4/12/2022 10:25:37 AM
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_CFG.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "REG.h"


void M_ADCInit(void);
u16  M_ADCRead(void);  //u16 because max. return value is (2^10) or 1024

#define AVCC      1
#define AREF_PIN  2
#define _2_VOLT   3

#define RIGHT     1
#define LIFT      2

#define _64       1
#define _128      2

#define ON        1
#define OFF       2


#endif /* ADC_H_ */