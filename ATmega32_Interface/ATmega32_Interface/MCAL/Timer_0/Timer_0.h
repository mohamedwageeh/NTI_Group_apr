/*
 * Timer_0.h
 *
 * Created: 4/13/2022 10:19:13 AM
 *  Author: user
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_

#include "Timer_0_CFG.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "REG.h"

void M_Timer0Init(void);
void M_Timer0SetTime(u32);
void M_Timer0Start(void);
void M_Timer0Stop(void);
void M_Timer0_SetCallBack(void(*)(void));

void M_PWM0Init(void);
void M_PWM0SetDutyCycle(u8);
void M_PWM0Start(void);
void M_PWM0Stop(void);

#define NORMAL_MODE                1
#define CTC_MODE                   2
#define FAST_PWM_MODE              3
#define PHASE_CORRECT_PWM_MODE     2


#endif /* TIMER_0_H_ */