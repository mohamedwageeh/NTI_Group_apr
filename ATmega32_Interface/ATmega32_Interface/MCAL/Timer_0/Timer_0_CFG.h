/*
 * Timer_0_CFG.h
 *
 * Created: 4/13/2022 10:19:38 AM
 *  Author: user
 */ 


#ifndef TIMER_0_CFG_H_
#define TIMER_0_CFG_H_

//TIMER0_MODE OPTIONS -> [ NORMAL_MODE , CTC_MODE]
#define TIMER0_MODE   CTC_MODE

//select crystal oscillator frequency in MHZ
#define CRYSTAL_FREQ  16 

//Select prescaler division factor -> options : [ 256 , 1024 ]
#define PRESCALER_DIV_FAC  1024

//PWM0MODE OPTIONS -> [ FAST_PWM_MODE , PHASE_CORRECT_PWM_MODE ]
#define PWM0MODE  PHASE_CORRECT_PWM_MODE

#endif /* TIMER_0_CFG_H_ */