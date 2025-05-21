#include<REGX52.H>

sbit Buzzer = P2^5; //蜂鸣器连接口
void BuzzerDelay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	
	i = 227;
	while (--i);
}
/**
 * @name: Buzzer_Time
 * @brief: 蜂鸣器延时函数
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