#include <REGX52.H>
#include "DS1302.h"
//����
sbit DS1302_SCLK = P3^6; //ʱ��
sbit DS1302_IO = P3^4; //����
sbit DS1302_CE = P3^5;  //ʹ��
//��ַ
#define DS1302_SECOND 0x80 //��
#define DS1302_MINUTE 0x82 //��
#define DS1302_HOUR 0x84 //ʱ
#define DS1302_DATE 0x86  //��
#define DS1302_MONTH 0x88  //��
#define DS1302_DAY 0x8a  //����
#define DS1302_YEAR 0x8c //��
#define DS1302_WP 0x8e //д����

//ʱ��������
unsigned char DS1302_Time[]={25,5,17,20,26,16,6}; //��ʼʱ������ 25��5��17��20ʱ26��16������6
//ʱ��ṹ��
struct DS1302 time;

/**
 * @brief ��ʼ��DS1302
 * @note
 */
void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;
    // DS1302_WriteByte(0x8e,0x00);

}

/**
 * @brief ��DS1302д��һ���ֽ�
 * @note
 * @param Command �����ַ
 * @param Data ����
 * @retval None
 */
void  DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
    unsigned char i;
    DS1302_CE=1; //ʹ��
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i); //д����
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
    for( i=0;i<8;i++)
    {
        DS1302_IO=Data&(0x01<<i); //д����
        DS1302_SCLK=1; 
        
        DS1302_SCLK=0;

    }
    DS1302_CE=0; //��ֹ
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i,Data=0x00; //����
    Command|=0x01; //������
    DS1302_CE=1;  //ʹ��
    for( i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i); //д����
        DS1302_SCLK=0; 
        
        DS1302_SCLK=1;
    }
    
    for( i=0;i<8;i++)
    {
    DS1302_SCLK=1;//����һ�Σ���ʱ��ͼ��
    DS1302_SCLK=0;
    if (DS1302_IO) //������
    {
        Data|=(0x01<<i);
    }
    }
    DS1302_CE=0; //��ֹ
    DS1302_IO=0; //�ͷ�IO
    Data=Data/16*10+Data%16;//BCD��תʮ����
    return Data;

}
/**
 * @brief ��������ʱ��
 * @note
 * @retval None
 */
void DS1302_SetTime(void)
{
    //��ħ��WriteByte������ֱ��д��BCD��
    //��ֹд������ָ�����
    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10); //д�����
    DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10); //д���·�
    DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10); //д������
    DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);   //д��Сʱ
    DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10); //д�����
    DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10); //д����
    DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10); //д������
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
    
}
/**
 * @brief ��ȡ����ʱ��
 * @note
 * @retval None
 */
void DS1302_ReadTime(void)
{  
    
    
    /*
    unsigned char Temp=0;
    Temp=DS1302_ReadByte(DS1302_YEAR); //��ȡ���
    DS1302_Time[0]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_MONTH); //��ȡ�·�
    DS1302_Time[1]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_DATE); //��ȡ����
    DS1302_Time[2]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_HOUR); //��ȡСʱ
    DS1302_Time[3]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_MINUTE); //��ȡ����
    DS1302_Time[4]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_SECOND); //��ȡ��
    DS1302_Time[5]=Temp/16*10+Temp%16; 
    Temp=DS1302_ReadByte(DS1302_DAY); //��ȡ����
    DS1302_Time[6]=Temp/16*10+Temp%16;
    */

    //
    DS1302_Time[0]=DS1302_ReadByte(DS1302_YEAR); //��ȡ���
    DS1302_Time[1]=DS1302_ReadByte(DS1302_MONTH); //��ȡ�·�
    DS1302_Time[2]=DS1302_ReadByte(DS1302_DATE); //��ȡ����
    DS1302_Time[3]=DS1302_ReadByte(DS1302_HOUR); //��ȡСʱ
    DS1302_Time[4]=DS1302_ReadByte(DS1302_MINUTE); //��ȡ����
    DS1302_Time[5]=DS1302_ReadByte(DS1302_SECOND); //��ȡ��
    DS1302_Time[6]=DS1302_ReadByte(DS1302_DAY); //��ȡ����



   
    
}
 
