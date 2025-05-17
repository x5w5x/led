#ifndef _DS1302_H_
#define _DS1302_H_
extern unsigned char DS1302_Time[];
void DS1302_Init();
void  DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime(void);
void DS1302_ReadTime(void);
void DS1302_GetTime(void);
#endif