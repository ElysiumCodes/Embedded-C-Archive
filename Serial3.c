#include <reg51.h>

unsigned char name[]=" Parking Full ";
unsigned int i;
sbit parking = P1^0;

void main(){
	TMOD = 0x20;		
	TH1 = 0xFF;		
	SCON = 0x40;
	
	ACC=PCON;
	ACC|=0x80; //masking for setting PCON.7 as 1
	PCON=ACC;
	
	while (1) {
		if (parking==1) {
			for (i=0; i<14;i++){
				TR1=1;
				SBUF=name[i];
				while(TI==0) {}
				TI=0;
			}
		}
	}
}
