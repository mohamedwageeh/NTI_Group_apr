/*
 * DIO.c
 *
 * Created: 4/5/2022 4:16:20 PM
 *  Author: user
 */ 


#include "DIO.h"

void M_PinMode(u8 x,u8 State)
{
	u8 Pin  = x % 10;
	u8 Port = x / 10;
	
	switch(State)
	{
		case INPUT:
		
			switch(Port)
			{
				case GROUP_A:
				ClrBit(DDRA,Pin);
				break;
				case GROUP_B:
				ClrBit(DDRB,Pin);
				break;
				case GROUP_C:
				ClrBit(DDRC,Pin);
				break;
				case GROUP_D:
				ClrBit(SREG,Pin);
				break;
				default:
				break;
			}
		
		break;
		case OUTPUT:
		
			switch(Port)
			{
				case GROUP_A:
				SetBit(DDRA,Pin);
				break;
				case GROUP_B:
				SetBit(DDRB,Pin);
				break;
				case GROUP_C:
				SetBit(DDRC,Pin);
				break;
				case GROUP_D:
				SetBit(SREG,Pin);
				break;
				default:
				break;
			}
		break;
		
		default:
		break;
	}
}

void M_PinWrite(u8 x,u8 State)
{
	u8 Pin  = x % 10;
	u8 Port = x / 10;
	
	switch(State)
	{
	
		
		case LOW:
		
			switch(Port)
			{
				case GROUP_A:
				ClrBit(PORTA,Pin);
				break;
				case GROUP_B:
				ClrBit(PORTB,Pin);
				break;
				case GROUP_C:
				ClrBit(PORTC,Pin);
				break;
				case GROUP_D:
				ClrBit(PORTD,Pin);
				break;
				default:
				break;
			}
			break;
			case HIGH:
			
			switch(Port)
			{
				case GROUP_A:
				SetBit(PORTA,Pin);
				break;
				case GROUP_B:
				SetBit(PORTB,Pin);
				break;
				case GROUP_C:
				SetBit(PORTC,Pin);
				break;
				case GROUP_D:
				SetBit(PORTD,Pin);
				break;
				default:
				break;
			}
			break;
		default:
		break;
	}
}

void M_PinTog(u8 x)
{
	u8 Pin  = x % 10;
	u8 Port = x / 10;
	
	switch(Port)
	{
		case GROUP_A:
		TogBit(PORTA,Pin);
		break;
		case GROUP_B:
		TogBit(PORTB,Pin);
		break;
		case GROUP_C:
		TogBit(PORTC,Pin);
		break;
		case GROUP_D:
		TogBit(PORTD,Pin);
		break;
		default:
		break;
	}
}

u8 M_PinRead(u8 x)
{
	u8 Pin  = x % 10;
	u8 Port = x / 10;
	u8 Reading = 0;
	
	switch(Port)
	{
		case  GROUP_A:
		Reading = GetBit(PINA,Pin);
		break;
		case  GROUP_B:
		Reading = GetBit(PINB,Pin);
		break;
		case  GROUP_C:
		Reading = GetBit(PINC,Pin);
		break;
		case  GROUP_D:
		Reading = GetBit(PIND,Pin);
		break;
		default:
		break;
	}
	return Reading;
}

void M_PinPullUp(u8 x,u8 State)
{
	u8 Pin  = x % 10;
	u8 Port = x / 10;
	
	switch(State)
	{
		case DISABLE:
		
		switch(Port)
		{
			case GROUP_A:
			ClrBit(PORTA,Pin);
			break;
			case GROUP_B:
			ClrBit(PORTB,Pin);
			break;
			case GROUP_C:
			ClrBit(PORTC,Pin);
			break;
			case GROUP_D:
			ClrBit(PORTD,Pin);
			break;
			default:
			break;
		}
		
		break;
		case ENABLE:
		
		switch(Port)
		{
			case GROUP_A:
			SetBit(PORTA,Pin);
			break;
			case GROUP_B:
			SetBit(PORTB,Pin);
			break;
			case GROUP_C:
			SetBit(PORTC,Pin);
			break;
			case GROUP_D:
			SetBit(PORTD,Pin);
			break;
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}