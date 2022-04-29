/*
 * UART_CFG.h
 *
 * Created: 4/20/2022 10:50:11 AM
 *  Author: user
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

//CHARACTER_SIZE OPTIONS --> [ 5 , 6 , 7 , 8 , 9 ] 
#define  CHARACTER_SIZE   8

//PARITY_CHECK OPTIONS --> [ EVEN , ODD , OFF ]
#define PARITY_CHECK      EVEN

//STOP_BITS OPTIONS --> [ 1 , 2 ]
#define STOP_BITS         1

//BAUD_RATE OPTIONS --> [ 9600 , 115200 , 38400 ]
#define BAUD_RATE         9600

#endif /* UART_CFG_H_ */