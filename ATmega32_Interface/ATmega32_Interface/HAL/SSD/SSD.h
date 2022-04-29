/*
 * SSD.h
 *
 * Created: 4/7/2022 5:52:49 PM
 *  Author: user
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "SSD_CFG.h"
#include "DIO.h"
# define F_CPU 16000000UL
#include <util/delay.h>

void H_SsdInit(void);
void H_SsdDisplayBlink(u8);
void H_SsdDisplay(u8);
void H_SsdCountUp(u8);
void H_SsdCountDown(u8);
void H_SsdClear(void);

#define DIRECT_MODE     1
#define DECODER_MODE    2



#endif /* SSD_H_ */