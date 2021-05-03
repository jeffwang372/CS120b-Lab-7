/* Author: Jeffrey Wang jwang619@ucr.edu
 * Lab Section: 22
 * Assignment: Lab #7  Exercise #3
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1m7LsuRrRbYAmkP0BMo0SWtQMKo72VWIu/view?usp=sharing
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
	if(ADCresult >= (maxLED/2)) {
		bitsB = 0x01;
	}
	else if (ADCresult < (maxLED/2)) {
		bitsB = 0x00;
	}

	PORTB = bitsB;
       	PORTD = 0x00;	
    }
    return 0;
}
