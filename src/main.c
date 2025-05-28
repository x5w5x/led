
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
float T=2;
void main()
{  

  LCD_Init();
  LCD_ShowString(1,1,"hello world");
 
   

 
    
     while(1)
     {
      
      DS18B20_ConvertT();
      T=DS18B20_ReadT();
      if(T<0){
        LCD_ShowString(2,1,"T=-");
        T=-T;
      }
      else{
        LCD_ShowString(2,1,"T=+");

      }
  	LCD_ShowNum(2,2,T,3);		
		LCD_ShowChar(2,5,'.');		
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
 
  
  
      
  }     
     
  
}

