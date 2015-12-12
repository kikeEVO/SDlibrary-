/*
 * auxiliar.h
 *
 *  Created on: 30/06/2014
 *      Author: kike
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>

#define delay_ms(a)	_delay_ms(a)
#define delay_us(a)	_delay_us(a)

struct mapaBits {
   unsigned char bit0:1;
   unsigned char bit1:1;
   unsigned char bit2:1;
   unsigned char bit3:1;
   unsigned char bit4:1;
   unsigned char bit5:1;
   unsigned char bit6:1;
   unsigned char bit7:1;
   };

extern volatile struct mapaBits *PORTBbits;
extern volatile struct mapaBits *PORTCbits;
extern volatile struct mapaBits *PORTDbits;
extern volatile struct mapaBits *DDRBbits;
extern volatile struct mapaBits *DDRCbits;
extern volatile struct mapaBits *DDRDbits;
extern volatile struct mapaBits *PINBbits;
extern volatile struct mapaBits *PINCbits;
extern volatile struct mapaBits *PINDbits;

void* operator new(size_t);
void* operator new[](size_t);
void operator delete(void*);
void operator delete[](void*);


#endif /* AUXILIAR_H_ */
