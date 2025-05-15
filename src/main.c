
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
void Delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}

void UART_Init()  //4800bps@11.0592MHz
{
    SCON=0x50; //设置串口工作模式1
    PCON|= 0x80; //波特率加倍
    TMOD&=0x0F;//设置定时器1为工作方式2
    TMOD|=0x20;//设置定时器1为工作方式2
    TL1=0xf4; //设置定时器初值
    TH1=0xf4; //设置定时器重载值
    TR1=1; //启动定时器1
    ET1=0; //禁止定时器1中断
    EA=1; //使能总中断
    ES=1; //使能串口中断
}

void UART_Routine() interrupt 4
{
    if(RI==1)
    {
        P2= SBUF; //将接收到的数据传送到P2口
        UART_SendByte(SBUF); //将接收到的数据传回
        RI=0; //清除接收中断标志位
    }
    
}


unsigned char sec=0;
void main()
{
     UART_Init();
     
     while(1)
     {
        //  UART_SendByte(sec);
        //  sec++;
        //  Delay(1000);
     }
  
}




