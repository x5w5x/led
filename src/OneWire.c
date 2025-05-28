#include<REG52x2.h>
/**
 * @file OneWire.c
 * @brief 1-Wire总线驱动
 * @author 0x9370
 */
sbit OneWire_DQ = P3^7;

/**
 * @brief 1-Wire总线初始化
 * @param 无
 * @retval 从机响应位，0为响应，1为未响应
 * 
 */

unsigned char OneWire_Init(void)
{
    unsigned char i,Ackbit;
	OneWire_DQ = 1; //释放总线
    OneWire_DQ = 0; //拉低总线
	i = 227; //247
	while (--i); //Delay 500us

	OneWire_DQ = 1;
    i = 28; //Delay 70us
	while (--i);

	Ackbit = OneWire_DQ;

    i = 227; //247
	while (--i);

	return Ackbit;

}

/**
 * @brief 1-Wire总线发送一位
 * @param dat 要发送的位
 * @retval 无
 * 
 */

void OneWire_SendBit(unsigned char dat)
{
    unsigned char i;
    OneWire_DQ = 0;//拉低总线
    i = 3; //32
    while (--i);//Delay 10us
    OneWire_DQ = dat;
    i = 22;
    while (--i);//Delay 50us
    OneWire_DQ = 1;//释放总线

}
/**
 * @brief 1-Wire总线接收一位
 * @param 无
 * @retval 读取的位
 * 
 */

unsigned char OneWire_ReceiveBit(void)
{
    unsigned char i,dat;
    OneWire_DQ = 0; //拉低总线
    i = 1;
	while (--i);//Delay 5us
    OneWire_DQ = 1;
    i = 1;
	while (--i);//Delay 5us
    dat = OneWire_DQ;
    i = 22;
    while (--i);//Delay 50us
    return dat;
}
/**
 * @brief 1-Wire总线发送一个字节
 * @param dat 要发送的字节
 * @retval 无
 */
void OneWire_SendByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(dat&(0x01<<i));//发送一位
        
    }
}

/**
 * @brief 1-Wire总线接收一个字节
 * @param 无
 * @retval 接收的字节
 */
unsigned char OneWire_ReceiveByte(void)
{
    unsigned char i,dat = 0x00;
    for(i=0;i<8;i++)
    {
        if(OneWire_ReceiveBit())
        {
            dat |=( 0x01<<i);//接收一位
        }
    }
    return dat;
}


