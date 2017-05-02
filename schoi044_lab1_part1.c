/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 1  Exercise 1 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
	// Initialize output on PORTB to 0x00
	unsigned char temp_PA0;
	unsigned char temp_PA1;
	unsigned char temp_PB0;
	while(1)
	{
		temp_PA0 = PINA & 0x01;
		temp_PA1 = PINA & 0x02;
		temp_PB0 = PORTB & 0x01;
		
		if(temp_PA0 && !temp_PA1)
		{
			temp_PB0 = (temp_PB0 & 0xFC) | 0x01;
		}
		else
		{
			temp_PB0 = (temp_PB0 & 0xFC) | 0x00;
		}
		PORTB = temp_PB0;
	}
	return 0;
}
