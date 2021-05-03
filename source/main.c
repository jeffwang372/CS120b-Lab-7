/* Author: Jeffrey Wang jwang619@ucr.edu
 * Lab Section: 22
 * Assignment: Lab #7  Exercise #4
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1mE8NMgWBqmvz8SJL_cUvQ0cSrH4L6sSk/view?usp=sharing
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
        DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
	unsigned short maxLED = 455;
		
    while (1) {
	unsigned short ADCresult = ADC;
	unsigned char bitsB = 0x00;
	if(ADCresult >= 0 && ADCresult < (maxLED/8)) {
		bitsB = 0x01;
	}
	else if(ADCresult >= (maxLED/8) && ADCresult < 2*(maxLED/8)) {
                bitsB = 0x03;
        }
	else if(ADCresult >= 2*(maxLED/8) && ADCresult < 3*(maxLED/8)) {
                bitsB = 0x07;
        }
	else if(ADCresult >= 3*(maxLED/8) && ADCresult < 4*(maxLED/8)) {
                bitsB = 0x0F;
        }
	else if(ADCresult >= 4*(maxLED/8) && ADCresult < 5*(maxLED/8)) {
                bitsB = 0x1F;
        }
	else if(ADCresult >= 5*(maxLED/8) && ADCresult < 6*(maxLED/8)) {
                bitsB = 0x3F;
        }
	else if(ADCresult >= 6*(maxLED/8) && ADCresult < 7*(maxLED/8)) {
                bitsB = 0x7F;
        }
	else if(ADCresult >= 7*(maxLED/8)) {
                bitsB = 0xFF;
        }
	

	PORTB = bitsB;
       	PORTD = 0x00;	
    }
    return 0;
}
