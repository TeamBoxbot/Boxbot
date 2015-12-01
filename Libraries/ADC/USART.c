/*****************************************************************************************
  Quick and dirty functions that make serial communications work.

  Note that receiveByte() blocks -- it sits and waits _forever_ for
   a byte to come in.  If you're doing anything that's more interesting,
   you'll want to implement this with interrupts.

   initUSART requires BAUDRATE to be defined in order to calculate
     the bit-rate multiplier.  9600 is default and the correct baudrate.
*****************************************************************************************/

#include <avr/io.h>

#include <USART.h>

void initUSART() 
{                                
	/* Set Baud Rate */
	UBRR0L = 0x33;

	/* Enable receiver and transmitter */
	UCSR0B = ( 1 << RXEN0 ) | ( 1 << TXEN0 );

	/* set frame format: 8data, 2 stop bit */
	UCSR0C = ( 1 << UCSZ00 ) | ( 1 << UCSZ01 );
	printString( "UART Initialized.\n\n" );
}

void transmitByte( uint8_t data ) 
{
	/* Wait for empty transmit buffer */
  	while( ! ( UCSR0A & ( 1 << UDRE0 ) ) );
  	
  	/* send data */
  	UDR0 = data;
}

uint8_t receiveByte( void ) 
{
	/* Wait for incoming data */
	while( ! ( UCSR0A & ( 1 << RXC0 ) ) );

	/* return register value */
	return UDR0;
}


/********** Here are a bunch of useful printing commands *************/
void printString( const char myString[] ) 
{
	uint8_t i = 0;
	while ( myString[ i ] ) 
  	{
		transmitByte( myString[ i ] );
		i++;
	}
}

void readString( char myString[], uint8_t maxLength ) 
{
  	char response;
  	uint8_t i;
  	i = 0;
  	while ( i < ( maxLength - 1 ) ) 
  	{
  		/* prevent over-runs */
    	response = receiveByte();
    	/* echo */
    	transmitByte(response);
    	if ( response == '\r' ) 
		{
			/* enter marks the end */
      		break;
    	}
    	else
    	{
    		/* add in a letter */
      		myString[ i ] = response;
      		i++;
    	}
  	}
  	/* terminal NULL character */
  	myString[ i ] = 0;
}

void printByte( uint8_t byte ) 
{
   /* Converts a byte to a string of decimal text, sends it */
  	transmitByte( '0' + ( byte / 100 ) );			/* Hundreds */
  	transmitByte( '0' + ( ( byte / 10) % 10 ) );	/* Tens */
  	transmitByte( '0' + ( byte % 10 ) );			/* Ones */
}

void printWord(uint16_t word) 
{
  	transmitByte( '0' + ( word / 10000 ) );         /* Ten-thousands */
  	transmitByte( '0' + ( ( word / 1000) % 10 ) );  /* Thousands */
  	transmitByte( '0' + ( ( word / 100 ) % 10 ) );  /* Hundreds */
  	transmitByte( '0' + ( ( word / 10 ) % 10 ) );   /* Tens */
  	transmitByte( '0' + ( word % 10 ) );            /* Ones */
}

void printBinaryByte(uint8_t byte) 
{
    /* Prints out a byte as a series of 1's and 0's */
  	uint8_t bit;
  	for ( bit = 7; bit < 255; bit-- )
  	{
    	if ( bit_is_set( byte, bit ) )
    	{
      		transmitByte( '1' );
      	}
    	else
    	{
      		transmitByte( '0' );
      	}
  	}
}

char nibbleToHexCharacter( uint8_t nibble ) 
{
    /* Converts 4 bits into hexadecimal */
  	if ( nibble < 10 )
  	{
    	return ( '0' + nibble );
  	}
  	else
  	{
    	return ( 'A' + nibble - 10 );
  	}
}

void printHexByte( uint8_t byte ) 
{
    /* Prints a byte as its hexadecimal equivalent */
  	uint8_t nibble;
  	nibble = ( byte & 0b11110000 ) >> 4;
  	transmitByte( nibbleToHexCharacter( nibble ) );
  	nibble = byte & 0b00001111;
  	transmitByte( nibbleToHexCharacter( nibble ) );
}

uint8_t getNumber( void ) 
{
  	/* Gets a numerical 0-255 from the serial port. */
  	/* Converts from string to number. */
	char hundreds = '0';
  	char tens = '0';
  	char ones = '0';
  	char thisChar = '0';
  	do
  	{
  		/* shift over */
    	hundreds = tens;
    	tens = ones;
    	ones = thisChar;
    	/* get a new character */
    	thisChar = receiveByte();
    	/* echo */
    	transmitByte( thisChar );
  	} while ( thisChar != '\r' );		/* until type return */
  	return ( 100 * (hundreds - '0' ) + 10 * ( tens - '0' ) + ones - '0' );
}
