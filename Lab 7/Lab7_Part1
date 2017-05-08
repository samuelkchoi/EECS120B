/*	Partner(s) Name & E-mail: Stanley Okwuoma sokwu001
 *	Lab Section: 22
 *	Assignment: Lab 7 Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
//#include "io.c"
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0;

unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

unsigned char tempB = 0x00;
unsigned char tempA = 0x00;

unsigned char A0 = 0x00; //button 1
unsigned char A1 = 0x00; //button 2

const unsigned char firstLED = 0x01; 
const unsigned char secondLED = 0x02; 
const unsigned char thirdLED = 0x04;
const unsigned char fourthLED = 0x08;

unsigned char threeLEDs = 0x00;
unsigned char blinkingLEDs = 0x00;

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

void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

typedef struct task {
	int state; // Current state of the task
	unsigned long period; // Rate at which the task should tick
	unsigned long elapsedTime; // Time since task's previous tick
	int (*TickFct)(int); // Function to call for task's tick
} task;

task tasks[3];

const unsigned char tasksNum = 3;
const unsigned long tasksPeriodGCD = 1;
const unsigned long periodBlinkLED = 1000;
const unsigned long periodThreeLEDs = 1000;
const unsigned long periodCombineLEDs = 1000;

enum BL_States { BL_SMStart, BL_s1 };
int TickFct_BlinkLED(int state);

int TickFct_ThreeLEDs(int state);
enum TL_States { TL_SMStart, TL_s1, TL_s2, TL_s3 };
	
int TickFct_CombineLEDs(int state);	
enum CL_States { CL_SMStart, CL_s1 };

void TimerISR() {
	unsigned char i;
	for (i = 0; i < tasksNum; ++i) { // Heart of the scheduler code
		if ( tasks[i].elapsedTime >= tasks[i].period ) { // Ready
			tasks[i].state = tasks[i].TickFct(tasks[i].state);
			tasks[i].elapsedTime = 0;
		}
		tasks[i].elapsedTime += tasksPeriodGCD;
	}
}

ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--;
	if (_avr_timer_cntcurr == 0) {
		TimerISR();
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

int TickFct_BlinkLED(int state) {
		A0 = ~PINA & 0x01;
		A1 = ~PINA & 0x02;

	switch(state) { // Transitions
		case BL_SMStart: // Initial transition
		blinkingLEDs = 0; // Initialization behavior
		state = BL_s1;
		break;
		
		case BL_s1:
		blinkingLEDs = 8;
		//blinkingLEDs = !blinkingLEDs; // for some reason, doing it this way and staying at this state and just toggling on/off over and over did not work, so
		//instead, I just hardcode the desired value and set the next state to BL_Start in order to go between on and off in 2 states as opposed to 1 state.
		state = BL_SMStart;
		break;

		default:
		state = BL_SMStart;
	} // Transitions

	switch(state) { // State actions
		case BL_s1:
		//blinkingLEDs = !blinkingLEDs; //on for 1 sec, then off for one sec
		break;
		
		default:
		break;
	} // State actions
	return state;
}

int TickFct_ThreeLEDs(int state) {
		A0 = ~PINA & 0x01;
		A1 = ~PINA & 0x02;

	switch(state) { // Transitions
		case TL_SMStart: // Initial transition
		state = TL_s1;
		break;
		
		case TL_s1:
		state = TL_s2;
		break;
		
		case TL_s2:
		state = TL_s3;
		break;
		
		case TL_s3:
		state = TL_s1;
		break;
		
		default:
		state = TL_SMStart;
	} // Transitions

	switch(state) { // State actions
		//setting outputs to shared variable so that the encompassing state does it,rather
		case TL_s1:
		threeLEDs = firstLED;
		//B2 = 1; B3 = 0; B4 = 0;
		break;
		
		case TL_s2:
		threeLEDs = secondLED;
		//B2 = 0; B3 = 1; B4 = 0;
		break;
		
		case TL_s3:
		threeLEDs = thirdLED;
		//B2 = 0; B3 = 0; B4 = 1;
		break;
		
		default:
		break;
	} // State actions
	return state;
}

int TickFct_CombineLEDs(int state) {
	A0 = ~PINA & 0x01;
	A1 = ~PINA & 0x02;

	switch(state) { // Transitions
		case CL_SMStart: // Initial transition
		state = CL_s1;
		break;
		
		case CL_s1:
		state = CL_s1;
		break;
		
		default:
		state = CL_SMStart;
	} // Transitions

	switch(state) { // State actions
		case CL_s1:
		PORTB = (blinkingLEDs & 0x08) | (threeLEDs & 0x07);
		break;
		
		default:
		break;
	} // State actions
	return state;
}

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs,
	
	task BL_task;
	task TL_task;
	//init array of tasks
	unsigned char i=0;
	tasks[i].state = BL_SMStart;
	tasks[i].period = periodBlinkLED;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &TickFct_BlinkLED;
	++i;
	tasks[i].state = TL_SMStart;
	tasks[i].period = periodThreeLEDs;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &TickFct_ThreeLEDs;
	++i;
	tasks[i].state = CL_SMStart;
	tasks[i].period = periodCombineLEDs;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &TickFct_CombineLEDs;

	TimerSet(tasksPeriodGCD);
	TimerOn();
	
	while(1)
	{
		
	}
}
