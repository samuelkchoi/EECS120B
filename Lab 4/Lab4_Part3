/*	Partner(s) Stanley Okwuoma	sokwu001@ucr.edu:
 *	Lab Section: 022
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum states {init, state1, state2, state3, state4, wait1, wait2, wait3, wait4} state;

unsigned char tempA;
unsigned char tempB = 0x00;
unsigned char counter = 0x00;

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Configures port A's pins as inputs
	DDRB = 0xFF; PORTB = 0x00; //Configures port C's pins as outputs
     
	 state = init;
	while (1) 
	{	
		tempA = ~PINA & 0x01;
		tick();
	}
}

void tick()
{
	switch(state)//Transitions
	{
		case init:
		if(tempA)
		{
			state = wait1;
			break;
		}
		else
		{
			state = init;
		}
		break;
		
		
		case state1:
		if(tempA)
		{
			state = wait1;
		}
		else
		{
			state = state1;
		}
		break;
		
		case state2:
		if(tempA)
		{
			state = wait2;
		}
		else
		{
			state = state2;
		}
		break;
		
		case state3:
		if(tempA)
		{
			state = wait3;
		}
		else
		{
			state = state3;
		}
		break;
		
		case state4:
		if(tempA)
		{
			state = wait4;
		}
		else
		{
			state = state4;
		}
		break;
		
		case wait1:
		break;
		
		case wait2:
		break;
		
		case wait3:
		break;
		
		case wait4:
		break;
	}
	
	switch(state)//Actions
	{
		case init:
		break;
	
		case state1:
		tempB = 0x3F;
		break;
	
		case state2:
		tempB = 0x1E;
		break;
	
		case state3:
		tempB = 0x0C;
		break;
	
		case state4:
		tempB = 0x00;
		break;
	
		case wait1:
		if(!tempA)
		{
			state = state2;
		}
		else
		{
			state = wait1;
		}
		break;
	
		case wait2:
		if(!tempA)
		{
			state = state3;
		}
		else
		{
			state = wait2;
		}
		break;
	
		case wait3:
		if(!tempA)
		{
			state = state4;
		}
		else
		{
			state = wait3;
		}
		break;
	
		case wait4:
		if(!tempA)
		{
			state = state1;
		}
		else
		{
			state = wait4;
		}
		break;
	}
	PORTB = tempB;
}
