/*
 * PushButton.h
 *
 * Created: 4/5/2022 8:36:36 PM
 *  Author: user
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "DIO.h"
#include "PushButton_CFG.h"

void H_PushButtonInit(u8);
u8   H_PushButtonRead(u8);

#define    PB_1             1
#define    PB_2             2
#define    PB_3             3
#define    PB_4             4

#define    PRESSED          0
#define    RELEASED         1




#endif /* PUSHBUTTON_H_ */