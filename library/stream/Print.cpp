/*
 * Print.cpp
 *
 *  Created on: 10/12/2014
 *      Author: kike
 */

#include "Print.h"

Print::Print(){}
Print::~Print(){}

int Print::write(const char* str, int len)
{
	 int n = 0;
	 while (len--) {
		 n += write(*str++);
	 }
	 return n;
}

int Print::write(char* str)
{
	return write(str,strlen(str));
}

int Print::println()
{
	return write('\n');
}
int Print::print(char dato)
{
	return write(dato);
}
int Print::print(char* dato)
{
	return write(dato);
}
int Print::print(const char* dato)
{
	return write((char*)dato);
}

int Print::print(char dato, int base)
{
	return print((long)dato, base);
}
int Print::print(unsigned char dato, int base)
{
	return print((unsigned long)dato, base);
}
int Print::print(int dato, int base)
{
	return print((long)dato, base);
}
int Print::print(unsigned int dato, int base)
{
	return print((unsigned long)dato, base);
}
int Print::print(long dato, int base)
{
	int n = 0;
	if(dato<0 && base == 10)
	{
		n += write('-');
		dato = -dato;
	}
	n += printNumber(dato,base);
	return n;
}
int Print::print(unsigned long dato, int base)
{
	return printNumber(dato,base);
}
int Print::print(double dato, int digito)
{
	return printFloat(dato, digito);
}


int Print::println(char* dato)
{
	int n = print(dato);
	return n + println();
}
int Print::println(const char* dato)
{
	int n = print(dato);
	return n + println();
}
int Print::println(char dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(unsigned char dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(short dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(unsigned short dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(int dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(unsigned int dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(long dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(unsigned long dato, int base)
{
	int n = print(dato, base);
	return n + println();
}
int Print::println(double dato, int digito)
{
	int n = print(dato, digito);
	return n + println();
}


int Print::printNumber(unsigned long number, int base)
{
	char buf[8* sizeof(long) + 1];
	char* str = &buf[sizeof(buf) - 1];
	*str = 0;

	if(base < 2) return 0;
	do{
		unsigned long n = number;
		number /= base;
		char nu = n - number*base;
		if(nu>9)nu += 0x37;
		else nu += 0x30;
		*--str = nu;
	}while(number);
	return write(str);
}
int Print::printFloat(float dato, int digito)
{
	int n = 0;
	char buff[23];
	char* str = &buff[22];
	*str = 0;

	if (dato < 0)
	{
		dato = -dato;
		n += write('-');
	}

	unsigned long entero = (unsigned long)dato;
	dato = dato - (double)entero;
	while(digito--)dato*=10;
	unsigned long fraccion = dato;
	do
	{
		unsigned long n = fraccion;
		fraccion /= 10;
		char nu = n - fraccion*10;
		*--str = nu + 0x30;
	}while(fraccion);
	*--str = '.';
	do
	{
		unsigned long n = entero;
		entero /= 10;
		char nu = n - entero*10;
		*--str = nu + 0x30;
	}while(entero);
	return n + write(str);
}

/*int Print::printf( const char * format, ... )
{
	char buffer[64];
	char caracteres;
	va_list args;
	va_start (args, format);
	caracteres = vsprintf (buffer,format, args);
	va_end (args);

	return write(buffer,caracteres);
}*/

