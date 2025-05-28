#include<REG52x2.h>
/**
 * @file OneWire.c
 * @brief 1-Wire��������
 * @author 0x9370
 */
sbit OneWire_DQ = P3^7;

/**
 * @brief 1-Wire���߳�ʼ��
 * @param ��
 * @retval �ӻ���Ӧλ��0Ϊ��Ӧ��1Ϊδ��Ӧ
 * 
 */

unsigned char OneWire_Init(void)
{
    unsigned char i,Ackbit;
	OneWire_DQ = 1; //�ͷ�����
    OneWire_DQ = 0; //��������
	i = 227; //247
	while (--i); //Delay 500us

	OneWire_DQ = 1;
    i = 28; //Delay 70us
	while (--i);

	Ackbit = OneWire_DQ;

    i = 227; //247
	while (--i);

	return Ackbit;

}

/**
 * @brief 1-Wire���߷���һλ
 * @param dat Ҫ���͵�λ
 * @retval ��
 * 
 */

void OneWire_SendBit(unsigned char dat)
{
    unsigned char i;
    OneWire_DQ = 0;//��������
    i = 3; //32
    while (--i);//Delay 10us
    OneWire_DQ = dat;
    i = 22;
    while (--i);//Delay 50us
    OneWire_DQ = 1;//�ͷ�����

}
/**
 * @brief 1-Wire���߽���һλ
 * @param ��
 * @retval ��ȡ��λ
 * 
 */

unsigned char OneWire_ReceiveBit(void)
{
    unsigned char i,dat;
    OneWire_DQ = 0; //��������
    i = 1;
	while (--i);//Delay 5us
    OneWire_DQ = 1;
    i = 1;
	while (--i);//Delay 5us
    dat = OneWire_DQ;
    i = 22;
    while (--i);//Delay 50us
    return dat;
}
/**
 * @brief 1-Wire���߷���һ���ֽ�
 * @param dat Ҫ���͵��ֽ�
 * @retval ��
 */
void OneWire_SendByte(unsigned char dat)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(dat&(0x01<<i));//����һλ
        
    }
}

/**
 * @brief 1-Wire���߽���һ���ֽ�
 * @param ��
 * @retval ���յ��ֽ�
 */
unsigned char OneWire_ReceiveByte(void)
{
    unsigned char i,dat = 0x00;
    for(i=0;i<8;i++)
    {
        if(OneWire_ReceiveBit())
        {
            dat |=( 0x01<<i);//����һλ
        }
    }
    return dat;
}


