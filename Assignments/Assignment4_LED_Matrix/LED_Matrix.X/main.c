/*
 * File:   main.c
 * Author: Mohamed Nagy
 *
 * Created on April 12, 2024, 7:16 PM
 */

#define _XTAL_FREQ (8000000)
#include <xc.h>

void main(void) {
    
    // Initialization
    TRISB=0;
    PORTB=0;
    OPTION_REGbits.nRBPU=0; //Pull-up resistor in PORTB
    unsigned char sequence[8]={14,22,38,37,35,19,11,13};
    
    while(1) {
        for(int i=0;i<8;i++) {
            PORTB=sequence[i];
            __delay_ms(500);
        }
    } 
}
