#include <REGX52.H>
/**
 * @name UART_Init 
 * @brief 初始化串口 4800bps@11.0592MHz
 * @param 无
 * @retval 无
 */
void UART_Init()  //4800bps@11.0592MHz
{
    SCON=0x40; //设置串口工作模式1
    PCON|= 0x80; //波特率加倍
    TMOD&=0x0F;//设置定时器1为工作方式2
    TMOD|=0x20;//设置定时器1为工作方式2
    TL1=0xf4; //设置定时器初值
    TH1=0xf4; //设置定时器重载值
    TR1=1; //启动定时器1
    ET1=0; //禁止定时器1中断
}
/**
 *  @name UART_SendByte
 * @brief 串口发送一个字节
 * @param dat 要发送的数据
 * @retval 无
 * 
 */
void UART_SendByte(unsigned char dat)
{
    SBUF=dat;
    while(!TI);
    TI=0;
}