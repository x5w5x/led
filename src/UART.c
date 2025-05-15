#include <REGX52.H>
/**
 * @name UART_Init 
 * @brief ��ʼ������ 4800bps@11.0592MHz
 * @param ��
 * @retval ��
 */
void UART_Init()  //4800bps@11.0592MHz
{
    SCON=0x40; //���ô��ڹ���ģʽ1
    PCON|= 0x80; //�����ʼӱ�
    TMOD&=0x0F;//���ö�ʱ��1Ϊ������ʽ2
    TMOD|=0x20;//���ö�ʱ��1Ϊ������ʽ2
    TL1=0xf4; //���ö�ʱ����ֵ
    TH1=0xf4; //���ö�ʱ������ֵ
    TR1=1; //������ʱ��1
    ET1=0; //��ֹ��ʱ��1�ж�
}
/**
 *  @name UART_SendByte
 * @brief ���ڷ���һ���ֽ�
 * @param dat Ҫ���͵�����
 * @retval ��
 * 
 */
void UART_SendByte(unsigned char dat)
{
    SBUF=dat;
    while(!TI);
    TI=0;
}