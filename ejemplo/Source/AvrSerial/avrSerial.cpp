/*
 * avrAvrSerial.cpp
 *
 *  Created on: 08/10/2014
 *      Author: kike
 */
#include "avrSerial.h"
#include <avr/io.h>

void (*intusart)();
char datoRX;

ISR(USART_RX_vect)
//void AvrSerial::isrUsartRx()
{
	datoRX = UDR0;
	if(intusart != 0)intusart();
}

AvrSerial::AvrSerial():
	baudios(9600)
{
	unsigned int ba;

	ba = (2000000/this->baudios)-1;
	intusart = 0;

	UBRR0H = (unsigned char)(ba>>8);
	UBRR0L = (unsigned char)ba;
	//UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0A |= 1<<U2X0;
	UCSR0B = (1<<TXEN0)|(1<<RXEN0);
	UCSR0C = (3<<UCSZ00);
}
AvrSerial::AvrSerial(long bauds)
{
	unsigned int ba;
	this->baudios = bauds;

	ba = (2000000/bauds)-1;
	intusart = 0;

	UBRR0H = (unsigned char)(ba>>8);
	UBRR0L = (unsigned char)ba;
	//UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0A |= 1<<U2X0;
	UCSR0B |= (1<<TXEN0)|(1<<RXEN0);
	UCSR0C |= (3<<UCSZ00);
}
void AvrSerial::begin(long bauds)
{
	unsigned int ba;
	this->baudios = bauds;

	ba = (2000000/bauds)-1;
	intusart = 0;

	UBRR0H = (unsigned char)(ba>>8);
	UBRR0L = (unsigned char)ba;
	//UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0A |= 1<<U2X0;
	UCSR0B = (1<<TXEN0)|(1<<RXEN0);
	UCSR0C = (3<<UCSZ00);
}

int AvrSerial::read()
{
	return datoRX;
}

void AvrSerial::setInterrupt(void (*prog)())
{
	intusart = prog;
	UCSR0B |= 1<<RXCIE0;
	sei();
}
void AvrSerial::removeInterrupt()
{
	intusart = 0;
	UCSR0B &= ~1<<RXCIE0;
}

void AvrSerial::USART_Transmit(unsigned char data)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}


long AvrSerial::getBaudios()
{
	return this->baudios;
}

void AvrSerial::setBaudios(long bauds)
{
	unsigned int ba;
	this->baudios = bauds;

	ba = (2000000/bauds)-1;

	UBRR0H = (unsigned char)(ba>>8);
	UBRR0L = (unsigned char)ba;
}

