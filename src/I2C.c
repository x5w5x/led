#include<REG52x2.h>


sbit I2C_SDA = P2^1;
sbit I2C_SCL = P2^0;

/**
 * @name I2C_Start
 * @brief I2C起始信号
 * @param 无
 * @return 无
 */
void I2C_Start()
{
    I2C_SDA = 1;
    I2C_SCL = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

/**
 * @name I2C_Stop
 * @brief I2C停止信号
 * @param 无
 * @return 无
 */
void I2C_Stop()
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

/**
 * @name I2C_SendByte
 * @brief I2C发送一个字节
 * @param dat:要发送的数据
 * @return 无
 */
void I2C_SendByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++){
        I2C_SDA = dat & (0x80);
        dat <<= 1;
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
    // I2C_SDA = 1;
    // I2C_SCL = 1;
}

/**
 * @name I2C_ReceiveByte
 * @brief I2C接收一个字节
 * @param 无
 * @return 接收到的数据
 */
unsigned char I2C_ReceiveByte()
{
    unsigned char i,dat = 0x00;
    I2C_SDA = 1;
    for(i=0;i<8;i++){
        I2C_SCL = 1;
        if(I2C_SDA) dat |= (0x80>>i);
        I2C_SCL = 0;
    }
    return dat;
}

/**
 * @name I2C_SendACK
 * @brief I2C发送ACK信号
 * @param Ack:ACK信号
 * @return 无
 */
void I2C_SendACK(unsigned char Ack)
{
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

/**
 * @name I2C_ReceiveACK
 * @brief I2C接收ACK信号
 * @param 无
 * @return 接收到的ACK信号
 */
unsigned char I2C_ReceiveACK()
{
    unsigned char Ack;
    I2C_SDA = 1; //释放SDA
    I2C_SCL = 1;
    Ack = I2C_SDA;
    I2C_SCL = 0;
    return Ack;
}