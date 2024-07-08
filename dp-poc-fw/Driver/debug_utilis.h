/*
 * debug_utilis.h
 *
 * Created: 8/11/2023 10:40:28 PM
 *  Author: Dewmith
 */ 


#ifndef DEBUG_UTILIS_H_
#define DEBUG_UTILIS_H_

#include <stdio.h>
#include <avr/io.h>

char BUFFER[50];

#ifdef _GNUC_
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

/**
 * @brief function prototypes for linking UART protocol with printf syntax
 *
 */

void print_float(float value);

void print( const char *message);


#endif /* DEBUG_UTILIS_H_ */