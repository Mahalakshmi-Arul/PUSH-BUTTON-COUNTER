#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <htc.h>
#include <stdio.h>
#include <string.h>
#define rs RC0
#define en RC1
#define sw RC5
void delay()
{
    int i;
    for(i=0;i<5000;i++);
}
void lcdcmd(unsigned char a)
{
    PORTD=a;
    rs=0;
    en=1;
    delay();
    en=0;
}
void lcddata(unsigned char a)
{
    PORTD=a;
    delay();
    rs=1;
    en=1;
    delay();
    en=0;
}
void lcdinit()
{
    lcdcmd(0X38);
    delay();
    lcdcmd(0X0F);
    delay();
    lcdcmd(0X06);
    delay();
    lcdcmd(0X01);
    delay();
}
void lcdprint(const char* str)
{
    while(*str)
    {
        lcddata(*str++);
        delay();
    }
}
void lcdnumber(unsigned int a)
{
    char val[6];
    sprintf(val,"%u",a);
    lcdprint(val);
}
void main(void) {
    TRISD=0;
    TRISC0=0;
    TRISC1=0;
    TRISC5=1;
    
   PORTD=0; 
   PORTC=0;
    
    lcdinit();
    lcdprint("Press Count:");
    lcdcmd(0XC0);
    
    unsigned int count=0;
    char button_pressed = 0;
    
    while(1)
    {
        if(sw==1 && button_pressed==0)
        {
            button_pressed = 1;
            count++;
            lcdcmd(0XC0);
            delay();
            lcdcmd(0X01);
            delay();
            lcdprint("count:");
            delay();
            lcdnumber(count);
            delay();
            
        }
        else if(sw==0)
        {
            button_pressed = 0;
            delay(); 
        }
    }
    
    
}
