/*
 * SPI.h
 *
 * Created: 4/21/2022 10:27:23 AM
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_CFG.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "DIO.h"

void M_SPIInit(void);
u8   M_SPITransceiving(u8);

#define  MASTER 1
#define  SLAVE  2

#endif /* SPI_H_ */