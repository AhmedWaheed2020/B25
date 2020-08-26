/*
 * LCD.h
 *
 * Created: 10/08/2020 15:31:44
 *  Author: ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include  "LCD_CFG.h"
#define   F_CPU  16000000
#include  <util/delay.h>

void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteData(uint8 data);

void LCD_GoTo(uint8 row , uint8 col);

void LCD_WriteString(uint8* str);

void LCD_WriteIntg (sint32 intgr);

void LCD_Clear(void);





#endif /* LCD_H_ */