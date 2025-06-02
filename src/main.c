
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
#include"IR.h"

unsigned char Address,Command;

void main()
{  

LCD_Init();
IR_Init();



    
while(1)
{
  if(IR_GetDataFlag()){
    Address=IR_GetAddress();
    Command=IR_GetCommand();
    LCD_ShowHexNum(2,1,Address,4);
    LCD_ShowHexNum(2,6,Command,4);



  }
     

  
  
      
  }     
     
  
}

