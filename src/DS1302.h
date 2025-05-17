#ifndef _DS1302_H_
#define _DS1302_H_
extern unsigned char DS1302_Time[]; 
void DS1302_Init();
void  DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime(void);
void DS1302_ReadTime(void);

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


void DS1302_GetTime(void);

#endif