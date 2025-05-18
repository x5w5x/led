#ifndef _DS1302_H_
#define _DS1302_H_
extern unsigned char DS1302_Time[]; 
void DS1302_Init(); //初始化
void  DS1302_WriteByte(unsigned char Command, unsigned char Data); //写一个字节
unsigned char DS1302_ReadByte(unsigned char Command); //读一个字节
void DS1302_SetTime(void); //设置数组时间
void DS1302_ReadTime(void); //读取数组时间

struct DS1302
{
    unsigned char Year;
    unsigned char Month;
    unsigned char Date;
    unsigned char Hour;
    unsigned char Minute;
    unsigned char Second;
    unsigned char Day;
};

extern struct DS1302 time;

void DS1302_SetTime2(void); //设置结构体时间
void DS1302_GetTime(void); //读取结构体时间

//时间单独设置读取

void DS1302_SetYear(unsigned char Year); //单独设置年
void DS1302_SetMonth(unsigned char Month); //单独设置月
void DS1302_SetDate(unsigned char Date); //单独设置日
void DS1302_SetHour(unsigned char Hour); //单独设置时
void DS1302_SetMinute(unsigned char Minute); //单独设置分
void DS1302_SetSecond(unsigned char Second); //单独设置秒
void DS1302_SetDay(unsigned char Day);

/*
//函数封装占内存
unsigned char DS1302_GetYear(void);     //单独读取年
unsigned char DS1302_GetMonth(void);   //单独读取月
unsigned char DS1302_GetDate(void);    //单独读取日
unsigned char DS1302_GetHour(void);    //单独读取时
unsigned char DS1302_GetMinute(void);  //单独读取分
unsigned char DS1302_GetSecond(void);  //单独读取秒
unsigned char DS1302_GetDay(void);     //单独读取星期
*/
// #define DS1302_ReadYear() (DS1302_ReadByte(0x8c))
#define DS1302_SECOND 0x80 //秒
#define DS1302_MINUTE 0x82 //分
#define DS1302_HOUR 0x84 //时
#define DS1302_DATE 0x86  //日
#define DS1302_MONTH 0x88  //月
#define DS1302_DAY 0x8a  //星期
#define DS1302_YEAR 0x8c //年
#define DS1302_WP 0x8e //写保护

#define DS1302_ReadYear() (DS1302_ReadByte(DS1302_YEAR)) //读取年
#define DS1302_ReadMonth() (DS1302_ReadByte(DS1302_MONTH)) //读取月
#define DS1302_ReadDate() (DS1302_ReadByte(DS1302_DATE)) //读取日
#define DS1302_ReadHour() (DS1302_ReadByte(DS1302_HOUR)) //读取时
#define DS1302_ReadMinute() (DS1302_ReadByte(DS1302_MINUTE)) //读取分
#define DS1302_ReadSecond() (DS1302_ReadByte(DS1302_SECOND)) //读取秒
#define DS1302_ReadDay() (DS1302_ReadByte(DS1302_DAY)) //读取星期


#endif