
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"
#include "LCD1602.h"
#include "DS1302.h"
#include"Buzzer.h"

void Delayms(unsigned int t) //—” ±1ms
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}


void main()
{  
   

    
     while(1)
     {
      
      if (P3_1==0){
      Delayms(10);
        if (P3_1==0){
         Buzzer_Time(50);
      
      
    }

      
  }
    

     
       
     }
  
}


