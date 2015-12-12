/*
 * SPI.h
 *
 *  Created on: 01/07/2015
 *      Author: kike
 */

#ifndef SOURCE_SD_UTILITY_SPI_H_
#define SOURCE_SD_UTILITY_SPI_H_

#include <avr/io.h>
#include "auxiliar.h"

uint8_t const SPI_FULL_SPEED = 0;
uint8_t const SPI_HALF_SPEED = 1; // 4Mhz
uint8_t const SPI_QUARTER_SPEED = 2;

uint8_t SPItransfer(uint8_t data)
{
	SPDR = data;
		while(!(SPSR & (1<<SPIF)));
		return SPDR;
}
uint16_t SPItransfer16(uint16_t data)
{
	uint16_t out;
		out = SPItransfer((data>>8) & 0xff) << 8;
		out += SPItransfer(data & 0xff);
		return out;
}
void SPItransfer(void *buf, unsigned int count)
{
	if (count == 0) return;
	    uint8_t *p = (uint8_t *)buf;
	    while (count-- > 0) {
	    	*p = SPItransfer(*p);
	    	p++;
	    }
 }

void SPIchipSelect()
{
	PORTBbits->bit2 = 0;
}
void SPIchipDeSelect()
{
	PORTBbits->bit2 = 1;
}

void SPIinit()
{
		DDRB = (1<<DD2)|(1<<DD3)|(1<<DD5);
		SPIchipDeSelect();
		SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0);
		SPSR &= ~(1 << SPI2X);
}

void SPIsetSckRate(uint8_t sckRateID)
{
	switch (sckRateID) {
		    case 0:
		    	SPCR = (1<<SPE) | (1<<MSTR) ;
		    	SPSR |= (1 << SPI2X);
		    	break;
		    case 1:
		    	SPCR = (1<<SPE) | (1<<MSTR);
		    	SPSR &= ~(1 << SPI2X);
		    	break;
		    case 2:
		    	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
		    	SPSR |= (1 << SPI2X);
		    	break;
		    default:
		    	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
		    	SPSR &= ~(1 << SPI2X);
		    	break;
		  }
}

#endif /* SOURCE_SD_UTILITY_SPI_H_ */
