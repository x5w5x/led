
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
   LCD_Init();//��ʼ��LCD
   DS1302_Init();//��ʼ��DS1302
   LCD_ShowString(1,1,"  -  -  ");

   LCD_ShowString(2,1,"  :  :  ");;
   DS1302_SetTime();
    
    
     while(1)
     {
      DS1302_ReadTime();//�������
      
      DS1302_GetTime(); //�ṹ�����


      LCD_ShowNum(1,1,time.Year,2);
      LCD_ShowNum(1,4,time.Month,2);
      LCD_ShowNum(1,7,time.Day,2);
      LCD_ShowNum(2,1,time.Hour,2);
      LCD_ShowNum(2,4,time.Minute,2);
      LCD_ShowNum(2,7,time.Second,2);


    

     
       
     }
  
}
