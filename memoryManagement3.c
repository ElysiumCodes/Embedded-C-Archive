void main(void){
	while(1){
		unsigned char in=P1;
		switch(in){
			case 00:
				P2=0xFF;
				break;
			case 01:
				P2=0xAA;
				break;
			case 02:
				P2=0x55;
				break;
			case 03:
				P2=0x00;
				break;
		}
	}
}
