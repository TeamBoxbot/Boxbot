#include <avr/io.h>
#include <util/delay.h>

int main( void )
{
  	/* Data Direction Register B: writing a one to the bit enables output. */
  	DDRD |= ( 1 << PORTD7 );

  	/* Event loop */
	while ( 1 )
	{
		/* Toggle PortD7 pin driving LED */
		PORTD ^= ( 1 << PORTD7 );
		/* wait */
		_delay_ms( 400 );

	}
	/* This line is never reached */
	return ( 0 );
}