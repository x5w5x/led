
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
void Delayms(unsigned int t) //—” ±1ms
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}

unsigned char dat=1;
unsigned char KeyNum;
unsigned char KeyValue=0;

void main()
{  

  LCD_Init();
  LCD_ShowString(1,1,"hello world");
  dat=OneWire_Init();
  LCD_ShowString(2,1,"dat=");
  LCD_ShowNum(2,5,dat,3);
   

 
    
     while(1)
     {
      

 
  
  
      
  }     
     
  
}

