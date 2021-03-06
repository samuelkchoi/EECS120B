/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


enum states {init, press_on, on, press_off} state;
	
void tick();

unsigned char input = 0x00;
unsigned char output = 0x00;

unsigned char a0 = 0x00;
unsigned char b0 = 0x00;
unsigned char a1 = 0x00;
unsigned char b1 = 0x00;


int main(void)
{
	
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;
	
	input = PINA & 0x00;
	
	
    while (1) 
    {
		tick();
		a0 = PINA & 0x01;
		a1 = PINA & 0x02;
    }
	
}

void tick()
{
	switch(state) //Transitions
	{	
		case init:
			if(a0 | a1)
			{
				state = press_on;
			}
			else
			{
				state = init;
			}
			break;
			
		case press_on:
			if(a0 | a1)
			{
				state = press_on;
			}
			else
			{
				state = on;
			}
			break;
			
		case on:
			if(a0 | a1)
			{
				state = press_off;
			}
			else
			{
				state = on;
			}
			break;
			
		case press_off:
			if(a0 | a1)
			{
				state = press_off;
			}
			else
			{
				state = init;
			}
			break;
			
		default:
			state = init;
			break;	
	}
	switch(state) //Actions
	{
		case init:
			b0 = 1;
			b1 = 0;
			output = 0x01;
			PORTB=output;
			break;
		
		case press_on:
			b0 = 0;
			b1 = 1;
			output = 0x02;
			PORTB=output;
			break;
			
		case on:
			b0 = 0;
			b1 = 1;
			output = 0x02;
			PORTB=output;
			break;
			
		case press_off:
			b0 = 1;
			b1 = 0;
			output = 0x01;
			PORTB=output;
			break;
			
		default:
			break;		
	}
}
