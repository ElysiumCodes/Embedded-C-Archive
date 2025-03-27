#include <reg51.h>

unsigned char value;

void main(){
	TMOD = 0x20;		
	TH1 = 0xFD;		
	SCON = 0x50;
	TR1=1;
	while (1){
		while(RI==0);       
    value=SBUF;     
    P1=value;
    RI=0;      
	}
	
}
