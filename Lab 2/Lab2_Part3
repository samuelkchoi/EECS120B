/*	Partner(s) Name & E-mail:
 *	Lab Section: 21
 *	Assignment: Lab 2  Exercise 3 
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
	DDRC = 0xFF; PORTC = 0x00; //Configures port C's pins as outputs
    
	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
while (1) 
    {	
		tempA = PINA & 0x0F;
		if(tempA > 0)
		{
			tempC = SetBit(tempC,5,1);
		}
		else
		{
			tempC = SetBit(tempC,5,0);
		}
		if(tempA > 2)
		{
			tempC = SetBit(tempC,4,1);
		}
		else
		{
			tempC = SetBit(tempC,4,0);
		}
		if(tempA > 4)
		{
			tempC = SetBit(tempC,3,1);
			tempC = SetBit(tempC,6,0);
		}
		else
		{
			tempC = SetBit(tempC,3,0);
		}
		if(tempA > 6)
		{	
			tempC = SetBit(tempC,2,1);
			tempC = SetBit(tempC,6,0);
		}
		else
		{
			tempC = SetBit(tempC,2,0);
		}
		if(tempA > 9)
		{
			tempC = SetBit(tempC,1,1);
			tempC = SetBit(tempC,6,0);
		}
		else
		{
			tempC = SetBit(tempC,1,0);
		}
		if(tempA > 12)
		{
			tempC = SetBit(tempC,0,1);
			tempC = SetBit(tempC,6,0);
		}
		else
		{
			tempC = SetBit(tempC,0,0);
		}
		if(tempA <= 4) //Turns the low fuel light on
		{
			tempC = SetBit(tempC,6,1);
		}
		else
		{
			tempC = SetBit(tempC,6,0);
		}
		//Checks to see if the key is inginition, the driver is seated, and if the seatbelt is not fasteneds
		if(GetBit(PINA,4) && GetBit(PINA,5) && !GetBit(PINA,6))
		{
			tempC = SetBit(tempC,7,1);
		}
		else
		{
			tempC = SetBit(tempC,7,0);
		}
		PORTC = tempC;
    }
}

