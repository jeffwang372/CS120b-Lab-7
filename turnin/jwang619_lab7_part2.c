/* Author: Jeffrey Wang jwang619@ucr.edu
 * Lab Section: 22
 * Assignment: Lab #7  Exercise #2
 * Exercise Description: [optional - include for your own benefit]
 * EXPLANATION FOR MAX AND MIN: I found the max by shining a flashlight on it, and I found the min by covering it with my hand.
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1m3qDyr3CDTDJUFZqYOkUsSkBruwtyfUU/view?usp=sharing
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
		
    while (1) {
	unsigned short ADCresult = ADC;
	unsigned char bitsB = (char)ADCresult;
	unsigned char bitsD = (char)(ADCresult >> 8);

	PORTB = bitsB;
       	PORTD = bitsD;	
    }
    return 0;
}
