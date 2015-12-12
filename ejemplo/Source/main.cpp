/*
 * main.cpp
 *
 *  Created on: 09/07/2015
 *      Author: kike
 */

#include "AvrSerial/avrSerial.h"
#include "SD/SD.h"


void configuraciones();
void bucle();

const char formato[] = {0x42,0x4d,0xb6,0x25,0x0,0x0,0x0,0x0,0x0,0x0,0x36,0x0,0x0,0x0,0x28,0x0
                        ,0x0,0x0,0x50,0x0,0x0,0x0,0x3c,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0x0,0x0
                        ,0x0,0x0,0x80,0x25,0x00,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
                        ,0x0,0x0,0x0,0x0,0x0,0x0};

AvrSerial serial;

int main()
{
	configuraciones();

	while(1)bucle();

	return 0;
}

void bucle()
{

}

void configuraciones()
{
	serial.begin(9600);

	serial.print("Initializing SD card...");
	if (!SD.begin()) {
		serial.println("Card failed, or not present");
	    return;
	}
	serial.println("card initialized.");

	File dataFile = SD.open("imagen2.bmp", FILE_WRITE);

	  	  // if the file is available, write to it:
	if (dataFile)
	{
		serial.println("preparando imagen");
		dataFile.seek(0);
		dataFile.write(formato,54);

		int c[80];
		for(int a = 0; a< 60; a++)
		{
			for(int b = 0; b< 80; b++)
			{
				if(a%2 == 0 && b%2 == 0)
				{
					c[b] = 0xf800;
				}
				else
				{
					c[b] = 0;
				}
			}
			dataFile.write((char*)&c[0],160);
		}

	  	dataFile.close();
	  	serial.println("imagen completa");
	}
	else
	{
		serial.println("error opening datalog.txt");
	}
}


