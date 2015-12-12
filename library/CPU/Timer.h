/*
 * Timer.h
 *
 *  Created on: 25/06/2015
 *      Author: kike
 */

#ifndef SOURCE_TIMER_H_
#define SOURCE_TIMER_H_

#include <stdlib.h>

class Timer {
public:
	Timer();
	Timer(unsigned long);
	~Timer();
	void setTime(unsigned long);
	unsigned long getTime();
	void start();
	void reStart();
	void stop();
	bool checkTimer();
	void updateTimer();
private:
	char status;
	unsigned long milis;
	unsigned long count;

};

class TimersInt
{
public:
	TimersInt();
	void updateTimers();
	void addTimer(Timer*);
	void delTimer(Timer*);
private:
	int nTimers;
	size_t* dirTimer;

};

extern TimersInt Timers;

#endif /* SOURCE_TIMER_H_ */
