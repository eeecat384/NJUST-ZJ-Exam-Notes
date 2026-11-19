#include "reg51.h"
#include "intrins.h"

unsigned char code Tab[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

void delay_10ms()
{
	unsigned int i = 800;
	while(i--) _nop_();
}

void main(void)
{
	unsigned int i, j;
	P0 = 0xC0;  
	P2 = 0xC0;  
	while (1)
	{
		for (i = 0; i < 100; i = i + 2)
		{
			P0 = Tab[i / 10];  
			P2 = Tab[i % 10];  
			j = 105;
			while (j--)
				delay_10ms();			
		}
	}
}