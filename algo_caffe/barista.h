#ifndef __BARISTA_H__
#define __BARISTA_H__

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include "order.h"
#include "MyTimer.h"

using namespace std;

class Barista {
public:
	char name;
	float coffeePTime; // 커피 제작 성능
	float juicePTime; // 주스 제작 성능
	float toastPTime; // 토스트 제작 성능

	float makeTime; // Queue안에 있는 order를 다 수행하는 데 걸리는 시간

	MyTimer t;
	queue<string> myQueue;
	
	Barista();
	Barista(char _name, float _coffeePTime, float _juicePTime, float _toastPTime);
	queue<string> assignOrder(Barista b, queue<string> _orderQueue, queue<string> _myQueue);
};


Barista getBarista(fstream &inStream);
void print(queue<string> _orderQueue);
void timePerception(Barista* barista);

#endif