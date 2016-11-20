#ifndef __MYTIMER_H__
#define __MYTIMER_H__
#include <time.h>

class MyTimer
{
public:
	MyTimer();
	~MyTimer();

	void           start();
	void           stop();
	void           reset();
	bool           isRunning();
	unsigned long  getTime();
	bool           isOver(unsigned long seconds);
private:
	bool           resetted;
	bool           running;
	unsigned long  beg;
	unsigned long  end;
};

#endif