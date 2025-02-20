//5ms delay

#include <reg51.h>

sbit A=P1^1;
void delay();

void main(){
	unsigned int i;
	for (;;) {
		A=0;
		for(i=0;i<100;i++){
			delay();
		}
		A=1;
		for(i=0;i<100;i++){
			delay();
		}
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