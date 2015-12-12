/*
 * avrSerial.h
 *
 *  Created on: 08/10/2014
 *      Author: kike
 */

#ifndef AVRSERIAL_H_
#define AVRSERIAL_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../stream/Print.h"
#include <stdio.h>

class AvrSerial : public Print {

public:
	AvrSerial();
	AvrSerial(long bauds);
	void begin(long bauds);
	long getBaudios();
	void setBaudios(long bauds);
	void setInterrupt(void (*prog)());
	void removeInterrupt();
	int	read();

	int write(const char dato){USART_Transmit(dato);return 1;}

private:
	long baudios;
	void USART_Transmit(unsigned char data);
	void isrUsartRx();
};


#endif /* AVRSERIAL_H_ */
