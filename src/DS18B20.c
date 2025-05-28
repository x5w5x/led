
#include <REGX52.H>
#include "OneWire.h"

//DS18B20指令
#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE

/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT(void)
{
	OneWire_Init();//初始化
	OneWire_SendByte(DS18B20_SKIP_ROM);//跳过ROM
	OneWire_SendByte(DS18B20_CONVERT_T);//开始温度转换
}

/**
  * @brief  DS18B20读取温度
  * @param  无
  * @retval 温度数值
  */
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();//初始化
	OneWire_SendByte(DS18B20_SKIP_ROM); //跳过ROM
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);//读取温度
	TLSB=OneWire_ReceiveByte(); //温度低字节
	TMSB=OneWire_ReceiveByte(); //温度高字节
	Temp=(TMSB<<8)|TLSB; //组合温度
	T=Temp/16.0; //温度转换
	return T; //返回温度值
}
