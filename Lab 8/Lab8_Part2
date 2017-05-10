/*	Partner(s) Name & E-mail: Stanley Okwuoma sokwu001
 *	Lab Section: 22
 *	Assignment: Lab 8 Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

unsigned short my_short = 0;
unsigned char tempB, tempD;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	// in Free Running Mode, a new conversion will trigger whenever
	// the previous conversion completes.
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	while(1)
	{
		my_short = ADC;
		tempB = my_short;
		tempD = my_short >> 8;
		PORTB = tempB;
		PORTD = tempD;
	}
}
