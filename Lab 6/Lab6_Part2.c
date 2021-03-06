/*	Partner(s) Name & E-mail: Stanley Okwuoma sokwu001
 *	Lab Section: 22
 *	Assignment: Lab 6 Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "io.c"

volatile unsigned char TimerFlag = 0; 

unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

enum States{init, light0, light1, light2, incr, decr} state;

unsigned char tempB = 0x00;
unsigned char tempA = 0x00;
unsigned char currentscore = 0x00;
unsigned char statecounter = 0x00;

void TimerOn() {
	TCCR1B = 0x0B;
	OCR1A = 125;
	TIMSK1 = 0x02; 
	TCNT1=0;
	_avr_timer_cntcurr = _avr_timer_M;
	SREG |= 0x80;
}

void TimerOff() {
	TCCR1B = 0x00; 
}

void TimerISR() {
	TimerFlag = 1;
}

ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

void tick()
{
	tempA = ~PINA & 0x01;
	switch(state)//Transitions
	{
		case init:
		currentscore = 5;
		LCD_ClearScreen();
		LCD_Cursor(1);
		LCD_WriteData(currentscore + '0');
		state = light0;
		break;
		
		case light0:
		if(tempA)
		{
			state = decr;
			break;
		}
		else
		{
			statecounter = 0;
			state = light1;
			break;
		}
		break;
		
		case light1:
		if(tempA)
		{
			state = incr;
			break;
		}
		else
		{
			statecounter = 0;
			state = light2;
			break;
		}
		break;
		
		case light2:
		if(tempA)
		{
			state = decr;
			break;
		}
		else
		{
			statecounter = 0;
			state = light0;
			break;
		}
		break;
		
		case incr:
		if(currentscore < 8)
		{
			currentscore++;
			LCD_Cursor(1);
			LCD_WriteData(currentscore + '0');
			state = light0;
			break;
		}
		else
		{
			if(tempA)
			{
				state = init;
				break;
			}
			else
			{
				LCD_DisplayString(1, "Winner!");
				state = incr;
				break;
			}
		}
		break;
		
		case decr:
		if(currentscore > 0)
		{
			currentscore--;
			LCD_Cursor(1);
			LCD_WriteData(currentscore + '0');
			state = light0;
			break;
		}
		else
		{
			LCD_Cursor(1);
			LCD_WriteData(currentscore + '0');
			state = light0;
			break;
		}
		break;
		
		default:
		state = init;
		break;
	}
	
	switch(state)//Actions
	{
		case init:
		break;
		
		case light0:
		statecounter++;
		tempB = 0x01;
		PORTB = tempB;
		break;
	
		case light1:
		statecounter++;
		tempB = 0x02;
		PORTB = tempB;
		break;
		
		case light2:
		statecounter++;
		tempB = 0x04;
		PORTB = tempB;
		break;
		
		case incr:
		break;
		
		case decr:
		break;
		
	}
	PORTB = tempB;
}
void main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00; 
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	TimerSet(300);
	TimerOn();
	LCD_init();
	
	state = init;
	while(1)
	{
		tick();
		while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;
	}
}

