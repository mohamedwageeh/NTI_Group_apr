/*
 * DC_MOTOR.h
 *
 * Created: 4/18/2022 9:45:26 AM
 *  Author: user
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DC_MOTOR_CFG.h"
#include "Timer_0.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "REG.h"
#include "DIO.h"

void H_DCMotorInit(void);
void H_DCMotorSetDirection(u8);
void H_DCMotorSetSpeed(u32);
void H_DCMotorStart(void);
void H_DCMotorStop(void);

#define  CLK_W    1
#define  A_CLK_W  2

#endif /* DC_MOTOR_H_ */