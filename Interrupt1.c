#include <reg51.h>

void IR0(void) interrupt 0 {
    ACC = P0;
    P2 = ACC;
}

void IR1(void) interrupt 2 {
    ACC = P0;
    P1 = ~ACC;
}

void serial(void) interrupt 4 {
    if (TI == 1) {
        ACC = P0; 
        SBUF = ACC;
        TI = 0;
    }
}

void main() {
    IE = 0x96;
    TMOD = 0x20;
    TH1 = -6;
    TR1 = 1;
    SCON = 0x40;	
    
    ACC = P0;
    SBUF = ACC;

    while (1) {
			
    }
}
