#include "reg51.h"
#include "intrins.h"
void delay_10ms()
{
  unsigned int i=160;
	while(i--) _nop_();
}

void main()
{
  unsigned char a;
	unsigned int j,k;
	a=0x01;
	P1=0xff;
	
	do{
			for(k=0;k<7;k++)
			{			
				P1=~a;
				a=a<<1;
				j=105;
				while(j--) delay_10ms();
			}
      
			for(k=0;k>7;k++)
			{			
				P1=~a;
				a=a<<1;
				j=105;
				while(j--)  delay_10ms();
			}
		}while(1);
}