/*
 * BIT_MATH.h
 *
 * Created: 4/5/2022 3:26:46 PM
 *  Author: user
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SetBit(Reg,Bit)     Reg |= 1 << Bit
#define ClrBit(Reg,Bit)     Reg &= ~(1 << Bit)
#define TogBit(Reg,Bit)     Reg ^= 1 << Bit
#define GetBit(Reg,Bit)     1 & (Reg >> Bit)


#endif /* BIT_MATH_H_ */