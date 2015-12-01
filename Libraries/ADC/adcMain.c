#include <stdlib.h>
#include <util/delay.h>

#include "USART.h"
#include "ADC.h"

int main( void ) 
{
	/* Inits */
	char buffer0[ 5 ];
	char buffer1[ 5 ];
	uint16_t adcValue0 = 0;
	uint16_t adcValue1 = 0;


	initUSART();

	initADC();

  	/* Event loop */
	while (1) 
	{
		/* Using ADC Channel 0 */
		adcValue0 = readADC( 0 );

		/* Conver 10-bit uint16_t adcValue to ASCII and store in buffer */
		itoa( adcValue0, buffer0, 10 );

		printString( "ADC Channel 0: " );
		printString( buffer0 );
		printString( "\n" );
		
		/* Using ADC Channel 1 */
		adcValue1 = readADC( 1 );

		/* Conver 10-bit uint16_t adcValue to ASCII and store in buffer */
		itoa( adcValue1, buffer1, 10 );

		printString("ADC Channel 1: ");
		printString( buffer1 );
		printString( "\n\n" );

		_delay_ms( 500 );
	}
}