/**
 * @file SPI.h
 * @author Dewmith Ranasinghe (dewmithrana@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-08-2023
 *  
 */

#ifndef _SPI_H_
#define _SPI_H_


void SPI_INIT();

uint8_t SPI_TRANSFER(uint8_t data); 

void SPI_WRITE(uint8_t data) ;

void SPI_READ(uint8_t * recvdata);

void SPI_ENABLE_SLAVE();

void SPI_DISABLE_SLAVE();

void SPI_END();


#endif