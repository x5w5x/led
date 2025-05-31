
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"
#include "LCD1602.h"
#include "DS1302.h"
#include"Buzzer.h"
#include "AT24C02.h"
#include "key.h"
#include"DS18B20.h"
#include"OneWire.h"

void delayms(unsigned int t)
{
  while(t--);
}
unsigned char T,c;

void main()
{  
Timer0_Init();
LCD_Init();
T=0;

P2_1=0;
P2_2=1;
    
while(1)
{
  if(P3_1==0)
  {
    delayms(10);
    if(P3_1==0)
    {
      while(!P3_1);
      T+=5;
      if(T>100)
      {
        T=0;
      }
    }
  }
  LCD_ShowNum(1,1,T,2);
     
//  P2_0=0;
//   delayms(T);
//  P2_0=1;
//   delayms(100-T);
  
  
      
  }     
     
  
}

void Timer0_Routine() interrupt 1
{
  TH0=(65535-100)/256; //设置定时器初值 100us 10次1ms 
  TL0=(65535-100)%256;
  c++;
  c%=100;
  if(c<T){
    P2_0=0;
  }
  else{
    P2_0=1;
  }

}