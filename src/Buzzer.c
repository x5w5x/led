#include<REGX52.H>

sbit Buzzer = P2^5; //���������ӿ�
void BuzzerDelay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	
	i = 227;
	while (--i);
}
/**
 * @name: Buzzer_Time
 * @brief: ��������ʱ����
 * @param {unsigned int} ms
 * @return {*}
 * 
 */
void Buzzer_Time(unsigned int ms)
{   unsigned char i;
   for( i=0;i<ms;i++)
         {
          Buzzer=!Buzzer;
          BuzzerDelay500us();

      }
}