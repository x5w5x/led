#ifndef _DS1302_H_
#define _DS1302_H_
extern unsigned char DS1302_Time[]; 
void DS1302_Init(); //��ʼ��
void  DS1302_WriteByte(unsigned char Command, unsigned char Data); //дһ���ֽ�
unsigned char DS1302_ReadByte(unsigned char Command); //��һ���ֽ�
void DS1302_SetTime(void); //��������ʱ��
void DS1302_ReadTime(void); //��ȡ����ʱ��

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

void DS1302_SetTime2(void); //���ýṹ��ʱ��
void DS1302_GetTime(void); //��ȡ�ṹ��ʱ��

//ʱ�䵥�����ö�ȡ

void DS1302_SetYear(unsigned char Year); //����������
void DS1302_SetMonth(unsigned char Month); //����������
void DS1302_SetDate(unsigned char Date); //����������
void DS1302_SetHour(unsigned char Hour); //��������ʱ
void DS1302_SetMinute(unsigned char Minute); //�������÷�
void DS1302_SetSecond(unsigned char Second); //����������
void DS1302_SetDay(unsigned char Day);


unsigned char DS1302_GetYear(void);     //������ȡ��
unsigned char DS1302_GetMonth(void);   //������ȡ��
unsigned char DS1302_GetDate(void);    //������ȡ��
unsigned char DS1302_GetHour(void);    //������ȡʱ
unsigned char DS1302_GetMinute(void);  //������ȡ��
unsigned char DS1302_GetSecond(void);  //������ȡ��
unsigned char DS1302_GetDay(void);     //������ȡ����



#endif