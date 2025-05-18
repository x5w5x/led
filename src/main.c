
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


void main()
{  
   LCD_Init();//初始化LCD
   DS1302_Init();//初始化DS1302
   LCD_ShowString(1,1,"  -  -  ");

   LCD_ShowString(2,1,"  :  :  ");;
    DS1302_Time[0]=25;
    DS1302_Time[1]=5;
    DS1302_Time[2]=18;
    DS1302_Time[3]=10;
    DS1302_Time[4]=48;
    DS1302_Time[5]=0;
    DS1302_Time[6]=5;
   DS1302_SetTime();
   DS1302_SetDate(16);
   
    
     while(1)
     {
      // DS1302_ReadTime();//数组访问
      // LCD_ShowNum(1,1,DS1302_Time[0],2);

      DS1302_GetTime(); //结构体访问
      // LCD_ShowNum(1,1,time.Year,2);

      // LCD_ShowNum(1,1,DS1302_GetYear(),2); //函数直接访问
      LCD_ShowNum(1,1,DS1302_ReadYear(),2);
      LCD_ShowNum(1,4,DS1302_ReadMonth(),2);
      LCD_ShowNum(1,7,DS1302_ReadDate(),2);
      LCD_ShowNum(2,1,DS1302_ReadHour(),2);
      LCD_ShowNum(2,4,DS1302_ReadMinute(),2);
      LCD_ShowNum(2,7,DS1302_ReadSecond(),2);
      // LCD_ShowNum(1,4,DS1302_GetMonth(),2);
      // LCD_ShowNum(1,7,DS1302_GetDate(),2);
      // LCD_ShowNum(2,1,DS1302_GetHour(),2);
      // LCD_ShowNum(2,4,DS1302_GetMinute(),2);
      // LCD_ShowNum(2,7,DS1302_GetSecond(),2);



      // LCD_ShowNum(1,4,time.Month,2);
      // LCD_ShowNum(1,7,time.Date,2);
      // LCD_ShowNum(2,1,time.Hour,2);
      // LCD_ShowNum(2,4,time.Minute,2);
      // LCD_ShowNum(2,7,time.Second,2);


    

     
       
     }
  
}
