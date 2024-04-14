/*
 * File:   main.c
 * Author: HW
 *
 * Created on April 12, 2024, 4:47 PM
 */

#define _XTAL_FREQ (8000000)
#include <xc.h>

void main(void) {
    //Initialization
    PORTB=0;
    PORTD=0;
    TRISB=0x80;
    TRISD=0;
    OPTION_REGbits.nRBPU=0; //Turn on pull-up resistor
    unsigned char counter=0;
    
    while(1) {
        if(PORTBbits.RB7==0) {
            __delay_ms(10);              // To avoid button debouncing
            if(PORTBbits.RB7==0) {
                counter++;
                while(PORTBbits.RB7==0); // To consider the button press as only one press
            }
        }
        PORTD=counter;
    }
}