/**
 * @brief ��ȡ�ṹ��ʱ��
 * @note
 * @retval None
 */
void DS1302_GetTime(void)
{
    time.Year=DS1302_ReadByte(DS1302_YEAR); //��ȡ���
    time.Month=DS1302_ReadByte(DS1302_MONTH); //��ȡ�·�
    time.Date=DS1302_ReadByte(DS1302_DATE); //��ȡ����
    time.Hour=DS1302_ReadByte(DS1302_HOUR); //��ȡСʱ
    time.Minute=DS1302_ReadByte(DS1302_MINUTE); //��ȡ����
    time.Second=DS1302_ReadByte(DS1302_SECOND); //��ȡ��
    time.Day=DS1302_ReadByte(DS1302_DAY); //��ȡ����

}

/**
 * @brief ��������ʱ��
 * @note
 * @param Year ��
 */
void DS1302_SetYear(unsigned char Year)
{   
    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Year=Year/10*16+Year%10;
    DS1302_WriteByte(DS1302_YEAR,Year); //д�����
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ���������·�
 * @note
 * @param Month ��
 */
void DS1302_SetMonth(unsigned char Month)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Month=Month/10*16+Month%10;
    DS1302_WriteByte(DS1302_MONTH,Month); //д���·�
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ������������
 * @note
 * @param Date ��
 */
void DS1302_SetDate(unsigned char Date)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Date=Date/10*16+Date%10;
    DS1302_WriteByte(DS1302_DATE,Date); //д������
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ��������Сʱ
 * @note
 * @param Hour ʱ
*/
void DS1302_SetHour(unsigned char Hour)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Hour=Hour/10*16+Hour%10;
    DS1302_WriteByte(DS1302_HOUR,Hour); //д��Сʱ
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief �������÷���
 * @note
 * @param Minute ��
 */
void DS1302_SetMinute(unsigned char Minute)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Minute=Minute/10*16+Minute%10;
    DS1302_WriteByte(DS1302_MINUTE,Minute); //д�����
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ����������
 * @note
 * @param Second ��
 */
void DS1302_SetSecond(unsigned char Second)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Second=Second/10*16+Second%10;
    DS1302_WriteByte(DS1302_SECOND,Second); //д����
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ������������
 * @note
 * @param Day ����
 */
void DS1302_SetDay(unsigned char Day)
{    DS1302_WriteByte(DS1302_WP,0x00); //�ر�д����
    Day=Day/10*16+Day%10;
    DS1302_WriteByte(DS1302_DAY,Day); //д������
    DS1302_WriteByte(DS1302_WP,0x80); //����д����
}
/**
 * @brief ������ȡ���
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetYear(void)
{
    return DS1302_ReadByte(DS1302_YEAR); //��ȡ���
    
}
/**
 * @brief ������ȡ�·�
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetMonth(void)
{
    return DS1302_ReadByte(DS1302_MONTH); //��ȡ�·�
}
/**
 * @brief ������ȡ����
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetDate(void)
{
    return DS1302_ReadByte(DS1302_DATE); //��ȡ����
}
/**
 * @brief ������ȡСʱ
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetHour(void)
{
    return DS1302_ReadByte(DS1302_HOUR); //��ȡСʱ
}
/**
 * @brief ������ȡ����
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetMinute(void)
{
    return DS1302_ReadByte(DS1302_MINUTE); //��ȡ����
}
/**
 * @brief ������ȡ��
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetSecond(void)
{
    return DS1302_ReadByte(DS1302_SECOND); //��ȡ��
}
/**
 * @brief ������ȡ����
 * @note
 * @retval unsigned char
 */
unsigned char DS1302_GetDay(void)
{
    return DS1302_ReadByte(DS1302_DAY); //��ȡ����
}
