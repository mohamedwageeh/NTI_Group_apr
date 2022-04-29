/*
 * PushButton.c
 *
 * Created: 4/5/2022 8:36:08 PM
 *  Author: user
 */ 

#include "PushButton.h"

void H_PushButtonInit(u8 u8_Local_PB)
{
	switch(u8_Local_PB)
	{
	    case PB_1:
	    M_PinMode(PushButtonPin1,INPUT);
	    M_PinPullUp(PushButtonPin1,ENABLE);
	    break;
        case PB_2:
        M_PinMode(PushButtonPin2,INPUT);
        M_PinPullUp(PushButtonPin2,ENABLE);
        break;
	    case PB_3:
	    M_PinMode(PushButtonPin3,INPUT);
	    M_PinPullUp(PushButtonPin3,ENABLE);
	    break;
	    case PB_4:
	    M_PinMode(PushButtonPin4,INPUT);
	    M_PinPullUp(PushButtonPin4,ENABLE);
	    break;
	    default:
        break;
	}
}

u8 H_PushButtonRead1(u8 u8_Local_PB)
{
	u8 Reading = 0;
	
	switch(u8_Local_PB)
	{
		case PB_1:
		Reading = M_PinRead(PushButtonPin1);
		break;
		case PB_2:
		Reading = M_PinRead(PushButtonPin2);
		break;
		case PB_3:
		Reading = M_PinRead(PushButtonPin3);
		break;
		case PB_4:
		Reading = M_PinRead(PushButtonPin4);
		break;
		default:
		break;
	}
	return Reading;
}

