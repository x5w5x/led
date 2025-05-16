#ifndef _MATRIXLED_H
#define _MATRIXLED_H
void MatrixLED_Init();
void MatrixLED_ShowColumn(unsigned char column, unsigned char dat);
void MatrixLED_Show(unsigned char dat[]);
void MatrixLED_FlowShow(unsigned char dat[],unsigned char length);
void MatrixLED_AnimateShow(unsigned char dat[],unsigned char length);
#endif