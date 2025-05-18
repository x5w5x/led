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

/*
//������װռ�ڴ�
unsigned char DS1302_GetYear(void);     //������ȡ��
unsigned char DS1302_GetMonth(void);   //������ȡ��
unsigned char DS1302_GetDate(void);    //������ȡ��
unsigned char DS1302_GetHour(void);    //������ȡʱ
unsigned char DS1302_GetMinute(void);  //������ȡ��
unsigned char DS1302_GetSecond(void);  //������ȡ��
unsigned char DS1302_GetDay(void);     //������ȡ����
*/
// #define DS1302_ReadYear() (DS1302_ReadByte(0x8c))
#define DS1302_SECOND 0x80 //��
#define DS1302_MINUTE 0x82 //��
#define DS1302_HOUR 0x84 //ʱ
#define DS1302_DATE 0x86  //��
#define DS1302_MONTH 0x88  //��
#define DS1302_DAY 0x8a  //����
#define DS1302_YEAR 0x8c //��
#define DS1302_WP 0x8e //д����

#define DS1302_ReadYear() (DS1302_ReadByte(DS1302_YEAR)) //��ȡ��
#define DS1302_ReadMonth() (DS1302_ReadByte(DS1302_MONTH)) //��ȡ��
#define DS1302_ReadDate() (DS1302_ReadByte(DS1302_DATE)) //��ȡ��
#define DS1302_ReadHour() (DS1302_ReadByte(DS1302_HOUR)) //��ȡʱ
#define DS1302_ReadMinute() (DS1302_ReadByte(DS1302_MINUTE)) //��ȡ��
#define DS1302_ReadSecond() (DS1302_ReadByte(DS1302_SECOND)) //��ȡ��
#define DS1302_ReadDay() (DS1302_ReadByte(DS1302_DAY)) //��ȡ����


#endif