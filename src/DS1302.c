#include <REGX52.H>

sbit DS1302_SCLK = P3^6; //时钟
sbit DS1302_IO = P3^4; //数据
sbit DS1302_CE = P3^5;  //使能

#define DS1302_SECOND 0x80 //秒
#define DS1302_MINUTE 0x82 //分
#define DS1302_HOUR 0x84 //时
#define DS1302_DATE 0x86  //日
#define DS1302_MONTH 0x88  //月
#define DS1302_DAY 0x8a  //星期
#define DS1302_YEAR 0x8c //年
#define DS1302_WP 0x8e //写保护

unsigned char DS1302_Time[]={17,12,16,16,16,16,16};



void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;
    // DS1302_WriteByte(0x8e,0x00);

}


void  DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
    unsigned char i;
    DS1302_CE=1; //使能
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i); //写数据
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
    for( i=0;i<8;i++)
    {
        DS1302_IO=Data&(0x01<<i); //写数据
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
    DS1302_CE=0; //禁止
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i,Data=0x00; //数据
    Command|=0x01; //读数据
    DS1302_CE=1;  //使能
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i); //写数据
        DS1302_SCLK=0; 
        
        DS1302_SCLK=1;
    }
    
    for( i=0;i<8;i++)
    {
    DS1302_SCLK=1;
    DS1302_SCLK=0;
    if (DS1302_IO) //读数据
    {
        Data|=(0x01<<i);
    }
    }
    DS1302_CE=0; //禁止
    DS1302_IO=0; //释放IO
    Data=Data/16*10+Data%16;
    return Data;

}



void DS1302_SetTime(void)
{
    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10); //写入年份
    DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10); //写入月份
    DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10); //写入日期
    DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);   //写入小时
    DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10); //写入分钟
    DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10); //写入秒
    DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10); //写入星期
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
    
}

void DS1302_ReadTime(void)
{  
    
    
    /*
    unsigned char Temp=0;
    Temp=DS1302_ReadByte(DS1302_YEAR); //读取年份
    DS1302_Time[0]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_MONTH); //读取月份
    DS1302_Time[1]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_DATE); //读取日期
    DS1302_Time[2]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_HOUR); //读取小时
    DS1302_Time[3]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_MINUTE); //读取分钟
    DS1302_Time[4]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_SECOND); //读取秒
    DS1302_Time[5]=Temp/16*10+Temp%16; 
    Temp=DS1302_ReadByte(DS1302_DAY); //读取星期
    DS1302_Time[6]=Temp/16*10+Temp%16;
    */

    //
    DS1302_Time[0]=DS1302_ReadByte(DS1302_YEAR); //读取年份
    DS1302_Time[1]=DS1302_ReadByte(DS1302_MONTH); //读取月份
    DS1302_Time[2]=DS1302_ReadByte(DS1302_DATE); //读取日期
    DS1302_Time[3]=DS1302_ReadByte(DS1302_HOUR); //读取小时
    DS1302_Time[4]=DS1302_ReadByte(DS1302_MINUTE); //读取分钟
    DS1302_Time[5]=DS1302_ReadByte(DS1302_SECOND); //读取秒
    DS1302_Time[6]=DS1302_ReadByte(DS1302_DAY); //读取星期


   
    
}