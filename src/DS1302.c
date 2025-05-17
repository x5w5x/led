#include <REGX52.H>

sbit DS1302_SCLK = P3^6; //ʱ��
sbit DS1302_IO = P3^4; //����
sbit DS1302_CE = P3^5;  //ʹ��

#define DS1302_SECOND 0x80 //��
#define DS1302_MINUTE 0x82 //��
#define DS1302_HOUR 0x84 //ʱ
#define DS1302_DATE 0x86  //��
#define DS1302_MONTH 0x88  //��
#define DS1302_DAY 0x8a  //����
#define DS1302_YEAR 0x8c //��
#define DS1302_WP 0x8e //д����

unsigned char DS1302_Time[]={17,12,16,16,16,16,16};



void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;
    // DS1302_WriteByte(0x8e,0x00);

}


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
    DS1302_SCLK=1;
    DS1302_SCLK=0;
    if (DS1302_IO) //������
    {
        Data|=(0x01<<i);
    }
    }
    DS1302_CE=0; //��ֹ
    DS1302_IO=0; //�ͷ�IO
    Data=Data/16*10+Data%16;
    return Data;

}



void DS1302_SetTime(void)
{
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