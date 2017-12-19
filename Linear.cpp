#include "StdAfx.h"
#include "Linear.h"


#include "SYS/DEV/DEV.h"

Linear::Linear(void)
{
	this->running = false;
	this->runtimeEnd = 0;
	this->runtimeStart = 0;
	this->triggered = false;
	// g_LogSys << "DPUCooperativeMotorwayMerge: Linear Created" << endl;
}
Linear::~Linear(void)
{
	// g_LogSys << "DPUCooperativeMotorwayMerge: Linear Deleted" << endl;
}


void Linear::start(double start, double end)
{
	if(!(this->isTriggered())) {
		this->runtimeStart = start;
		this->runtimeEnd = end;
		this->running = true;
		this->triggered = true;
		//g_LogSys << "DPUCooperativeMotorwayMerge: Linear Started" << endl;
	}
}

double Linear::run(double current)
{
	double timediff = this->runtimeEnd-this->runtimeStart;
	double time = 0;
	if(this->isRunning()) {
		if(current <= this->runtimeEnd) {
			time = (current-this->runtimeStart)/timediff;
		} else {
			time = 1;
			this->stop();
		}
	} else {
		time = 1;
	}
	return time;
}

void Linear::stop(void)
{
	if(this->isRunning()) {
		this->runtimeStart = 0;
		this->runtimeEnd = 0;
		this->running = false;
		//g_LogSys << "DPUCooperativeMotorwayMerge: Linear Stopped" << endl;
	}
}

void Linear::resetTrigger(void)
{
	this->triggered = false;
}

bool Linear::isRunning(void)
{
	return this->running;
}

bool Linear::isTriggered(void)
{
	return this->triggered;
}