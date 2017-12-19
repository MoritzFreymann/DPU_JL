#pragma once
class Linear
{
public:
	Linear(void);
	//Linear(double r, double g, double b, double a);
	~Linear(void);
	
	void start(double start, double end);
	double run(double current);
	void stop(void);
	void resetTrigger(void);
	bool isRunning(void);
	bool isTriggered(void);

private:
	double runtimeStart;
	double runtimeEnd;
	bool running;
	bool triggered;
};