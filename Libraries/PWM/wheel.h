#include <avr/io.h>

#include "USART.h"

/*****************************************************************************************
initPWM -  	Initialize PWM using timer0 compare registers A and B
			Initial dutycycle set to 0
			PORTC 0-3 used to control direction via H-bridge 
			PORTD 3&4 used as PWM output to wheels
*****************************************************************************************/
void initPWM( void );

/*****************************************************************************************
rightwheel -	input "duty" must be between 0 and 100 as it represents a percentage
				input "direc" must be either -1 or 1 as it represents direction
				-1 = reverse
		 		1 = forward
*****************************************************************************************/
void rightwheel( float duty, int direc );

/*****************************************************************************************
leftwheel -		input "duty" must be between 0 and 100 as it represents a percentage
				input "direc" must be either -1 or 1 as it represents direction
				-1 = reverse
				1 = forward
*****************************************************************************************/
void leftwheel( float duty, int direc );