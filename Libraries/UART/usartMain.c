#include <util/delay.h>

#include "USART.h"

int main( void )
{
	initUSART();

	while( 1 )
	{
		printString( "Let it be Noted:\n" );
		printString( "At 3:00PM, September 19th 2015, UART was born.\n" );
		printString( "A small step for man, a leap for Senior Design A-Team\n" );
		_delay_ms( 1000 );
	}
} 