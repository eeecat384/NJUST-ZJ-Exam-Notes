11:13#include <reg51.h>
#include <intrins.h>
#include <absacc.h>

#define PIN0 XBYTE[0X7FF8]
typedef unsigned char byte;
typedef unsigned int word;
bit Timer_flag;
byte Timer_count;
byte k2,l,i;
float result=0;
float result_reg;
int a,b,c,d,e,r;
unsigned char code tab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x73,0x3e,0x31,0x6e,0xff};

void delay(word i)
{  word j=0;
   while (j<i)
   j++;
}

void AD_Covert(void)
{
  PIN0=0xFF;
  while(INT0);
  while(!INT0);
  result_reg=PIN0;
  result=result_reg*5/255;
}

void Data_change(void)
{
   r=result*100;
   a=r/100;
   b=(r-a*100)/10;
   c=(r-a*100)%10;
 }
 
 void Display(int ax,bx,cx)
 {
        P1=0x00;
        P2=0xf4;
        P1=tab[cx];
        delay(100);
        P1=0x00;
        P2=0xf2;
        P1=tab[bx];
        delay(100);
        P1=0x00;
        P2=0xf1;
        P1=tab[ax]+0x80;
        delay(100);
        P1=0x00;
}

void main(void)
{
       TMOD=0x01;
       TH0=0xb0;
       TL0=0x3c;
       TR0=1;
       ET0=1;
       EA=1;
     while(1)
     {
        if(Timer_flag==1)
       {
           Timer_flag=0;
           AD_Covert();
           Data_change();
           Display(a,b,c);
       }
     }
}

void timer0_int(void) interrupt 1 using 0
{
   TH0=0xb0;
   TL0=0x3c;
   Timer_count++;
   if(Timer_count==2)
   {
     Timer_count=0;
     Timer_flag=1;
  }
}
	
	




