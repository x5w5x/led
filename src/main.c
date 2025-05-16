
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"
#include "LCD1602.h"
#include "DS1302.h"
// void Delay(unsigned int t)
// {
//     unsigned int i,j;
    
//     for(i=0;i<t;i++)
        
//         for(j=0;j<125;j++);
// }

unsigned char Second;

void main()
{  
   LCD_Init();//初始化LCD
   DS1302_Init();//初始化DS1302
   DS1302_WriteByte(0x8e,0x00);
   DS1302_WriteByte(0x80,0x10);
   Second=DS1302_ReadByte(0x81);
    
 
    LCD_ShowNum(2,1,Second,3);
    
     while(1)
     {
      

    

     
       
     }
  
}




