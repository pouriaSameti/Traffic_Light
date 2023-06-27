/*
 * traffic light.cpp
 *
 * Created: 6/16/2023 2:16:48 AM
 * Author : acer
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <time.h>
#include <stdio.h>


int conversionA0(){
	
	ADMUX = 0x40;
	ADCSRA |= 0x40;
	
	while(ADCSRA & (1 << ADSC));
	return ADC;
}

int conversionA1(){
	
	_delay_us(2);
	
	ADMUX = 0x41;
	ADCSRA |= 0x40;
	
	while(ADCSRA & (1 << ADSC));
	return ADC;
}

void waitFor(int secs) {
	for (int i=0; i<secs; ++i)
	_delay_ms(1000);
}

int main(void)
{
	
		DDRC = 0xff;
		
		DDRA = 0x00;
		ADCSRA = 0x87;
		ADMUX = 0x40;
		
		int delayHorizental, midDelay, delayVertical;

		while (1)
		{
			
			int value = conversionA0();
			int value2 = conversionA1();
			
			delayHorizental = value * 0.05;
			midDelay = value * 0.008;
			delayVertical = (value * 0.05) * (512 / value2);
			
			PORTC = 0x24;
			waitFor(delayHorizental);
			
			PORTC = 0x22;
			waitFor(midDelay);
			
			PORTC = 0x81;
			waitFor(delayVertical);
			
			PORTC = 0x41;
			waitFor(midDelay);
		}
}
