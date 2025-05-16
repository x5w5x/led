#include <REGX52.H>

sbit DS1302_SCLK = P3^6; //时钟
sbit DS1302_IO = P3^4; //数据
sbit DS1302_CE = P3^5;  //使能