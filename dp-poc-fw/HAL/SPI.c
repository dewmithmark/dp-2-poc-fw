/**
 * @file SPI.c
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#include <avr/io.h>
#include "SPI.h"

void SPI_INIT() 
{  
    DDRB |= (1 << DDB3)|(1 << DDB5)|(1 << DDB2);
    DDRB &= ~(1 << DDB4);    
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    SPCR &= ~(1 << DORD);  // Clear the DORD bit to set MSB first (default)
	PORTB |= 1 << PORTB2;
}

uint8_t SPI_TRANSFER(uint8_t data)
{ 
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));    
    return SPDR;
}

void SPI_WRITE(uint8_t data) 
{
	SPDR = data;		
	while (!(SPSR & (1 << SPIF)));
}

void SPI_READ(uint8_t * recvdata) 
{
	SPDR = 0xFF;	
	while (!(SPSR & (1 << SPIF)));	
	*recvdata = SPDR;
}

void SPI_ENABLE_SLAVE()
{   
    PORTB &= ~(1 << PORTB2);
}

void SPI_DISABLE_SLAVE()
{
	PORTB |= 1 << PORTB2;
}

void SPI_END()
 {
	// Disable SPI
	SPCR &= ~(1 << SPE);

	// Set MOSI, SCK, and SS pins as inputs
	DDRB &= ~((1 << DDB3) | (1 << DDB5) | (1 << DDB2));
}

