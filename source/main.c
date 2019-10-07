/*	Author: mlips001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	unsigned char counter = 0x00;
    /* Insert your solution below */
    while (1) {
	int i = 0;

	unsigned char GetBit (char port, char bit_position) {
	  return ((port >> bit_position) & 0x01);
	}

	for (i = 0; i < 8; ++i) {
	  if (GetBit(PORTA, i)) {
	    counter++;
	  }
 	  PORTC = counter;
	  counter = 0;
	}
	for (i = 0; i < 8; ++i) {
	  if (GetBit(PORTB, i)) {
	    counter++;
	  }
 	  PORTC = counter;
	  counter = 0;
	}
    }
    return 1;
}
