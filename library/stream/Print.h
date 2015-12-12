/*
 * Print.h
 *
 *  Created on: 10/12/2014
 *      Author: kike
 */

#ifndef PRINT_H_
#define PRINT_H_

#include <string.h>
//#include <stdarg.h>
#include <stdio.h>

#define BIN 2
#define DEC 10
#define HEX 16

class Print {

public:
	//constructores
	Print();
	~Print();
	//funciones primarias
	/*virtual size_t write(uint8_t) = 0;
	size_t write(const char *str) {
		if (str == NULL) return 0;
	    return write((const uint8_t *)str, strlen(str));
	}
	virtual size_t write(const uint8_t *buffer, size_t size);
	size_t write(const char *buffer, size_t size) {
		return write((const uint8_t *)buffer, size);
	}*/

	virtual int write(char){return 0;}
	virtual int write(const char* ,int);
	//int write(char*, int);
	int write(char*);
	int println();
	int printNumber(unsigned long, int);
	int printFloat(float, int);
	//funciones basicas
	int print(char);
	int print(char*);
	int print(const char*);
	int print(char, int = 10);
	int print(unsigned char, int = 10);
	int print(short, int = 10);
	int print(unsigned short, int = 10);
	int print(int, int = 10);
	int print(unsigned int, int = 10);
	int print(long, int = 10);
	int print(unsigned long, int = 10);
	int print(double, int = 2);

	int println(char*);
	int println(const char*);
	int println(char, int = 10);
	int println(unsigned char, int = 10);
	int println(short, int = 10);
	int println(unsigned short, int = 10);
	int println(int, int = 10);
	int println(unsigned int, int = 10);
	int println(long, int = 10);
	int println(unsigned long, int = 10);
	int println(double, int = 2);

	//int printf(const char *, ... );
};

#endif /* PRINT_H_ */
