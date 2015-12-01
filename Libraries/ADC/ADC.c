#include "ADC.h"

void initADC( void )
{
	/* reference voltage on AVCC. ADC defaults to channel 0 */
	ADMUX |= (1 << REFS0);

	/* ADC clock prescaler /16 */
	ADCSRA |= (1 << ADPS2);

	 /* enable ADC */
	ADCSRA |= (1 << ADEN);

	printString("ADC initialized.\n\n");
}

uint16_t readADC( uint8_t channel )
{
	ADMUX = ( 0xF0 & ADMUX ) | channel;
	ADCSRA |= ( 1 << ADSC );
	loop_until_bit_is_clear( ADCSRA, ADSC );
	return ( ADC );
}