#include<reg51.h>


void main(void){
	unsigned char arr[5]={'1','2','3','4','5'};
	unsigned char j;
	for(j=0;j<5;j++){
		P1=arr[j];
	}
}
