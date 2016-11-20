#include "MyTimer.h" 
#include<cstdlib>
#include<conio.h>
#include<iostream>

using namespace std;

MyTimer::MyTimer(){
	resetted = true;
	running = false;
	beg = 0;
	end = 0;
}

MyTimer::~MyTimer(){ }

void MyTimer::start() {
	if (!running) {
		if (resetted)
			beg = (unsigned long)clock();
		else
			beg -= end - (unsigned long)clock();
		running = true;
		resetted = false;
	}
}

void MyTimer::stop() {
	if (running) {
		end = (unsigned long)clock();
		running = false;
	}
}

void MyTimer::reset() {
	bool wereRunning = running;
	if (wereRunning)
		stop();
	resetted = true;
	beg = 0;
	end = 0;
	if (wereRunning)
		start();
}

bool MyTimer::isRunning() {
	return running;
}

unsigned long MyTimer::getTime() {
	if (running)
		return ((unsigned long)clock() - beg) / CLOCKS_PER_SEC;
	else
		return end - beg;
}

bool MyTimer::isOver(unsigned long seconds) {
	return seconds >= getTime();
}