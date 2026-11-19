#include"reg51.h"
unsigned char b;
void main()
{
TMOD=0x20;
SCON=0x70;
TH1=TL1=0xFD;
TR1=1;
EA=1;
ES=1;
while(1)
P1=b;
}
void seri_srv() interrupt 4
{
b=SBUF;
RI=0;
}
