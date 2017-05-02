/*	Partner(s) Name & E-mail:
 *	Lab Section: 21
 *	Assignment: Lab 2  Exercise 5 
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
	DDRD = 0x00; PORTD = 0xFF; //Configures port D's pins as inputs
	DDRB = 0xFF; PORTB = 0x00; //Configures port B's pins as outputs
    
	unsigned short pas_weight;
	unsigned short weightB;
	unsigned char tempB = 0x00;
	while (1) 
    {
		pas_weight = PIND;
		weightB = PINB & 0x01;
		
		pas_weight = pas_weight + weightB;
		
		if(pas_weight < 5)
		{
			tempB = SetBit(tempB,1,0);
			tempB = SetBit(tempB,2,0);
		}
		else if(pas_weight >= 70)
		{
			tempB = SetBit(tempB,1,1);
			tempB = SetBit(tempB,2,0);
		}
		else
		{
			tempB = SetBit(tempB,1,0);
			tempB = SetBit(tempB,2,1);
		}
		PORTB = tempB;
    }
}

