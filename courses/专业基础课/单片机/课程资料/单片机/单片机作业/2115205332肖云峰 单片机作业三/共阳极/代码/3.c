#include "reg51.h"
#include "intrins.h"
unsigned char code Tab[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void delay_10ms()
{
	unsigned int i = 800;
	while(i--)_nop_();
}
void main (void)
{
	unsigned int i,j;
	P0 = 0x80;
	P2 = 0x80;
	while(1)
	{
		for(i=0;i<100;i=i+2)
		{
			P0=Tab[i/10];
			P2=Tab[i%10];
			j=105;
			while(j--)delay_10ms();
		}
	}
}