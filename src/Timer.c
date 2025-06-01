
#include <REGX52.H>
/**
 * @brief ��ʱ����ʼ������
 * @note 1ms�ж�һ��
 * @retval None
 */
void Timer0_Init()
{
    TMOD &=0xf0; //���ö�ʱ��0Ϊģʽ1
    TMOD |=0x01; 
    
    TH0=(65535-10000)/256; //���ö�ʱ����ֵ 100us 10��1ms 
    TL0=(65535-10000)%256; 
    ET0=1; //����ʱ��0�ж�
    EA=1; //�������ж�
    TR0=1; //������ʱ��0
}
/**
 * @brief ��ʱ��1��ʼ������
 * @note 50ms�ж�һ��
 * @retval None
 */
void Timer1_Init()
{
    TMOD &=0x0f; //���ö�ʱ��1Ϊģʽ1
    TMOD |=0x10; 
    
    TH1=(65535-50000)/256; //���ö�ʱ����ֵ 50ms 20��1S
    TL1=(65535-50000)%256; 
    ET1=1; //����ʱ��1�ж�
    EA=1; //�������ж�
    TR1=1; //������ʱ��1
}
/**
 * @brief ��ʱ��0��ʼ������
 * @note 1ms�ж�һ��
 * @retval None
 */
void Timer0ms_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}


// void Timer0() interrupt 1
// {
//     TH0=(65535-50000)/256;
//     TL0=(65535-50000)%256;
//     count++;
//     if (count>20)
//     P2_1=~P2_1,count=0;
// }

void Timer0_InitCounter()
{
    TMOD &=0xf0; //���ö�ʱ��0Ϊģʽ1
    TMOD |=0x01; 
    
    TH0=0; //���ö�ʱ����ֵ 100us 10��1ms 
    TL0=0; 
    TF0=0; //���TF0��־
    TR0=0; //������ʱ��0
}

void Timer0_SetCounter(unsigned int counter)
{
    TH0=counter/256;
    TL0=counter%256;
}

unsigned int Timer0_GetCounter(void)
{
    return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
    TR0=Flag;
}
