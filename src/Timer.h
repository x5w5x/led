#ifndef __TIMER_H__
#define __TIMER_H__
void Timer0_Init();
//
void Timer0_InitCounter();
void Timer0_SetCounter(unsigned int counter);
unsigned int Timer0_GetCounter(void);
void Timer0_Run(unsigned char Flag);
#endif