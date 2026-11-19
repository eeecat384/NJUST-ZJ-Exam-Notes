#include<reg51.h>
sbit p10=P1^0;
sbit p30=P3^0;

void main(void)
{
  if(p30==0)
	p10=0;
	else p10=1;
}
		
	