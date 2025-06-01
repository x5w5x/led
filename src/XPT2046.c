#include<REGX52.H>

//���Ŷ���
sbit XPT2046_CS = P3^5; //Ƭѡ
sbit XPT2046_DCLK = P3^6; //ʱ��
sbit XPT2046_DIN = P3^4; //��������
sbit XPT2046_DOUT = P3^7; //�������

/**
 * @name   XPT2046_Read_AD
 * @brief  ��ȡADֵ
 * @param  Cmd:����
 * @retval ADֵ
 */
unsigned int XPT2046_Read_AD(unsigned char Cmd)
{
unsigned char i;
unsigned int AD_Value=0; //����һ���������洢ADֵ

XPT2046_CS = 0; //Ƭѡʹ��
XPT2046_DCLK = 0; //ʱ��������

for(i=0;i<8;i++)
{
    XPT2046_DIN = Cmd &0x80; //��Cmd���λ��ֵ��DIN
    Cmd <<= 1; //��Cmd����һλ
    XPT2046_DCLK = 1; //ʱ��������
    XPT2046_DCLK = 0; //ʱ��������
}

for(i=0;i<16;i++)
{
    XPT2046_DCLK = 1;
    XPT2046_DCLK = 0;

    if (XPT2046_DOUT) 
    {
    AD_Value |= (0x8000>>i); //��DOUT��ֵ��ֵ��AD_Value
    }
}
    XPT2046_CS = 1; //Ƭѡ�ر�
    return AD_Value>>8; //����ADֵ
}