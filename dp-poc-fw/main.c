/*
 * dp-poc-fw.c
 *
 * Created: 6/20/2024 12:06:22 PM
 * Author : Dewmith
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "GPIO.h"
#include "ADC.h"
#include "UART.h"
#include "Timer.h"
#include "SPI.h"
#include "debug_utilis.h"
#include "voltage_sensor.h"
#include "current_sensor.h"
#include "relay_control.h"

static float voltage = 0;	
static float current = 0;
static char received_data = 0;

void update_relay_status(char status)
{
	if('A' == status)
	{
		enable_relay();
	}
	else if('B' == status)
	{
		disable_relay();
	}
	else
	{
		//no implementation
	}
}

int main(void)
{
    TIMER_INIT();
	UART_INIT();
	ADC_INIT();
	SPI_INIT();	

	voltage_sensor_init();
	current_sensor_init();
	relay_init();
  
    while (1) 
    {

	    voltage = get_voltage_rms();
		current = get_current_rms();
		
		print_float(voltage);
		print("\n\r");
		print_float(current);
		print("\n\r");
		
		received_data = UART_RECEIVE();	
		
		update_relay_status(received_data);
				
		print("data sent\n\r");
		_delay_ms(500);
    }
}

