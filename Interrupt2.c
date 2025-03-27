#include <reg51.h>

unsigned char waveType = 0;

void delay(unsigned char t) {
    unsigned char i, j;
    for (i = 0; i < t; i++) {
        for (j = 0; j < 100; j++); 
    }
}


void generateTriangle() {
    static unsigned char value = 0;
    static bit increasing = 1; 

    P2 = value; 

    if (increasing) {
        value++; 
        if (value == 255) { 
            increasing = 0; 
        }
    } else {
        value--; 
        if (value == 0) { 
            increasing = 1;
        }
    }
}


void generateSquare() {
    P2 = ~P2;
		delay(1000);
}


void IR0(void) interrupt 0 {
    waveType = 0; 
}


void IR1(void) interrupt 2 {
    waveType = 1; 
}


void Timer0_ISR(void) interrupt 1 {
    if (waveType == 0) {
        generateTriangle();
    } else {
        generateSquare();
    }
}

void main() {

    IE = 0x87;  


    TMOD = 0x01; 
    TH0 = 0xFC;  
    TL0 = 0x66;  
    TR0 = 1;    
    ET0 = 1;    

    while (1) {
        
    }
}
