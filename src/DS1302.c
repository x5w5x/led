#include <REGX52.H>
#include "DS1302.h"
//引脚
sbit DS1302_SCLK = P3^6; //时钟
sbit DS1302_IO = P3^4; //数据
sbit DS1302_CE = P3^5;  //使能
//地址
#define DS1302_SECOND 0x80 //秒
#define DS1302_MINUTE 0x82 //分
#define DS1302_HOUR 0x84 //时
#define DS1302_DATE 0x86  //日
#define DS1302_MONTH 0x88  //月
#define DS1302_DAY 0x8a  //星期
#define DS1302_YEAR 0x8c //年
#define DS1302_WP 0x8e //写保护

//时间存放数组
unsigned char DS1302_Time[]={25,5,17,20,26,16,6}; //初始时间数组 25年5月17日20时26分16秒星期6
//时间结构体
struct DS1302 time;

/**
 * @brief 初始化DS1302
 * @note
 */
void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;
    // DS1302_WriteByte(0x8e,0x00);

}

/**
 * @brief 向DS1302写入一个字节
 * @note
 * @param Command 命令地址
 * @param Data 数据
 * @retval None
 */
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
    DS1302_SCLK=1;//多置一次（看时序图）
    DS1302_SCLK=0;
    if (DS1302_IO) //读数据
    {
        Data|=(0x01<<i);
    }
    }
    DS1302_CE=0; //禁止
    DS1302_IO=0; //释放IO
    Data=Data/16*10+Data%16;//BCD码转十进制
    return Data;

}
/**
 * @brief 设置数组时间
 * @note
 * @retval None
 */
void DS1302_SetTime(void)
{
    //不魔改WriteByte函数，直接写入BCD码
    //防止写入数据指令错误
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
/**
 * @brief 读取数组时间
 * @note
 * @retval None
 */
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
 
/**
 * @brief 获取结构体时间
 * @note
 * @retval None
 */
void DS1302_GetTime(void)
{
    time.Year=DS1302_ReadByte(DS1302_YEAR); //读取年份
    time.Month=DS1302_ReadByte(DS1302_MONTH); //读取月份
    time.Date=DS1302_ReadByte(DS1302_DATE); //读取日期
    time.Hour=DS1302_ReadByte(DS1302_HOUR); //读取小时
    time.Minute=DS1302_ReadByte(DS1302_MINUTE); //读取分钟
    time.Second=DS1302_ReadByte(DS1302_SECOND); //读取秒
    time.Day=DS1302_ReadByte(DS1302_DAY); //读取星期

}

/**
 * @brief 单独设置时间
 * @note
 * @param Year 年
 */
void DS1302_SetYear(unsigned char Year)
{   
    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Year=Year/10*16+Year%10;
    DS1302_WriteByte(DS1302_YEAR,Year); //写入年份
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置月份
 * @note
 * @param Month 月
 */
void DS1302_SetMonth(unsigned char Month)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Month=Month/10*16+Month%10;
    DS1302_WriteByte(DS1302_MONTH,Month); //写入月份
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置日期
 * @note
 * @param Date 日
 */
void DS1302_SetDate(unsigned char Date)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Date=Date/10*16+Date%10;
    DS1302_WriteByte(DS1302_DATE,Date); //写入日期
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置小时
 * @note
 * @param Hour 时
*/
void DS1302_SetHour(unsigned char Hour)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Hour=Hour/10*16+Hour%10;
    DS1302_WriteByte(DS1302_HOUR,Hour); //写入小时
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置分钟
 * @note
 * @param Minute 分
 */
void DS1302_SetMinute(unsigned char Minute)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Minute=Minute/10*16+Minute%10;
    DS1302_WriteByte(DS1302_MINUTE,Minute); //写入分钟
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置秒
 * @note
 * @param Second 秒
 */
void DS1302_SetSecond(unsigned char Second)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Second=Second/10*16+Second%10;
    DS1302_WriteByte(DS1302_SECOND,Second); //写入秒
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独设置星期
 * @note
 * @param Day 星期
 */
void DS1302_SetDay(unsigned char Day)
{    DS1302_WriteByte(DS1302_WP,0x00); //关闭写保护
    Day=Day/10*16+Day%10;
    DS1302_WriteByte(DS1302_DAY,Day); //写入星期
    DS1302_WriteByte(DS1302_WP,0x80); //开启写保护
}
/**
 * @brief 单独获取年份
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetYear(void)
{
    return DS1302_ReadByte(DS1302_YEAR); //读取年份
    
}
/**
 * @brief 单独获取月份
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetMonth(void)
{
    return DS1302_ReadByte(DS1302_MONTH); //读取月份
}
/**
 * @brief 单独获取日期
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetDate(void)
{
    return DS1302_ReadByte(DS1302_DATE); //读取日期
}
/**
 * @brief 单独获取小时
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetHour(void)
{
    return DS1302_ReadByte(DS1302_HOUR); //读取小时
}
/**
 * @brief 单独获取分钟
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetMinute(void)
{
    return DS1302_ReadByte(DS1302_MINUTE); //读取分钟
}
/**
 * @brief 单独获取秒
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetSecond(void)
{
    return DS1302_ReadByte(DS1302_SECOND); //读取秒
}
/**
 * @brief 单独获取星期
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetDay(void)
{
    return DS1302_ReadByte(DS1302_DAY); //读取星期
}
