/*
 * Stream.h
 *
 *  Created on: 28/06/2015
 *      Author: kike
 */

#ifndef SOURCE_STREAM_H_
#define SOURCE_STREAM_H_

#include <string.h>
#include "Print.h"

#define PARSE_TIMEOUT 1000  // default number of milli-seconds to wait
#define NO_SKIP_CHAR  1  // a magic char not found in a valid ASCII numeric field

class Stream : public Print{

protected:
    unsigned long _timeout;      // number of milliseconds to wait for the next char before aborting timed read
    int timedRead();    // private method to read stream with timeout
    int timedPeek();    // private method to peek stream with timeout
    int peekNextDigit(); // returns the next numeric digit in the stream or -1 if timeout

public:
    virtual int available() {return 0;};
    virtual int read() {return 0;};
    virtual int peek() {return 0;};
    virtual void flush() {};

    Stream();
    ~Stream();

// parsing methods

    void setTimeout(unsigned long timeout);  // sets maximum milliseconds to wait for stream data, default is 1 second

    bool find(char *target);   // reads data from the stream until the target string is found
      bool find(uint8_t *target) { return find ((char *)target); }
      // returns true if target string is found, false if timed out (see setTimeout)

      bool find(char *target, unsigned int length);   // reads data from the stream until the target string of given length is found
      bool find(uint8_t *target, unsigned int length) { return find ((char *)target, length); }
      // returns true if target string is found, false if timed out

      bool findUntil(char *target, char *terminator);   // as find but search ends if the terminator string is found
      bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }

      bool findUntil(char *target, unsigned int targetLen, char *terminate, unsigned int termLen);   // as above but search ends if the terminate string is found
      bool findUntil(uint8_t *target, unsigned int targetLen, char *terminate, unsigned int termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }


      long parseInt(); // returns the first valid (long) integer value from the current position.
      // initial characters that are not digits (or the minus sign) are skipped
      // integer is terminated by the first character that is not a digit.

      float parseFloat();               // float version of parseInt

      unsigned int readBytes( char *buffer, unsigned int length); // read chars from stream into buffer
      unsigned int readBytes( uint8_t *buffer, unsigned int length) { return readBytes((char *)buffer, length); }
      // terminates if length characters have been read or timeout (see setTimeout)
      // returns the number of characters placed in the buffer (0 means no valid data found)

      unsigned int readBytesUntil( char terminator, char *buffer, unsigned int length); // as readBytes with terminator character
      unsigned int readBytesUntil( char terminator, uint8_t *buffer, unsigned int length) { return readBytesUntil(terminator, (char *)buffer, length); }
// terminates if length characters have been read, timeout, or if the terminator character  detected
// returns the number of characters placed in the buffer (0 means no valid data found)

// Arduino String functions to be added here
    //String readString();
    //String readStringUntil(char terminator);

protected:
    long parseInt(char skipChar); // as above but the given skipChar is ignored
// as above but the given skipChar is ignored
// this allows format characters (typically commas) in values to be ignored

    float parseFloat(char skipChar);  // as above but the given skipChar is ignored

    struct MultiTarget {
		const char *str;  // string you're searching for
		unsigned int len;       // length of string you're searching for
		unsigned int index;     // index used by the search routine.
	};

// This allows you to search for an arbitrary number of strings.
// Returns index of the target that is found first or -1 if timeout occurs.
    int findMulti(struct MultiTarget *targets, int tCount);

};

#endif /* SOURCE_STREAM_H_ */
