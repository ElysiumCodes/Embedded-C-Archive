#include <reg51.h>


unsigned char name[]={'S','H','A','K','T', 'I', ' '};
unsigned int i;

void main(){
	TMOD = 0x20;		
	TH1 = 0xFA;		
	SCON = 0x40;		
	
	while (1) {
		for (i=0; i<7;i++){
			TR1=1;
			SBUF=name[i];
			while(TI==0) {}
			TI=0;
		}
	}
}
