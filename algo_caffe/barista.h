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
	float coffeePTime; // Ŀ�� ���� ����
	float juicePTime; // �ֽ� ���� ����
	float toastPTime; // �佺Ʈ ���� ����

	float makeTime; // Queue�ȿ� �ִ� order�� �� �����ϴ� �� �ɸ��� �ð�

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