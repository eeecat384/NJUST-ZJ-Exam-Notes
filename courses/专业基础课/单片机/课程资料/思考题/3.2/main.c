#include "reg51.h"
void main()
{
unsigned  char a;
TMOD=0x20;
SCON=0x70;
TH1=0xFD;//9600
TL1=0xFD;
TR1=1;
while(1)
{
	while(!RI);
	RI=0;
	a=SBUF;
P1=a;

	}
}	
	

