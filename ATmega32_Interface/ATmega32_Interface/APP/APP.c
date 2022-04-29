	/*
 * APP.c
 *
 * Created: 4/21/2022 4:34:20 PM
 *  Author: user
 */ 

/*#include "APP.h"

u8 QuestionNumber = 1;

void Asking(void)
{
	if(H_PushButtonRead(PB_1) == PRESSED || H_PushButtonRead(PB_2) == PRESSED || H_PushButtonRead(PB_3) == PRESSED || H_PushButtonRead(PB_4) == PRESSED)
	{
		Check_Answer(QuestionNumber);
	}
}

void Check_Answer(u8 QuestionNumber)
{
	switch(QuestionNumber)
	{
		case 1:
		if(H_PushButtonRead(PB_1) == PRESSED)
		Wrong_Answer();
		else if(H_PushButtonRead(PB_2) == PRESSED)
		Wrong_Answer();
		else if(H_PushButtonRead(PB_3) == PRESSED)
		Wrong_Answer();
		else if(H_PushButtonRead(PB_4) == PRESSED)
		Right_Answer();
		break;
	}
}

void Right_Answer(void)
{
	H_BuzzerOnce();
	H_LcdWriteString("GREAT");
	QuestionNumber++;
}

void Wrong_Answer(void)
{
	H_BuzzerOnce();
	H_LcdWriteString("1 MINUTE PENALTY");
	H_LcdWriteString("LOSER");
}*/