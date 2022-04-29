/*
 * ServoMotor.h
 *
 * Created: 4/17/2022 12:45:13 PM
 *  Author: user
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "ServoMotor_CFG.h"
#include "Timer_1.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "REG.h"

void H_ServoMotorInit(void);
void H_ServoMotorSetAngle(u16);
void H_ServoMotorStart(void);
void H_ServoMotorStop(void);



#endif /* SERVOMOTOR_H_ */