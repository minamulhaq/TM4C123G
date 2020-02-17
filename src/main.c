#include "lm4f120h5qr.h"

int main() {
    SYSCTL_RCGCGPIO_R = 0x20U;  /* enable clock for GPIOF */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0xff;
    GPIO_PORTF_DIR_R = 0x0EU; // set pins 1,2, and 3 as outputs
    GPIO_PORTF_PUR_R |= 0x10;
    GPIO_PORTF_DEN_R = 0x1FU;

    GPIO_PORTF_DATA_R = 0x00;
    
    while (1)
    {


        switch ( GPIO_PORTF_DATA_R & 0x10)
        {
        case 0x00:
            // GPIO_PORTF_DATA_R = (1<<3);
            // (*((volatile unsigned long *)0x400253FC))= (1<<3);
            (*((volatile unsigned long *)0x400253FC))= (1<<3);
            break;
        case 0x10:
            GPIO_PORTF_DATA_R = (1<<1);
            break;
        
        }
    }
    
    return 0;
}