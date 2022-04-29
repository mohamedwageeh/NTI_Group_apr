/*
 * I2C.h
 *
 * Created: 4/24/2022 12:56:32 PM
 *  Author: user
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "I2C_CFG.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "REG.h"

void M_I2CInit(void);
void M_I2CStartCondition(void);
void M_I2CStopCondition(void);
void M_I2CRepeatedStart(void);
void M_I2CMasterSendSlaveAddressWrite(u8);
void M_I2CMasterSendSlaveAddressRead(u8);
void M_I2CMasterSendByte(u8);
u8   M_I2CMasterReadByte(void);

#define MASTER 1
#define SLAVE  2

/*_I2C_STATUS_REG_VALUES_*/
#define START_ACK                     0x08		// start has been sent
#define REP_START_ACK                 0x10		// repeated start
#define SLAVE_AD_AND_WR_ACK           0x18		// master transmit [ slave address + write request ] ACK
#define SLAVE_AD_AND_RD_ACK           0x40		// master transmit [ slave address + read  request ] ACK
#define WR_BYTE_ACK                   0x28		// master transmit data ACK
#define RD_BYTE_WITH_NACK			  0x58		// master received data with NACK
#define RD_BYTE_WITH_ACK			  0x50		// master received data with  ACK
#define SLAVE_ADD_REC_RD_REQ		  0xA8		// slave address received with write request
#define SLAVE_ADD_REC_WR_REQ          0x60		// slave address received with read  request
#define SLAVE_DATA_REC                0x80		// read  byte request received
#define SLAVE_BYTE_TRANSMITTED        0xC0		// write byte request received


#endif /* I2C_H_ */