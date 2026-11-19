#include<reg51.h>
#include<intrins.h>
sbit p10=P1^0;
 
int	i; 
void delay(i)
{
  unsigned int k;
	while(k--) _nop_();
}
main(void)
{
  unsigned int j;
	while(1)
	{
	  j=200;
		p10=0;
	  while(j--) delay(200);
   	j=200;
		p10=1;
		while(j--) delay(200);
  }
}
		
		
	