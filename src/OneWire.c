#include<REG52x2.h>

sbit OneWire_DQ = P3^7;



unsigned char OneWire_Init(void)
{
        unsigned char i,Ackbit;

	OneWire_DQ = 1; 
    OneWire_DQ = 0;
	i = 227; //247
	while (--i);
	OneWire_DQ = 1;
    i = 29; //32
	while (--i);
	Ackbit = OneWire_DQ;
    i = 227; //247
	while (--i);
	return Ackbit;

}



void OneWire_SendBit(unsigned char dat)
{

OneWire_DQ = 0;
 i = 3; //32
while (--i);
OneWire_DQ = dat;
i = 22;
while (--i);
OneWire_DQ = 1;

}


unsigned char OneWire_ReceiveBit(void)
{
    unsigned char i,dat;
    OneWire_DQ = 0;
    i = 1;//5
	while (--i);
    OneWire_DQ = 1;
    i = 1;
	while (--i);
    dat = OneWire_DQ;
    i = 22;
    while (--i);
    return dat;
}

void OneWire_SendByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(dat&(0x01<<i));
        dat >>= 1;
    }
}


unsigned char OneWire_ReceiveByte(void)
{
    unsigned char i,dat = 0;
    for(i=0;i<8;i++)
    {
        dat >>= 1;
        if(OneWire_ReceiveBit())
        {
            dat |= 0x80;
        }
    }
    return dat;
}