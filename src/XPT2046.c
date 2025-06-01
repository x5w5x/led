#include<REGX52.H>

//引脚定义
sbit XPT2046_CS = P3^5; //片选
sbit XPT2046_DCLK = P3^6; //时钟
sbit XPT2046_DIN = P3^4; //数据输入
sbit XPT2046_DOUT = P3^7; //数据输出

/**
 * @name   XPT2046_Read_AD
 * @brief  读取AD值
 * @param  Cmd:命令
 * @retval AD值
 */
unsigned int XPT2046_Read_AD(unsigned char Cmd)
{
unsigned char i;
unsigned int AD_Value=0; //定义一个变量来存储AD值

XPT2046_CS = 0; //片选使能
XPT2046_DCLK = 0; //时钟线拉低

for(i=0;i<8;i++)
{
    XPT2046_DIN = Cmd &0x80; //将Cmd最高位赋值给DIN
    Cmd <<= 1; //将Cmd左移一位
    XPT2046_DCLK = 1; //时钟线拉高
    XPT2046_DCLK = 0; //时钟线拉低
}

for(i=0;i<16;i++)
{
    XPT2046_DCLK = 1;
    XPT2046_DCLK = 0;

    if (XPT2046_DOUT) 
    {
    AD_Value |= (0x8000>>i); //将DOUT的值赋值给AD_Value
    }
}
    XPT2046_CS = 1; //片选关闭
    return AD_Value>>8; //返回AD值
}