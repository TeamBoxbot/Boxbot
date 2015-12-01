#include <avr/io.h>

#include "USART.h"

/* init ADC MUX = 0000 by default */
void initADC(void);

/* Specify which ADC channel to read from, 0-7. */
uint16_t readADC( uint8_t channel );