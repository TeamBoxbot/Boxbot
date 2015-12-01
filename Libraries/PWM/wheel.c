#include "wheel.h"

void initPWM( void )
{

	/* Set Initial Duty Cycle to zero. */
	OCR0A = 0;
	OCR0B = 0;
	
	/* Fast PWM mode 8-bit, PWM output on OCR0A and OCR0B */
	/* setting PWM frequency (PRESCALER TO 256) */
    TCCR0A = ( 1 << WGM00 ) | ( 1 << WGM01 ) | ( 1 << COM0A1 ) | ( 1 << COM0B1 ); 
	TCCR0B = ( 1 << CS02 ); 

	/* Setting Directional Pins to Output. */
	DDRC = 0x0F;

	/* Setting PWM Pins to Output */
	DDRB = ( 1 << PORTB3 ) | ( 1 << PORTB4 );
	
	printString("PWM initialized\n");
}

void rightwheel( float duty, int direc ) 
{
	/*Safety catch to ensure duty cycle is between 0 and 100*/
	if( duty > 100 || duty < 0 )
	{
		printString( "\nDutycycle out of bounds. Must be between 0 and 100\n" );
		return;
	}
	
	/* Calculate input dutycycle value to corresponding 0-255 in compare register */
	int a = ( ( float )duty/100 )*255; 
	OCR0B= a; 

	/* FORWARD */
	if ( direc == 1 )  	
	{
		PORTC &= ~( 0x03 );
		PORTC |= 0x01; 
	}
	
	/* REVERSE */
	else if ( direc == -1 ) 
	{
		PORTC &= ~( 0x03 );
		PORTC |= 0x02;
	}
}

void leftwheel( float duty, int direc ) 
{
	/* Safety catch to ensure duty cycle is between 0 and 100 */
	if( duty > 100 || duty < 0 )
	{
		printString( "\nDutycycle out of bounds. Must be between 0 and 100\n" );
		return;
	}
	/* Calculate input dutycycle value to corresponding 0-255 in compare register */
	float a = ( ( float )duty/100 )*255;
	OCR0A= a;

	/* FORWARD */
	if ( direc == 1 ) 
	{
		PORTC &= ~( 0x0C );
		PORTC |= 0x04;
	}
	
	/* BACKWARD */
	else if ( direc == -1 ) 	
	{
		PORTC &= ~( 0x0C );
		PORTC |= 0x08; 
	}	
}