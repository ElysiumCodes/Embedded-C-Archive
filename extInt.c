#include <reg51.h>
 
sbit led = P2^4; 

void DELAY_ms(unsigned int ms);
 
void external_interrupt_1() interrupt 2 {
    DELAY_ms(50);
    led=~led;
}
 
void main() {
    P2 = 0x00;
 
    EA = 1;
    EX1 = 1;
    TCON |= 0x04;
 
    while (1) {C
        DELAY_ms(500);
    }
}
 
void DELAY_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1275; j++);
    }
}
