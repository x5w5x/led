#ifndef _XPT2046_H_
#define _XPT2046_H_




#define XPT2046_XP_8 0x9C //XP地址
#define XPT2046_YP_8 0xDC //YP地址
#define XPT2046_VBAT_8 0xAC //VBAT地址
#define XPT2046_AUX_8 0xEC //AUX地址
 
#define XPT2046_XP_12 0x94 //XP地址
#define XPT2046_YP_12 0xD4 //YP地址
#define XPT2046_VBAT_12 0xA4 //VBAT地址
#define XPT2046_AUX_12 0xE4 //AUX地址

unsigned int XPT2046_Read_AD(unsigned char Cmd);
/*
 ADvalue=XPT2046_Read_AD(XPT2046_XP_12);
LCD_ShowNum(2,1,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_YP_12);
LCD_ShowNum(2,5,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_VBAT_12);
LCD_ShowNum(2,9,ADvalue,4);
 ADvalue=XPT2046_Read_AD(XPT2046_AUX_12);
LCD_ShowNum(2,13,ADvalue,4);
*/



#endif