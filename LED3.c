#include <reg51.h>

sbit A=P1^1;
void delay();

void main(){
	for (;;) {
		unsigned int i;
		A=0;
		for (i=0; i<100; i++){
			delay();
		}
		A=1;
		for (i=0; i<100; i++){
			delay();
		}
	}
}

void delay(){
	TMOD=0x01;
	TH0=0xEC;
	TL0=0x77;
	TR0=1;
	while (TF0==0);
	TF0=0;
	TR0=0;
}
