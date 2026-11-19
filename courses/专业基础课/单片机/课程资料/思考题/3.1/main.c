#include "reg51.h"
void main()
{
TMOD=0x20;
SCON=0x70;
TH1=0xFD;//9600
TL1=0xFD;
TR1=1;
while(1)
{
SBUF=P1	;
	
while(!TI);
TI=0;	
	}
}	
	
