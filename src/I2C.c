#include<REG52x2.h>


sbit I2C_SDA = P2^1;
sbit I2C_SCL = P2^0;

/**
 * @name I2C_Start
 * @brief I2C��ʼ�ź�
 * @param ��
 * @return ��
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
 * @brief I2Cֹͣ�ź�
 * @param ��
 * @return ��
 */
void I2C_Stop()
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

/**
 * @name I2C_SendByte
 * @brief I2C����һ���ֽ�
 * @param dat:Ҫ���͵�����
 * @return ��
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
 * @brief I2C����һ���ֽ�
 * @param ��
 * @return ���յ�������
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
 * @brief I2C����ACK�ź�
 * @param Ack:ACK�ź�
 * @return ��
 */
void I2C_SendACK(unsigned char Ack)
{
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

/**
 * @name I2C_ReceiveACK
 * @brief I2C����ACK�ź�
 * @param ��
 * @return ���յ���ACK�ź�
 */
unsigned char I2C_ReceiveACK()
{
    unsigned char Ack;
    I2C_SDA = 1; //�ͷ�SDA
    I2C_SCL = 1;
    Ack = I2C_SDA;
    I2C_SCL = 0;
    return Ack;
}