#include<REGX52.H>
#include<string.h>

sbit RCK=P3^5; //74HC595寄存器锁存
sbit SCK=P3^6;  //74HC595移位寄存器锁存
sbit SER=P3^4;   //74HC595串行数据输入

#define MatrixLED_Port P0 //LED矩阵端口

void Delay(unsigned int t)
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}

/**
 * 
 * @description: 初始化74HC595
 */
void MatrixLED_Init()
{
    MatrixLED_Port=0xFF; //关闭所有LED
    RCK=0; 
    SCK=0;
}

void HC595_WriteByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++) //循环8次，将一个字节的数据发送到74HC595
    {  
        SCK=0;
        //SER=(dat&0x80>>i);
        SER=dat&0x80; //将dat的最低位发送到74HC595
        dat<<=1; //dat左移一位，准备发送下一个位
        SCK=1;
    }
    RCK=1; //锁存数据
    RCK=0; //释放锁存
    
}


/**
 * 
 * @description: 74HC595显示一列数据
 * @param {unsigned char} column 列号
 * @param {unsigned char} dat 数据 16进制
 * @param：高位在上，低位在下
 * 
 * 
 */
void MatrixLED_ShowColumn(unsigned char column, unsigned char dat)
{
    HC595_WriteByte(dat); //将数据发送到74HC595
    MatrixLED_Port=~(0x80>>column); //将对应列的LED打开
    Delay(1);
    MatrixLED_Port=0xFF; //消影
    
}
/**
 * 
 * @description: 74HC595显示一串数据
 * @param {unsigned char} dat[] 数据数组 8个字节
 * @note：高位在上，低位在下
 */
void MatrixLED_Show(unsigned char dat[])
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        MatrixLED_ShowColumn(i,dat[i]);
    }
}



//必要定义
unsigned char i,Offset=0,count=0; //定义变量
/**
 * 
 * @description: 74HC595显示一串数据，滚动显示
 * @param {unsigned char} dat[] 数据数组 8个字节
 * @param {unsigned char} length 数据长度
 * @note：高位在上，低位在下
 * 
 */
void MatrixLED_FlowShow(unsigned char dat[],unsigned char length)
{
        for(i=0;i<8;i++)
        {
           MatrixLED_ShowColumn(i,dat[i+Offset]);

        }
        count++;
        if(count>10) //控制滚动速度
        {
           count=0;
           Offset++; //流动显示
         //   Offset+=8; //快速显示（逐桢）
           if(Offset>length-8)
           {
              Offset=0;
           }
        }

}
/**
 * 
 * @description: 74HC595显示一串数据，逐帧显示
 * @param {unsigned char} dat[] 数据数组 8个字节
 * @param {unsigned char} length 数据长度
 * @note：高位在上，低位在下
 * 
 */
void MatrixLED_AnimateShow(unsigned char dat[],unsigned char length)
{
      for(i=0;i<8;i++)
        {
           MatrixLED_ShowColumn(i,dat[i+Offset]);

        }
        count++;
        if(count>10) //控制滚动速度
        {
           count=0;
           Offset+=8; //快速显示（逐桢）
           if(Offset>length-8)
           {
              Offset=0;
           }
        }
}