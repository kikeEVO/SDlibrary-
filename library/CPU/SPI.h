/*
 * SPI.h
 *
 *  Created on: 01/07/2015
 *      Author: kike
 */

#ifndef SOURCE_SD_UTILITY_SPI_H_
#define SOURCE_SD_UTILITY_SPI_H_

uint8_t const SPI_FULL_SPEED = 0;
uint8_t const SPI_HALF_SPEED = 1; // 4Mhz
uint8_t const SPI_QUARTER_SPEED = 2;

uint8_t SPItransfer(uint8_t data)
{
	//transfer one byte wait and return byte in
}
uint16_t SPItransfer16(uint16_t data)
{
	//transfer two byte wait and return two byte in
}
void SPItransfer(void *buf, unsigned int count)
{
	//transfer buffer and replace for in
 }

void SPIchipSelect()
{
	//pin SPI select Low
}
void SPIchipDeSelect()
{
	//pin SPI select high
}

void SPIinit()
{
	//config SPI master mode 1
}

void SPIsetSckRate(uint8_t sckRateID)
{
	//config SCLK baut rate
}

#endif /* SOURCE_SD_UTILITY_SPI_H_ */
