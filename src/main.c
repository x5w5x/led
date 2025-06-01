
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
#include"XPT2046.h"
#include "Int.h"
#include"Delay.h"


unsigned int T,c;
unsigned int ADvalue;

void main()
{  
Timer0_InitCounter();
LCD_Init();
T=0;
Timer0_SetCounter(0);
Timer0_Run(1);
Delay(10);
T=Timer0_GetCounter();



    
while(1)
{
  LCD_ShowNum(1,1,T,5);
     

  
  
      
  }     
     
  
}

