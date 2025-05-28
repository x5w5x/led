#ifndef _ONEWIRE_H_
#define _ONEWIRE_H_


unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char dat);
unsigned char OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char dat);
unsigned char OneWire_ReceiveByte(void);
#endif