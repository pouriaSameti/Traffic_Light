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


int conversionA0(){
	
	ADMUX = 0x40;
	ADCSRA |= 0x40;
	
	while(ADIF == 0);
	
	_delay_us(10);
	int firstPart = (int)ADCL;
	int secondPart = (int)ADCH*256;
	
	int result = secondPart + firstPart;
	return (result);
}

int conversionA1(){
	
	ADMUX = 0x41;
	ADCSRA |= 0x40;
	
	while(ADIF == 0);
	
	_delay_us(10);
	int firstPart = (int)ADCL;
	int secondPart = (int)ADCH*256;
	
	int result = secondPart + firstPart;
	return (result);
}

int main(void)
{
	
	DDRC = 0x01;
	
	DDRA = 0x00;
	ADCSRA = 0x87;
	ADMUX = 0x40;
	
	while (1)
	{

		int value = conversionA0();
		
		if (value > 512)
			PORTC |= 0x01;
		else
			PORTC = 0x00;
	}
}
