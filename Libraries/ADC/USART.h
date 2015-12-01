#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/* if not defined in Makefile... */
/* set a safe default baud rate */
#ifndef BAUD
#define BAUD 9600
#endif

/* These are defined for convenience */
#define   USART_HAS_DATA   bit_is_set(UCSR0A, RXC0)
#define   USART_READY      bit_is_set(UCSR0A, UDRE0)

/*****************************************************************************************
initUSART - 	Takes the defined BAUD and F_CPU,
   				calculates the bit-clock multiplier,
   				and configures the hardware USART
*****************************************************************************************/
void initUSART();

/*****************************************************************************************
transmitByte - 	Blocking transmit and receive functions.
   				When you call receiveByte() your program will hang until
   				data comes through.
*****************************************************************************************/
void transmitByte( uint8_t data );

uint8_t receiveByte( void );

/*****************************************************************************************
printString -	Utility function to transmit an entire string from RAM
*****************************************************************************************/
void printString( const char myString[] );

/*****************************************************************************************
readString  -	Define a string variable and pass it to this function.
   				The string will contain whatever you typed over serial
*****************************************************************************************/
void readString(char myString[], uint8_t maxLength);

/*****************************************************************************************
printByte  -	Prints a byte out as its 3-digit ascii equivalent.
*****************************************************************************************/
void printByte(uint8_t byte);

/*****************************************************************************************
printWord  -	Prints a word (16-bits) out as its 5-digit ascii equivalent.
*****************************************************************************************/
void printWord(uint16_t word);

/*****************************************************************************************
printBinaryByte - Prints a byte out in 1s and 0s.
*****************************************************************************************/
void printBinaryByte(uint8_t byte);

char nibbleToHex(uint8_t nibble);

/*****************************************************************************************
printHexByte  -	Prints a byte out in hexadecimal.
*****************************************************************************************/
void printHexByte(uint8_t byte);


/*****************************************************************************************
getNumber  -	Takes in up to three ascii digits,
				converts them to a byte when press enter.
*****************************************************************************************/
uint8_t getNumber(void);