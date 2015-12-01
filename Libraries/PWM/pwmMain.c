#include <util/delay.h>

#include <avr/interrupt.h>
#include <avr/io.h> 

#include "wheel.h"

int main( void )
{
	initUSART();

	initPWM();

	while ( 1 )	
	{
		printString( "Forward/n" );
		/* Duty Cycle at 30% in the forward direction */
		leftwheel( 30, 1 );
		rightwheel( 30, 1 );
		_delay_ms( 1000 );
		
		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );
		
		printString( "Backwards/n" );
		leftwheel( 30 , -1 );
		rightwheel( 30, -1 );
		_delay_ms( 1000 );	

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );

		printString( "Right/n" );
		leftwheel( 30 , 1 );
		rightwheel( 30, -1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );

		printString( "Left/n" );
		leftwheel( 30, -1 );
		rightwheel( 30, 1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );
		
		printString( "Right Wheel Only/n" );
		leftwheel( 0, 1 );
		rightwheel( 30, 1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );
		
		printString( "Right Wheel Only/n" );
		leftwheel( 0, 1 );
		rightwheel( 30, -1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );
		
		printString( "Left Wheel Only/n" );
		leftwheel( 30, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );

		printString( "Left Wheel Only/n" );
		leftwheel( 30, -1 );
		rightwheel( 0, 1 );
		_delay_ms( 1000 );

		printString( "Stop/n" );
		leftwheel( 0, 1 );
		rightwheel( 0, 1 );
		_delay_ms( 2000 );
	}
}
