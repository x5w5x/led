
#include <REGX52.H>

#include"Timer.h"



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