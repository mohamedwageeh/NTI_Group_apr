/*
 * StepperMotor.h
 *
 * Created: 4/19/2022 9:45:46 AM
 *  Author: user
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "StepperMotor_CFG.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "DIO.h"

void H_StepperMotorInit(void);
void H_StepperMotorRotate(u32);



#endif /* STEPPERMOTOR_H_ */