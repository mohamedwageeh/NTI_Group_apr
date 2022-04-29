/*
 * UART.h
 *
 * Created: 4/20/2022 10:49:35 AM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_CFG.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "REG.h"

void M_UARTInit(void);
void M_UARTSend(u8);
u8   M_UARTReceive(void);

#define OFF    0
#define ODD    1
#define EVEN   2


#endif /* UART_H_ */