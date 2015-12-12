La librerías principales para SD depende de otras que requieren parámetros específicos de cada arquitectura de procesador, dichos parámetros se deben especificar en las librerías que se encuentran en la carpeta CPU.

SPI.h

Este archivo contiene las funciones para uso del puerto SPI, es necesario agregar el código para cada función. 

Timer.h/.cpp

Esta librería contiene funciones de temporizado, si no es sustituida por completo es necesario incluir una interrupción así como los para metros para configurarla.

Dentro de las funciones de Timer y Stream se hace uso del operador “new” y “delete”, si el compilador no las reconoce es necesario declararlas.
