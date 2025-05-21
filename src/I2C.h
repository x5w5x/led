#ifndef _I2C_H
#define _I2C_H

void I2C_Start();
void I2C_Stop();
void I2C_SendByte(unsigned char dat);
unsigned char I2C_ReceiveByte();
void I2C_SendACK(unsigned char Ack);
unsigned char I2C_ReceiveACK();

#endif