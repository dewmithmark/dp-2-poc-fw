/*
 * GPIO.h
 *
 * Created: 8/11/2023 9:48:52 AM
 *  Author: Dewmith
 */ 
#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>

enum _PORTS
{
	_PORTB = 1,
	_PORTC,
	_PORTD
};

#define INPUT			0
#define OUTPUT			1
#define INPUT_PULLUP	2

#define LOW		0
#define ANY		1
#define FALLING	2
#define RISING	3

#define RESET	0
#define SET		1


#define CURRENT_SENSOR_IN_Pin		PORTC0
#define CURRENT_SENSOR_IN_Port		_PORTC
#define CURRENT_SENSOR_IN_Channel	0
#define VOLTAGE_SENSOR_IN_Pin		PORTC1
#define VOLTAGE_SENSOR_IN_Port		_PORTC
#define VOLTAGE_SENSOR_IN_Channel	1
#define RELAY_DRIVER_OUT_Pin		PORTD2
#define RELAY_DRIVER_OUT_Port		_PORTD
#define APP_DATA_SCK_Pin			PORTB5
#define APP_DATA_SCK_Port			_PORTB
#define APP_DATA_MISO_Pin			PORTB4
#define APP_DATA_MISO_Port			_PORTB
#define APP_DATA_MOSI_Pin			PORTB3
#define APP_DATA_MOSI_Port			_PORTB
#define APP_DATA_SS_Pin				PORTB2
#define APP_DATA_SS_Port			_PORTB



/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_SET_PIN(uint8_t pin, uint8_t port, uint8_t status);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_WRITE_PIN(uint8_t pin, uint8_t port, uint8_t status);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
uint8_t GPIO_READ_PIN(uint8_t pin, uint8_t port);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_PCINT_SET(uint8_t pin, uint8_t port);

/**
 * @brief 
 *
 * @param
 *
 * @retval
 */
void GPIO_EXTINT_SET(uint8_t int_type, uint8_t trigger_edge);

void GPIO_EXTINT_RESET(uint8_t int_type);
      


#endif /* GPIO_H_ */