
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
void delayms(unsigned int t)
{
  while(t--);
}
unsigned char T,c;
unsigned int ADvalue;
void main()
{  
LCD_Init();
T=0;
LCD_ShowString(1,1,"ADJ NTC RG");
    
while(1)
{
 ADvalue=XPT2046_Read_AD(XPT2046_XP_8);
LCD_ShowNum(2,1,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_YP_8);
LCD_ShowNum(2,5,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_VBAT_12);
LCD_ShowNum(2,9,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_AUX_12);
LCD_ShowNum(2,13,ADvalue,4);
    
     

  
      
  }     
     
  
}

