/*	Partner(s) Stanley Okwuoma	sokwu001@ucr.edu:
 *	Lab Section: 022
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

//from zybooks

enum SM_States { SMStart, SM_Init, PRESS_INCR, INCR, PRESS_DECR, DECR, WAIT, RESET } SM_State;

void Tick()
{
	
	unsigned char A0 = ~PINA & 0x01;
	unsigned char A1 = ~PINA & 0x02;
	
	
	switch(SM_State) {   // Transitions
		case SMStart:  // Initial transition
		SM_State = SM_Init;
		break;

		case SM_Init:
		if (A0 && !A1) { 
			
			SM_State = PRESS_INCR;
		}
		else if (A0 && A1) { 
			SM_State = RESET;
		}
		else if (A1 && !A0) {
			SM_State = PRESS_DECR;
		}
		else if (0x00){
			SM_State = SM_Init;
		}
		break;

		case PRESS_INCR:
			SM_State = INCR;
		break;

		case INCR: 
		if (A0 && !A1) { 
			SM_State = INCR;
		}
		else if (!A0) {
			SM_State = WAIT;
		}
		else if (A0 && A1) {
			SM_State = RESET;
		}
		else  {
			SM_State = INCR; 
		}
		break;

		case PRESS_DECR:
			SM_State = DECR;
		break;
		
		case DECR:
		if (A1 && !A0) { 
			SM_State = DECR;
		}
		else if (!A1) {
			SM_State = WAIT;
		}
		else if (A1 && A0) {
			SM_State = RESET;
		}
		else  {
			SM_State = DECR; 
		}
		break;
		
		case WAIT:
		if (!A0 && !A1) { 
			SM_State = WAIT;
		}
		else if (A0 && A1) { 
			SM_State = RESET;
		}
		else if (A0 && !A1) { 
			SM_State = PRESS_INCR;
		}
		else if (A1 && !A0) {
			SM_State = PRESS_DECR;
		}

		else {
			SM_State = WAIT;
		}
		break;
		
		case RESET:
		if (A0 && !A1) { 
			SM_State = PRESS_INCR;
		}
		else if (A1 && !A0) {
			SM_State = PRESS_DECR;
		}
		else { 
			SM_State = RESET;
		}
		break;

		default:
		SM_State = SMStart;
		break;
	} // Transitions

	switch(SM_State) {   // State actions
		case SM_Init:
		PORTB = 7;
		break;
		
		case PRESS_INCR:
		if (PORTB < 9) {
			PORTB = PORTB + 1;
		}
		break;
		
		case INCR:
		break;
		
		case PRESS_DECR:
		if (PORTB > 0) {
			PORTB = PORTB - 1;
		}
		break;
		
		case DECR:
		break;
		
		case WAIT:
		break;
		
		case RESET:
		PORTB = 0;
		break;
		
		default:
		break;
	} // State actions
}

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
	//DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
	
	SM_State = SMStart; // Indicates initial call
	while(1) {
		Tick();
		
	}
}
