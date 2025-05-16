#include <REGX52.H>

sbit DS1302_SCLK = P3^6; //时钟
sbit DS1302_IO = P3^4; //数据
sbit DS1302_CE = P3^5;  //使能


void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;

}


void  DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
    unsigned char i;
    DS1302_CE=1; //使能
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<1); //写数据
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
    for( i=0;i<8;i++)
    {
        DS1302_IO=Data&(0x01<<1); //写数据
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i,Data=0;
    DS1302_CE=1; 
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<1); //写数据
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;
    }
}