/*	Partner(s) Name & E-mail: Stanley Okwuoma sokwu001
 *	Lab Section: 22
 *	Assignment: Lab 8 Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

unsigned short my_short, PR_MAX, PR_MIN, PR_RANGE, PR_INCR = 0;
unsigned short PR_MAX = 97;
unsigned short PR_MIN = 39;
unsigned char tempB, INCR_COUNT, SHIFT_COUNT;

//MAX = 97(DEC) //MIN = 39(MIN)

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
	ADC_init();
	INCR_COUNT = 1;
	
	while(1)
	{
		my_short = ADC;
		
		PR_RANGE = PR_MAX - PR_MIN; //Determines the range of values that the photo resistor will operate in
		PR_INCR = PR_RANGE / 8; //Divides up the range into 8 because we will be outputting the ADC with 8 bits
		
		while(INCR_COUNT < 9) //Must do it for < 9 because we only want to account for 8 bits
		{
			if(my_short > PR_MIN + (PR_INCR * INCR_COUNT))
			{
				SHIFT_COUNT++; //Increases the amount to bit shift the output by
			}
			
			INCR_COUNT++; //Increases the count until it hits 8
		}
		
		tempB = 0xFF >> (8 - SHIFT_COUNT); //Takes the shift count taken from the while loop to do the actual bit shift to represent the ADC.
		
		PORTB = tempB;
		INCR_COUNT = 1; //Resets count to start over
		SHIFT_COUNT = 0; //Resets count to start over
	}
}
