/*
 * Timer.c
 *
 * Created: 9/8/2023 9:00:34 PM
 *  Author: Dewmith
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Timer.h"
uint32_t millis_counter = 0;

void TIMER_INIT() {
		
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0B |= (1 << CS01) | (1 << CS00);
	TCNT0 = 6;
	TIMSK0 |= (1 << TOIE0);
}

uint32_t millis()
{
	static uint32_t ms = 0;
	cli();
	ms = millis_counter;
	sei();
	return ms;
}


ISR(TIMER0_OVF_vect)
{
	millis_counter++;
}