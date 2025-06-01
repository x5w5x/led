#include<REGX52.H>

/**
 * @brief 外部中断0初始化
 * @note 设置外部中断0为下降沿触发，使能外部中断0，使能总中断，设置外部中断0为高优先级
 * @retval None
 */
void Int0_Init(void) //外部中断0初始化
{
    IT0 = 1; //设置外部中断0为下降沿触发
    IE0 = 1; //使能外部中断0
    EX0 = 1; //使能外部中断0
    EA = 1; //使能总中断
    PX0 = 1; //设置外部中断0为高优先级

}




// void Int0_Routine() interrupt 0
// {
//   //中断函数代码
// }
