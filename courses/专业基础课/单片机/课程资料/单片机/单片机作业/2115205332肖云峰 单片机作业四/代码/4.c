#include <reg51.h>

// 延时函数
void delay(void)
{
    unsigned char i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 200; j++);
}

// 判断一个数是否为质数
unsigned char isPrime(unsigned int num)
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

void main(void)
{
    unsigned int num = 0;
    while (1)
    {
        if (isPrime(num))
        {
            // 显示质数
            unsigned int thousands = num / 1000;         // 千位
            unsigned int hundreds = (num % 1000) / 100;  // 百位
            unsigned int tens = (num % 100) / 10;        // 十位
            unsigned int ones = num % 10;                // 个位

            P2 = 0x00;
            P0 = (0x01 << thousands);  // 设置段选码为千位对应的值
            delay();

            P2 = 0x00;
            P0 = (0x01 << hundreds);  // 设置段选码为百位对应的值
            delay();

            P2 = 0x00;
            P0 = (0x01 << tens);  // 设置段选码为十位对应的值
            delay();

            P2 = 0x00;
            P0 = (0x01 << ones);  // 设置段选码为个位对应的值
            delay();
        }
        num++;
        if (num > 9999)
            num = 0;
    }
}