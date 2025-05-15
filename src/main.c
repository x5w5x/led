
#include <REGX52.H>
#include "UART.h"
#include"Timer.h"
#include"MatrixLED.h"

// void Delay(unsigned int t)
// {
//     unsigned int i,j;
    
//     for(i=0;i<t;i++)
        
//         for(j=0;j<125;j++);
// }












unsigned char sec=0;
void main()
{
    MatrixLED_Init();
    
     while(1)
     {
        MatrixLED_ShowColumn(0,0x80);
        MatrixLED_ShowColumn(1,0x40);
        MatrixLED_ShowColumn(2,0x20);
        MatrixLED_ShowColumn(3,0x10);
     }
  
}




