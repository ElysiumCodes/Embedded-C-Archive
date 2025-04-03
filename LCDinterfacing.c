#include <reg51.h>
void LCD_CMD(unsigned char CMD);
void LCD_DATA(unsigned char DATA);
void DELAY_ms(unsigned char j);
sbit RS= P3^7; 
sbit RW= P3^6;
sbit EN= P3^5;
unsigned char name[] = {'V','I','S','N','U'};
unsigned char i;
void main()
{
	P2=0x00;					
	LCD_CMD(0x01); 		
	DELAY_ms(5);
	LCD_CMD(0x0E);		
	DELAY_ms(5);
	LCD_CMD(0x38);		
	DELAY_ms(5);
	LCD_CMD(0x80);		
	DELAY_ms(5);
	for(i=0; i<5; i++){
		LCD_DATA(name[i]);
	}
	while(1);
}

void LCD_CMD(unsigned char CMD)
{
	P2=CMD;
	RS=0;
	RW=0;
	EN=1; 
	DELAY_ms(5);
	EN=0;	
}

void LCD_DATA(unsigned char DATA)
{
	P2=DATA;
	RS=1;
	RW=0;
	EN=1;
	DELAY_ms(5);
	EN=0;	
}

void DELAY_ms(unsigned int j)
{
	unsigned int i;
	for(;j>0;j--)
	{
		for(i=250;i>0;i--);
		for(i=250;i>0;i--);
	}
}
