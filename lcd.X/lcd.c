#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS LATCbits.LC0
#define EN LATCbits.LC1
#define LCD LATD
void pulse();
void command(char);
void data(char );
void main(void)
{
   
    PORTC=0x00;
    TRISC=0x00;
    PORTD=0x00;
    TRISD=0x00;
    ADCON1=0x0f;
    CMCON=0x07;
    
    void lcdint()
    {
        
    
    
    command(0x38);
    command(0x0e);
    command(0x01);
    }
    return;
            
    
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
