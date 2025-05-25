
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"
#include "LCD1602.h"
#include "DS1302.h"
#include"Buzzer.h"
#include "AT24C02.h"
#include "key.h"
void Delayms(unsigned int t) //—” ±1ms
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}

unsigned char dat;
unsigned char KeyNum;
unsigned char KeyValue=0;
void main()
{  

  LCD_Init();
  LCD_ShowString(1,1,"hello world");
  Timer0_Init();
   

 
    
     while(1)
     {
      
   KeyValue=key();
   if(KeyValue!=0)
  //  LCD_ShowNum(2,1,KeyValue,2);
  
  
      
  }     
     
  
}

void Time0_Routine(void) interrupt 1
{
    static unsigned int t0;
    TL0=0x18;
    TH0=0xFC;
    t0++;
    if(t0==20){
        t0=0;
        Key_loop();
    }
}
