/*
 * File:   main.c
 * Author: Mohamed NAGY
 *
 * Created on April 12, 2024, 6:17 PM
 */

#define _XTAL_FREQ (8000000)
#include <xc.h>

void main(void) {
    
    // Initialization
    TRISB=0x38;   //00111000
    TRISD=0x0;
    PORTB=0x07;   //00000111
    PORTD=0;
    OPTION_REGbits.nRBPU=0;   // Pull-up resistors in PORTB
    unsigned char num=0;
    
    while(1) {
        // First Row
        PORTB=0x07;
        PORTBbits.RB0=0;
        if(PORTBbits.RB3==0)
            num=1;
        else if(PORTBbits.RB4==0)
            num=2;
        else if(PORTBbits.RB5==0)
            num=3;
        
        // Second Row
        PORTB=0x07;
        PORTBbits.RB1=0;
        if(PORTBbits.RB3==0)
            num=4;
        else if(PORTBbits.RB4==0)
            num=5;
        else if(PORTBbits.RB5==0)
            num=6;
        
        // Third Row
        PORTB=0x07;
        PORTBbits.RB2=0;
        if(PORTBbits.RB3==0)
            num=7;
        else if(PORTBbits.RB4==0)
            num=8;
        else if(PORTBbits.RB5==0)
            num=9;
        
        PORTD=num;
    }
}
