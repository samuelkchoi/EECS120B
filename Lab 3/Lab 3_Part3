/*	Partner(s) Taylor Che [tche001@ucr.edu]:
 *	Lab Section: 22
 *	Assignment: Lab 3  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


enum states {init, locked, state_x, state_y, state_pound, wait1, wait2, unlocked} state;

void tick();

unsigned char A0 = 0x00;
unsigned char A1 = 0x00;
unsigned char A2 = 0x00;
unsigned char A7 = 0x00;

unsigned char i = 0x01; //initial activation
unsigned char pass = 0x00;
unsigned char tempY_VAR = 0x00; //Y
unsigned char tempY_MAIN = 0x00; //Y
unsigned char tempP_VAR = 0x00; //Pound
unsigned char tempP_MAIN = 0x00; //Pound
unsigned char lock_status = 0x00; //Lock
unsigned char state_num = 0x00;

int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;
	DDRC = 0xFF; PINC = 0x00;
	DDRC = 0xFF; PINC = 0x00;
	
	PORTD = 0x01; //i = 1
	
    while (1) 
    {
		A0 = PINA & 0x01;
		A1 = PINA & 0x02;
		A2 = PINA & 0x04;
		A7 = PINA & 0x80;
		
		tempP_MAIN = tempP_VAR;
		tempY_MAIN = tempY_VAR;
		
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
				break;
			}
			else
			{
				state = wait1;
				break;
			}
		break;
		
		case locked:
			if(A7)
			{
				state = locked;
				break;
			}
			else
			{
				state = wait2;
				break;
			}
		break;
		
		case wait2:
			
			if(!A7 && !A0 && !A1 && !A2)
			{
				state = wait1;
				break;
			}
			else
			{
				state = wait2;
				break;
			}
		break;
			
		case wait1:
			if(pass)
			{
				state = unlocked;
				break;
			}
			
			if(A0)
			{
				state = state_x;
				break;
			}
			else if(A1)
			{
				state = state_y;
				break;
			}
			else if(A2)
			{
				state = state_pound;
				break;
			}
			else if(A7)
			{
				state = locked;
				break;
			}
			else
			{
				state = wait1;
				break;
			}
		break;
		
		case state_x:
			state = wait2;
		break;
		
		case state_y:
			state = wait2;
		break;
		
		case state_pound:
			state = wait2;
		break;
		
		case unlocked:
			state = wait2;
		break;
		
		//Default
		default:
		state = init;
		break;
		
	}
	switch(state)//Actions
	{
		case init:
		i = 0;
		
		PORTD = 0x00; //i = 0
		
		lock_status = 0x01;
		PORTB = lock_status;
		
		state_num = 0x01;
		PORTC = state_num;
		break;
		
		case locked:
			lock_status = 0x00;
			tempP_VAR = 0x00;
			
			PORTD = 0x00; //P=0
			
			tempY_VAR = 0x00;
			
			PORTD = 0x00; //Y=0
			
			PORTB = lock_status;
			
			state_num = 0x02;
		PORTC = state_num;
		break;
		
		case wait1:
		state_num = 0x04;
		PORTC = state_num;
		break;
		
		case wait2:
		state_num = 0x08;
		PORTC = state_num;
		break;
		
		case state_x:
			tempP_VAR = 0;
			
			PORTD = 0x00; //i = 0
		
		state_num = 0x10;
		PORTC = state_num;
		break;
		
		case state_y:
			if(tempP_MAIN)
			{
				PORTC = 0xFF;
				
				pass = 1;
				
				PORTD = 0x10; //i = 0
				
				tempY_VAR = 1;
				
				PORTD = 0x04; //i = 0
				
			}
			else
			{
				tempP_VAR = 0;
				
				PORTD = 0x00; //i = 0
				
				tempY_VAR = 0;
				
				PORTD = 0x00; //i = 0
			}
		state_num = 0x20;
		PORTC = state_num;
		break;
		
		case state_pound:
			tempP_VAR = 1;
			
			PORTD = 0x08; //i = 0
			
		state_num = 0x40;
		PORTC = state_num;
		break;
		
		case unlocked:
		pass = 0;
		tempP_VAR = 0;
		tempY_VAR = 0;
		lock_status = 0x01;
		PORTB = lock_status;
		state_num = 0x80;
		PORTC = state_num;
		break;
		
		//Default
		default:
		break;
	}
	
}
