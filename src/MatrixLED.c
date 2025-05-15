#include<REGX52.H>


sbit RCK=P3^5; //74HC595�Ĵ�������
sbit SCK=P3^6;  //74HC595��λ�Ĵ�������
sbit SER=P3^4;   //74HC595������������

#define MatrixLED_Port P0 //LED����˿�
void Delay(unsigned int t)
{
    unsigned int i,j;
    
    for(i=0;i<t;i++)
        
        for(j=0;j<125;j++);
}

/**
 * 
 * @description: ��ʼ��74HC595
 */
void MatrixLED_Init()
{
    MatrixLED_Port=0xFF; //�ر�����LED
    RCK=0; 
    SCK=0;
}

void HC595_WriteByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++) //ѭ��8�Σ���һ���ֽڵ����ݷ��͵�74HC595
    {  
        SCK=0;
        //SER=(dat&0x80>>i);
        SER=dat&0x80; //��dat�����λ���͵�74HC595
        dat<<=1; //dat����һλ��׼��������һ��λ
        SCK=1;
    }
    RCK=1;
    RCK=0;
    
}


/**
 * 
 * @description: 74HC595��ʾһ������
 * @param {unsigned char} column �к�
 * @param {unsigned char} dat ����
 * @param����λ���ϣ���λ����
 * 
 * 
 */
void MatrixLED_ShowColumn(unsigned char column, unsigned char dat)
{
    HC595_WriteByte(dat); //�����ݷ��͵�74HC595
    MatrixLED_Port=~(0x80>>column); //����Ӧ�е�LED��
    Delay(1);
    MatrixLED_Port=0xFF; //��Ӱ
    
}
