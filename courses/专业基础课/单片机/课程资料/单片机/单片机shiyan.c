#include <stdio.h>
#include <reg52.h>
#define	LED P1
void delay(unsigned int ms)
{
unsigned int t1,t2;
for(t1=0;t1<ms;++t1)
	for(t2=0;t2<110;++t2);
}
void main()
{
 while(1)
 {
 LED=0x55;
 delay(500);
 LED=0xaa;
 delay(500);
 }
}
