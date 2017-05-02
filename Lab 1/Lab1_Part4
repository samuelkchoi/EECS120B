/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 1  Exercise 4 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;


	unsigned char weightA = 0x00;
	unsigned char weightB = 0x00;
	unsigned char weightC = 0x00;
	unsigned char weight = 0x00;
	
	unsigned char temp = 0x00;
	
	unsigned short totalWeight = 0;
	const unsigned char maxWeight = 140;
	const unsigned char diffWeight = 80;
	
	while(1)
	{
		PORTD = PORTD & 0x00;
		
		weightA = PINA;
		weightB = PINB;
		weightC = PINC;
		
		totalWeight = weightA + weightB + weightC;
		
		if(totalWeight > maxWeight)
		{
			temp = temp | 0x01;
		}
		else
		{
			temp = temp & 0x01;
		}
		
		//Check weight balance
		
		if(weightA > weightC)
		{
			weight = weightA - weightC;
		}
		else if(weightA < weightC)
		{
			weight = weightC - weightA;
		}
		else
		{
			weight = 0;
		}
		
		if(weight > diffWeight)
		{
			temp = temp | 0x02;
		}
		else
		{
			temp =temp & 0x01;
		}
		
		
		temp = temp | ((totalWeight / 50) << 2); // We have 6 bits available 2^6=64 therefore 767/64
		PORTD = temp;
	}
	return 0;
}
