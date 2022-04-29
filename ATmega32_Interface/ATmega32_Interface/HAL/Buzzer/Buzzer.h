/*
 * Buzzer.h
 *
 * Created: 4/6/2022 10:56:52 AM
 *  Author: user
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO.h"
#include "Buzzer_CFG.h"

void H_BuzzerInit(void);
void H_BuzzerOn(void);
void H_BuzzerOff(void);
void H_BuzzerOnce(void);
void H_BuzzerTwice(void);
void H_BuzzerTriple(void);
void H_BuzzerLong(void);



#endif /* BUZZER_H_ */