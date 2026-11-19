#include"reg51.h"
void main()
{
TMOD=0x20;
SCON=0x50;
TH1=TL1=0xFD;
TR1=1;
while(1)
{
SBUF='L';
while(!TI);
TI=0;
}
}