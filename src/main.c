
#include <REGX52.H>

#include"Timer.h"

// void Timer0_Init()
// {
//     TMOD &=0xf0; //���ö�ʱ��0Ϊģʽ1
//     TMOD |=0x01; 
//     TH0=(65535-925)/256; //���ö�ʱ����ֵ
//     TL0=(65535-925)%256; 
//     ET0=1; //����ʱ��0�ж�
//     EA=1; //�������ж�
//     TR0=1; //������ʱ��0
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