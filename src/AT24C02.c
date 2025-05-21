#include <REG52x2.h>
#include"I2C.h"

#define AT24C02_ADDRESS 0xA0


/**
 * @function: AT24C02_Write
 * @brief:   AT24C02写入一个字节
 * @param:   addr:地址 dat:数据 均为0~255
 * @return:  无
 * 
 */
void AT24C02_Write(unsigned char addr,unsigned char dat)
{   
    
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveACK();
    I2C_SendByte(addr);
    I2C_ReceiveACK();
    I2C_SendByte(dat);
    I2C_ReceiveACK();
    I2C_Stop();

   
}

/**
 * @function: AT24C02_Read
 * @brief:   AT24C02读取一个字节
 * @param:   addr:地址
 * @return:  dat:数据 均为0~255
 */
unsigned char AT24C02_Read(unsigned char addr)
{   
    unsigned char dat;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveACK();
    I2C_SendByte(addr);
    I2C_ReceiveACK();
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS+1);
    I2C_ReceiveACK();
    dat = I2C_ReceiveByte();
    I2C_SendACK(1);
    I2C_Stop();
    return dat;

}