/*
 * Temp.h
 *
 * Created: 4/12/2022 2:03:47 PM
 *  Author: user
 */ 


#ifndef TEMP_H_
#define TEMP_H_

#include "Temp_CFG.h"
#include "STD.h"
#include "ADC.h"


void H_TempSensorInit(void);
u16  H_TempSensorRead(void);



#endif /* TEMP_H_ */