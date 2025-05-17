
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
// #define DS1302_YEAR 0x8c //年

void main()
{  
   LCD_Init();//初始化LCD
   DS1302_Init();//初始化DS1302
   LCD_ShowString(1,1,"  -  -  ");
//    LCD_ShowString(2,1,"  -  -  ");
   LCD_ShowString(2,1,"  :  :  ");
//    DS1302_WriteByte(0x8e,0x00);
//    DS1302_WriteByte(0x80,0x11);
//    Second=DS1302_ReadByte(0x81);
//  LCD_ShowNum(2,1,Second,3);
// LCD_ShowNum(2,1,64,3);
   DS1302_SetTime();
    
    
     while(1)
     {
      DS1302_ReadTime();
      DS1302_GetTime();
     //  LCD_ShowNum(1,1,DS1302_Time[0],2);
      LCD_ShowNum(1,1,Timestruct.year,2);
      LCD_ShowNum(1,4,DS1302_Time[1],2);
      LCD_ShowNum(1,7,DS1302_Time[2],2);
      LCD_ShowNum(2,1,DS1302_Time[3],2);
      LCD_ShowNum(2,4,DS1302_Time[4],2);
      LCD_ShowNum(2,7,DS1302_Time[5],2);
      

    

     
       
     }
  
}
