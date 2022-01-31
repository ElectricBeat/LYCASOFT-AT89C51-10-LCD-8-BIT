#include<reg51.h>
#include "8051_delay.h"

sbit RS = P3^0;
sbit EN = P3^1;

#define ON 1
#define OFF 0

void Lcd_Command(char cmd)
{
	P2 = cmd;
	RS = OFF;
	EN = ON;
	delay(1);
	EN = OFF;
}

void Lcd_Data(char Data)
{
	P2 = Data;
	RS = ON;
	EN = ON;
	delay(1);
	EN = OFF;
}

void Lcd_String(const unsigned char *Str)
{
	while(*Str)
	{
		Lcd_Data(*Str++);
	}	
}

void Lcd_Intialization()
{
	Lcd_Command(0x38);
	Lcd_Command(0x06);
	Lcd_Command(0x0c);
}

void main()
{
	P2=0X00;
	P3=0X00;

	Lcd_Intialization();
	
	while(1)
	{
		Lcd_Command(0x80);
		Lcd_String("LYCO SOFT");
	}
}