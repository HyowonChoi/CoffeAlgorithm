#ifndef __ORDER_H__
#define __ORDER_H__

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

enum menuId {
	mochaLatte = 10, americano = 5, hotChoco = 8, macchiato = 13, milkTea = 8, juice = 10, toast = 5
};

class Order {
public:
	int time[2]; // [0]:시간 [1]:분
	int customerNum; // 손님번호 
	int numMenu; // 주문종류 수

	map<string, int> menu;

public:
	Order();
	Order(char _time[6], int _num, int _numMenu);
	queue<string> makeOrderQueue(queue<string> _orderQueue);
};

Order getOrder(fstream &inStream);


#endif