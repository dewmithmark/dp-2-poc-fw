/*
 * relay_control.c
 *
 * Created: 6/20/2024 1:12:49 PM
 *  Author: Dewmith
 */ 

#include "GPIO.h"
#include "relay_control.h"


void relay_init()
{
	GPIO_SET_PIN(RELAY_DRIVER_OUT_Pin , RELAY_DRIVER_OUT_Port , OUTPUT);
}


void enable_relay()
{
	GPIO_WRITE_PIN(RELAY_DRIVER_OUT_Pin , RELAY_DRIVER_OUT_Port , SET);
}



void disable_relay()
{
	GPIO_WRITE_PIN(RELAY_DRIVER_OUT_Pin , RELAY_DRIVER_OUT_Port , RESET);	
}