/*	Partner(s) Name & E-mail:
 *	Lab Section: 21
 *	Assignment: Lab 2  Exercise 1 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
// Bit-access function given to us from the lab manual
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTA = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0xFF; PORTA = 0x00; // Configure port C's 8 pins as outputs
	unsigned char ones_count = 0x00;
	unsigned char counter = 0x00;
	while (1) 
    {
		while(counter < 8) //The register has 8 bits so thats all we need
		{
			if (GetBit(PINA,counter))
			{
				ones_count = ones_count + 1;
			}
			if (GetBit(PINB,counter))
			{
				ones_count = ones_count + 1;
			}
			counter++;
		}
		PORTC = ones_count;
		ones_count = 0x00;
		counter = 0x00;
    }
}

