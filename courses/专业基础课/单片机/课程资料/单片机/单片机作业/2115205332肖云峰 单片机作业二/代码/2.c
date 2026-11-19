#include"reg51.h"
#include"intrins.h"
void delay_10ms()
{
	unsigned int i = 800;
	while(i--)_nop_();
}
void main ()
{
	unsigned char a;
	unsigned int j;
	a=1;
	P1 = 0xff;
	do{
			P1=~a;
			j = 105;
		while(j--)delay_10ms();
		a=a<<1;
		if(a==0) a=1;
	}
	while(1);
}