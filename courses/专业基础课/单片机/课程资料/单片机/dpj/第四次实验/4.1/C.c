#include<reg51.h>
char dis_dat[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char i,minute,second,minute0,minute1,second0,second1;
void T1_srv(void)interrupt 3
{
	TH1=0x3c;
	TL1=0xb0;
	i--;
	if(i==0)
	{
		i=20;
		second++;
		if(second==60)
		{
			second=0;
			minute++;
			if(minute==60)
			{
				minute=0;
				
				
			}
		}
	}
}
void delay()
{int j=500;
	while(j--);
}
void int0_srv(void)interrupt 0
{
	minute++;
	if(minute==60)
	{minute=0;}
}
void int1_srv(void)interrupt 2
{
	minute=0;
	second=0;
}
void main()
{
	i=20;
	minute=0;
	second=0;
	TMOD=0x10;
	TH1=0x3c;
	TL1=0xb0;
	ET1=1;
	TCON=0x05;
	EX0=1;
	EX1=1;
	EA=1;
	TR1=1;
	while(1)
	{
		minute1=minute/10;
		minute0=minute%10;
		second1=second/10;
		second0=second%10;
		P2=0x80;
		P0=dis_dat[second0];
		delay();
		P2=0x40;
		P0=dis_dat[second1];
		delay();
		P2=0x20;
		P0=dis_dat[minute0];
		delay();
		P2=0x10;
		P0=dis_dat[minute1];
		delay();
	}
}