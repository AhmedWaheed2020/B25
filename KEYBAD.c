/*
 * KEYBAD.c
 *
 * Created: 11/08/2020 6:23:16 ?
 *  Author: Ahmed
 */ 


#define F_CPU 16000000
#include "util/delay.h"

#include "KEYPAD.h"

#define COL_INIT    0
#define COL_FINAL   3

#define ROW_INIT    4
#define ROW_FINAL   7


const uint8 KeyPad_Values[4][4]    =   { {'1' , '2' , '3' , '/'},
										 {'4' , '5' , '6' , '*'},
										 {'7' , '8' , '9' , '-'},
										 {'C' , '0' , '=' , '+'} };







void KeyPad_Init(void)
{
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUMN_0 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUMN_1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUMN_2 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUMN_3 , DIO_PIN_OUTPUT);
	
	
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_0 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_1 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_2 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_3 , DIO_PIN_INPUT);
	
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_0);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_1);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_2);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_ROW_3);

	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN_0 ,  DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN_1 ,  DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN_2 ,  DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN_3 ,  DIO_PIN_HIGH);

}





uint8 KeyPad_GetValue(void)
{
	
	uint8 LOC_Column  = 0;
	uint8 LOC_Row     = 0;
	uint8 Value       = 0;
	uint8 Temp        = 0;
	
	for( LOC_Column =  COL_INIT ;  LOC_Column  <=  COL_FINAL ;  LOC_Column ++  )
	{
		DIO_SetPinValue(KEYPAD_PORT, LOC_Column ,  DIO_PIN_LOW);

		
		for( LOC_Row = ROW_INIT  ; LOC_Row <= ROW_FINAL   ; LOC_Row ++ )
		{
			
			DIO_ReadPin(KEYPAD_PORT, LOC_Row , &Temp);
			
			if(!Temp)
			{
				Value = KeyPad_Values[LOC_Row - ROW_INIT][LOC_Column - COL_INIT];
				
				while(!Temp)
				{
					DIO_ReadPin(KEYPAD_PORT, LOC_Row , &Temp);
				}
				
				_delay_ms(10);
				
			}
			
		}
		DIO_SetPinValue(KEYPAD_PORT, LOC_Column ,  DIO_PIN_HIGH);
	}
	
	return Value ;
	
	
}
