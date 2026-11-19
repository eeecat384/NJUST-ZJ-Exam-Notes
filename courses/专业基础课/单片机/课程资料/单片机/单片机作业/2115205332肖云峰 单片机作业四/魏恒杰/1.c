#include <reg51.h>

bit isPrime(unsigned int num)
{
	unsigned int i;
	if (num < 2)
		return 0;
	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void delay(void)
{
	unsigned int i = 800;
	while(i--)_nop_();
}

void main(void)
{
	unsigned int number;
	unsigned char digit1, digit2, digit3, digit4;

	TMOD = 0x01;   // ?????T0???1
	TH0 = 0xFC;    // ???????
	TL0 = 0x18;

	while (1)
	{
		for (number = 0; number <= 9999; number++)
		{
			if (isPrime(number))
			{
				digit1 = number / 1000;         // ??
				digit2 = (number / 100) % 10;   // ??
				digit3 = (number / 10) % 10;    // ??
				digit4 = number % 10;           // ??

				P2 = 0x01; // ????????
				P0 = digit1; // ???????
				delay();

				P2 = 0x02; // ????????
				P0 = digit2;
				delay();

				P2 = 0x04; // ????????
				P0 = digit3;
				delay();

				P2 = 0x08; // ????????
				P0 = digit4;
				delay();
			}
		}
	}
}