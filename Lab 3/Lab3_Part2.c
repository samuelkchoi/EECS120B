/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 3  Exercise 2 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


enum states {init, add, subtract, reset, wait1, wait2} state;

void tick();

unsigned char A0 = 0x00;
unsigned char A1 = 0x00;

unsigned char count = 0x00;
unsigned char i = 0x01;


int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;
	
    while (1) 
    {
		A0 = PINA & 0x01;
		A1 = PINA & 0x02;
		tick();
    }
	
}

void tick()
{
	switch(state)//Transitions
	{
		case init:
			if(i == 1)
			{
				state = init;
			}
			else
			{
				state = wait1;
			}
		break;
		
		case wait1:
		if(A0 && A1)
		{
			state = reset;
		}
		else if(A0 && !A1)
		{
			state = add;
		}
		else if(!A0 && A1)
		{
			state = subtract;
		}
		else
		{
			state = wait1;
		}
		break;
		
		case wait2:
		if(!A0 && !A1)
		{
			i = 0;
			state = wait1;
		}
		else
		{
			state = wait2;
		}
		break;
		
		case add:
		i = 1;
		state = wait2;
		break;
		
		case subtract:
		i = 1;
		state = wait2;
		break;
		
		case reset:
		i = 1;
		state = wait2;
		break;
		
		default:
		state = init;
		break;
		
	}
	switch(state)//Actions
	{
		case init:
		i = 0;
		count = 0x07;
		PORTB = count;
		break;
		
		case add:
		if(count <= 9)
		{
			count++;
			PORTB = count;
		}
		break;
		
		case subtract:
		if(count >= 0)
		{
			count--;
			PORTB = count;
		}
		break;
		
		case reset:
		count = 0;
		PORTB = count;
		break;
		
		default:
		break;
	}
	
}
