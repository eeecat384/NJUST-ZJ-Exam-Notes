#include "reg51.h"
#include"string.h"
char s[]=0x41;
	
void main()
{
char a,b=0;
	TMOD=0x20;
	SCON=0x40;
	TH1=0xF4;
	TL1=0xF4;
	TR1=1;
	a=strlen(s);
	for (;b<a;b++)
	{
		SBUF=s[b];
		while(!TI);
		TI=0;
	}
}