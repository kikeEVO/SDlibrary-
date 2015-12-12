/*
 * auxiliar.c
 *
 *  Created on: 26/09/2014
 *      Author: kike
 */
#include "auxiliar.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>

volatile struct mapaBits *PORTBbits = (struct mapaBits*)&PORTB;
volatile struct mapaBits *PORTCbits = (struct mapaBits*)&PORTC;
volatile struct mapaBits *PORTDbits = (struct mapaBits*)&PORTD;
volatile struct mapaBits *DDRBbits = (struct mapaBits*)&DDRB;
volatile struct mapaBits *DDRCbits = (struct mapaBits*)&DDRC;
volatile struct mapaBits *DDRDbits = (struct mapaBits*)&DDRD;
volatile struct mapaBits *PINBbits = (struct mapaBits*)&PINB;
volatile struct mapaBits *PINCbits = (struct mapaBits*)&PINC;
volatile struct mapaBits *PINDbits = (struct mapaBits*)&PIND;

void* operator new(size_t size)
{
	return malloc(size);
}
void *operator new[](size_t size)
{
	return malloc(size);
}
void operator delete(void * ptr)
{
	free(ptr);
}
void operator delete[](void * ptr)
{
	free(ptr);
}
