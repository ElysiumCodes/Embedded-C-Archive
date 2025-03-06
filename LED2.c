// 100 Hz waveform

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
