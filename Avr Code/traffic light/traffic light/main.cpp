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
	
}
