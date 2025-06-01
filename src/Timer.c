
#include <REGX52.H>
/**
 * @brief 定时器初始化函数
 * @note 1ms中断一次
 * @retval None
 */
void Timer0_Init()
{
    TMOD &=0xf0; //设置定时器0为模式1
    TMOD |=0x01; 
    
    TH0=(65535-10000)/256; //设置定时器初值 100us 10次1ms 
    TL0=(65535-10000)%256; 
    ET0=1; //允许定时器0中断
    EA=1; //允许总中断
    TR0=1; //启动定时器0
}
/**
 * @brief 定时器1初始化函数
 * @note 50ms中断一次
 * @retval None
 */
void Timer1_Init()
{
    TMOD &=0x0f; //设置定时器1为模式1
    TMOD |=0x10; 
    
    TH1=(65535-50000)/256; //设置定时器初值 50ms 20次1S
    TL1=(65535-50000)%256; 
    ET1=1; //允许定时器1中断
    EA=1; //允许总中断
    TR1=1; //启动定时器1
}
/**
 * @brief 定时器0初始化函数
 * @note 1ms中断一次
 * @retval None
 */
void Timer0ms_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
}


// void Timer0() interrupt 1
// {
//     TH0=(65535-50000)/256;
//     TL0=(65535-50000)%256;
//     count++;
//     if (count>20)
//     P2_1=~P2_1,count=0;
// }

void Timer0_InitCounter()
{
    TMOD &=0xf0; //设置定时器0为模式1
    TMOD |=0x01; 
    
    TH0=0; //设置定时器初值 100us 10次1ms 
    TL0=0; 
    TF0=0; //清除TF0标志
    TR0=0; //启动定时器0
}

void Timer0_SetCounter(unsigned int counter)
{
    TH0=counter/256;
    TL0=counter%256;
}

unsigned int Timer0_GetCounter(void)
{
    return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
    TR0=Flag;
}
