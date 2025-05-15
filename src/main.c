
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
void Delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}






unsigned char sec=0;
void main()
{
     UART_Init();
     
     while(1)
     {
         UART_SendByte(sec);
         sec++;
         Delay(1000);
     }
  
}




