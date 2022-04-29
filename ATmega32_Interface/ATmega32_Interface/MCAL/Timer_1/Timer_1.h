/*
 * Timer_1.h
 *
 * Created: 4/17/2022 10:12:28 AM
 *  Author: user
 */ 


#ifndef TIMER_1_H_
#define TIMER_1_H_

#include "Timer_1_CFG.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "REG.h"

void M_PWM1Init(void);
void M_PWM1SetFrequency(u32);
void M_PWM1SetDutyCycle(f32);
void M_PWM1Start(void);
void M_PWM1Stop(void);



#endif /* TIMER_1_H_ */