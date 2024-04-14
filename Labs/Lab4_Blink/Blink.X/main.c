/*
 * File:   main.c
 * Author: Mohamed Nagy
 *
 * Created on April 12, 2024, 9:34 AM
 */

#define _XTAL_FREQ 8000000
#include <xc.h>

void main(void) {
    
    TRISB=0;
    
    while(1){
        PORTBbits.RB0=0x1;
        __delay_ms(1000);
        PORTBbits.RB0=0x0;
        __delay_ms(1000);
    }
    
    return;
}
