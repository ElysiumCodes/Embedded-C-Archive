//5ms delay

#include <reg51.h>

sbit A=P0^1;
void delay();

void main(){
	for (;;) {
		A=0;
		delay();
		A=1;
		delay();
	}
}

void delay(){
	TMOD=0x02;
	TH0=0xCD;
	TR0=1;
	while (TF0==0);
	TF0=0;
	TR0=0;
}
