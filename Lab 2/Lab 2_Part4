/*	Partner(s) Name & E-mail:
 *	Lab Section: 21
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

// Bit-access function from the lab manual
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Configures port A's pins as inputs
	DDRB = 0xFF; PORTB = 0x00; //Configures port B's pins as outputs
	DDRC = 0xFF; PORTC = 0x00; //Configures port C's pins as outputs
    
	unsigned char tempA;
	unsigned char tempB;
	while (1) 
    {
		tempA = PINA >> 4;
		PORTB = tempA;
		
		tempB = PINA & 0x0F;
		tempB = tempB << 4;
		PORTC = tempB;
    }
}

