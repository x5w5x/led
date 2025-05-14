
#include <REGX52.H>

#include"Timer.h"

// void Timer0_Init()
// {
//     TMOD &=0xf0; //设置定时器0为模式1
//     TMOD |=0x01; 
//     TH0=(65535-925)/256; //设置定时器初值
//     TL0=(65535-925)%256; 
//     ET0=1; //允许定时器0中断
//     EA=1; //允许总中断
//     TR0=1; //启动定时器0
// }

 unsigned char count=0;

void main()
{
  Timer0_Init();
    P2_1=0;
    while (1)
    {
        
    }
}


void Timer0() interrupt 1
{
    TH0=(65535-50000)/256;
    TL0=(65535-50000)%256;
    count++;
    if (count>20)
    P2_1=~P2_1,count=0;
}