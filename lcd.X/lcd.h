#ifndef swa
#define swa
#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS LATCbits.LC0
#define EN LATCbits.LC1
#define LCD LATD
void pulse();
void command(char);
void data(char );

    void lcdint()
    {
    
    command(0x38);
    command(0x0e);
    command(0x01);
    }
  
   
            
    

void pulse()
{
    EN=1;
    __delay_ms(10);
     EN=0;
    __delay_ms(10);
    
}
void command(char cmd)
{
    RS=0;
    LCD=cmd;
    pulse();
}

void data(char dat)
{
    RS=1;
    LCD=dat;
    pulse();
}
void conv(int num)
{
    unsigned int thou,hun,ten,unit,temp;
    thou=num/1000;
    temp=num%1000;
    hum=temp/100;
    temp=temp%100;
    tens=temp/10;
    units=temp%10;
    data(thou+48);
     data(hun+48);
      data(ten+48);
       data(uints+48);
            
}
#endif