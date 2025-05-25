#include <REGX52.H>
sbit Key1=P3^1;
sbit Key2=P3^0;
sbit Key3=P3^2;
sbit Key4=P3^3;



unsigned char KeyNumm;
unsigned char key(void){
    unsigned char Temp;
    Temp = KeyNumm;
    KeyNumm = 0;
    return Temp;
}
void Keydelay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}

unsigned char key_scan(void)
{
    unsigned char key_value = 0;
    if(Key1==0){
       
            while(Key1==0);
      
            key_value = 1;
    }
    if(Key2==0){
        
            while(Key2==0);
           
            key_value = 2;
    }
    if(Key3==0){
        
            while(Key3==0);
           
            key_value = 3;
    }
    if(Key4==0){
       
            while(Key4==0);
        
            key_value = 4;
    }
    return key_value;

}

void Key_loop(void)
{
static unsigned char NowState, LastState;
    LastState = NowState;
    NowState = key_scan();
    if(NowState == 1 && LastState == 0){
        KeyNumm = 1;
    }
    if(NowState == 2 && LastState == 0){
        KeyNumm = 2;
    }
    if(NowState == 3 && LastState == 0){
        KeyNumm = 3;
    }
    if(NowState == 4 && LastState == 0){
        KeyNumm = 4;
    }

}


// void Time0_Routine(void) interrupt 1
// {
//     static unsigned int t0;
//     TL0=0x18;
//     TH0=0xFC;
//     t0++;
//     if(t0==20){
//         t0=0;
//         Key_loop();
//     }
// }