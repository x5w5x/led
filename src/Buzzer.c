#include<REGX52.H>

sbit Buzzer = P2^5; //·äÃùÆ÷Á¬½Ó¿Ú
void Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned int ms)
{   unsigned char i;
   for( i=0;i<ms;i++)
         {
          Buzzer=!Buzzer;
          Delay500us();

      }
}