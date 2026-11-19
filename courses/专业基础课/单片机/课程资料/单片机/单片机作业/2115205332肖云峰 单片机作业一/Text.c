#include"reg51.h"
#include"intrins.h"
sbit p10 = P1^0;
void delay_10ms()
{
	unsigned int i = 800;
	while(i--)_nop_();
}
void main(void)
{
	unsigned int j;
	while(1)
	{
		j = 105;
		p10 = 0;
		while(j--)delay_10ms();
			j = 105;
			p10 = 1;
		while(j--)delay_10ms();
	}
}