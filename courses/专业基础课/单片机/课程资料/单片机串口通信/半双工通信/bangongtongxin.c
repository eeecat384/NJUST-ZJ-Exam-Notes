#include"reg51.h"
void main()
{
unsigned char a;
TMOD=0x20;
SCON=0x70;
TH1=TL1=0xFA;
TR1=1;
while(1)
{
while(!RI);
RI=0;
a=SBUF;
if(a==0x55)
{SBUF=0x41;
while(!TI)
TI=0;
}
}
}