
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"
#include "LCD1602.h"
#include "DS1302.h"
#include"Buzzer.h"
#include "AT24C02.h"
void Delayms(unsigned int t) //—” ±1ms
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}

unsigned char dat;
void main()
{  

  LCD_Init();
  LCD_ShowString(1,1,"hello world");
   AT24C02_Write(1,147);
  Delayms(6);
  dat=AT24C02_Read(1);
  LCD_ShowNum(2,1,dat,4);
 
    
     while(1)
     {
      
   
      
  }     
     
  
}


