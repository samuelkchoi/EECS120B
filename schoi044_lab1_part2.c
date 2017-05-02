/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 1  Exercise 2 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 9 pins as outputs
	
	while(1)
	{
		int i;
		unsigned char tempA = PINA;
		unsigned char cntavail = 0x00;
		for(i = 0; i < 4; i++)
		{
			if((tempA>>i) & 0x01)
			{
				cntavail = cntavail + 1;
			}
		}
		PORTC = 4 - cntavail;
	}
}