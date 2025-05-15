
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
    SCON=0x50; //���ô��ڹ���ģʽ1
    PCON|= 0x80; //�����ʼӱ�
    TMOD&=0x0F;//���ö�ʱ��1Ϊ������ʽ2
    TMOD|=0x20;//���ö�ʱ��1Ϊ������ʽ2
    TL1=0xf4; //���ö�ʱ����ֵ
    TH1=0xf4; //���ö�ʱ������ֵ
    TR1=1; //������ʱ��1
    ET1=0; //��ֹ��ʱ��1�ж�
    EA=1; //ʹ�����ж�
    ES=1; //ʹ�ܴ����ж�
}

void UART_Routine() interrupt 4
{
    if(RI==1)
    {
        P2= SBUF; //�����յ������ݴ��͵�P2��
        UART_SendByte(SBUF); //�����յ������ݴ���
        RI=0; //��������жϱ�־λ
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




