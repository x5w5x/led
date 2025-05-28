
#include <REGX52.H>
#include "OneWire.h"

//DS18B20ָ��
#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE

/**
  * @brief  DS18B20��ʼ�¶ȱ任
  * @param  ��
  * @retval ��
  */
void DS18B20_ConvertT(void)
{
	OneWire_Init();//��ʼ��
	OneWire_SendByte(DS18B20_SKIP_ROM);//����ROM
	OneWire_SendByte(DS18B20_CONVERT_T);//��ʼ�¶�ת��
}

/**
  * @brief  DS18B20��ȡ�¶�
  * @param  ��
  * @retval �¶���ֵ
  */
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();//��ʼ��
	OneWire_SendByte(DS18B20_SKIP_ROM); //����ROM
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);//��ȡ�¶�
	TLSB=OneWire_ReceiveByte(); //�¶ȵ��ֽ�
	TMSB=OneWire_ReceiveByte(); //�¶ȸ��ֽ�
	Temp=(TMSB<<8)|TLSB; //����¶�
	T=Temp/16.0; //�¶�ת��
	return T; //�����¶�ֵ
}
