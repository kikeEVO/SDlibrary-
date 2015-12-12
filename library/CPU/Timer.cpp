/*
 * Timer.cpp
 *
 *  Created on: 25/06/2015
 *      Author: kike
 */

#include "Timer.h"

Interruption(Timer = 1ms)//Replace
{
	Timers.updateTimers();
}

Timer::Timer()
{
	this->status = 0;
	this->milis = 0;
	Timers.addTimer((Timer*)this);
}
Timer::Timer(unsigned long time)
{
	this->status = 0;
	this->milis = time;
	Timers.addTimer((Timer*)this);
}

Timer::~Timer()
{
	Timers.delTimer(this);
}


void Timer::setTime(unsigned long t)
{
	this->milis = t;
}
unsigned long Timer::getTime()
{
	return this->count;
}

void Timer::start()
{
	if(this->milis == 0)return;
	this->status = 1;
	this->count = 0;
}
void Timer::reStart()
{
	if(this->milis == 0)return;
	this->status = 1;
}
void Timer::stop()
{
	this->status = 0;
}

bool Timer::checkTimer()
{
	if(this->status == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Timer::updateTimer()
{
	if(this->status == 1)
	{
		this->count++;
		if(this->count == this->milis)
		{
			this->status = 2;
		}
	}
}

TimersInt::TimersInt()
{
	nTimers = 0;
	configureInterruptionTimer(1ms);//Replace
}

void TimersInt::addTimer(Timer* op)
{
	if(op == 0) return;

	size_t* inter = new size_t[nTimers +1];
	for(int a = 0; a < nTimers; a++)
	{
		inter[a] = dirTimer[a];
	}
	delete dirTimer;

	dirTimer = inter;
	dirTimer[nTimers] = (size_t)op;
	nTimers++;
	enableInterruptionTimer();//Replace
}


void TimersInt::delTimer(Timer* op)
{
	if(op == 0 || nTimers == 0) return;

	if(!--nTimers)
		disableInterruptionTimer();//Replace
	size_t* inter = new size_t[nTimers];
	for(int a = 0; a < nTimers; a++)
	{
		if(dirTimer[a] == (size_t)op)
		{
			dirTimer[a] = dirTimer[nTimers];
		}
		inter[a] = dirTimer[a];
	}
	delete dirTimer;
	dirTimer = inter;
}

void TimersInt::updateTimers()
{
	for(int a = 0; a < nTimers; a++)
	{
		((Timer*)dirTimer[a])->updateTimer();
	}
}


TimersInt Timers;
