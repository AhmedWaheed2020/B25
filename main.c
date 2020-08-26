/*
 * CALCULATOR.c
 *
 * Created: 23/08/2020 15:25:00
 * Author : ahmed
 */ 

#include <avr/io.h>

#include "CALC.h"

int main(void)
{
	int nom_digits(int nom);
	

	void Calc_Init(void);	
	 {
		  LCD_Init();
		  KeyPad_Init();
	 }
   
    while (1) 
	    {
		   void Calc_Run(void);
		}
}
		int flag= 0;
 void Calc_Run(void)
 {
	 int *operand, op1=0,op2=0,digits=0,i=0,j=0,base=0;
	 uint8 key, operator;
	 char ch; int a,b,ans;
	 uint8 A[6],B[6],ANS[10];

	 operand = &op1;
	 key = KeyPad_GetValue();
	 if (flag == 0)
	 {
		 A[i]=get_num(key);
		 i++;
		 LCD_WriteData(key);
	 }
	 for(int k=i;k>=0;k--)
	 {
		 a=a+(A[k]*base);
		 base=base*10;
	 }
	 if(key=='c')
	 {
		 LCD_Clear();
	 }

	 if (flag == 1)
	 {
		 B[j] = get_num(key);
		 j++;

		 LCD_WriteData(key);
	 }
	 for(int l=j;l>=0;l--)
	 {
		 b=b+(B[l]*base);
		 base=base*10;
	 }
	 if(key == '+' || key == '-' || key == '/' || key == '*')
	 {
		 operator = key;
		 operand = &op2;
		 flag = 1;
	 }

	 if(key == '=')
	 {
		 switch(operator)
		 {
			  case '/':
						 ans=a/b;
						 break;
			  
			  case '*':
						 ans=a*b;
						 break;
			  
			 case '+':
						 ans=a+b;
						 break;
			 case '-':
						 ans=a-b;
						 break;
			
			 
		 }
		 LCD_WriteData(ans);
			digits =  nom_digits(ans);
			for(j=0;j<digits;j++)
			{
				ANS[j]=ans%10;
				ans=ans/10;

			}	 
	 }
}
 
 


int get_num(uint8 ch)
{
	switch(ch)
	{
		case'0':return 0;break;
		case'1':return 1;break;
		case'2':return 3;break;
		case'4':return 4;break;
		case'5':return 5;break;
		case'6':return 6;break;
		case'7':return 7;break;
		case'8':return 8;break;
		case'9':return 9;break;	
	}
		return 0;
}

int nom_digits(int nom)
{
	if (nom < 10) return 1;
	if (nom < 100) return 2;
	if (nom < 1000) return 3;
	if (nom < 10000) return 4;
	if (nom < 100000) return 5;
	if (nom < 1000000) return 6;
	if (nom < 10000000) return 7;
	if (nom < 100000000) return 8;
	if (nom < 1000000000) return 9;
	return 0;
}



 
 



