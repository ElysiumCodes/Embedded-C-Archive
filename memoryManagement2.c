#include<reg51.h>

sbit input= P1^0;
sbit output= P2^0;
bit membit;
void main(void){
	while(1){
		membit=~input;
		output=membit;
	}
}
