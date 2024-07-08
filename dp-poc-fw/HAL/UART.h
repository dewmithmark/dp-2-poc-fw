/**
 * @file UART.h
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#ifndef _UART_H_
#define _UART_H_

#define BAUD_RATE 9600

/**
 * @brief 
 *
 */
void UART_INIT();

/**
 * @brief 
 *
 */
void UART_TRANSMIT(uint8_t data);

uint8_t UART_RECEIVE();

void print( const char *message);
#endif