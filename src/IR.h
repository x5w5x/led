#ifndef _IR_H_
#define _IR_H_
void IR_Init(void);
unsigned char IR_GetDataFlag(void);
unsigned char IR_GetRepeatFlag(void);
unsigned char IR_GetAddress(void);
unsigned char IR_GetCommand(void);
#endif /* _IR_H_ */