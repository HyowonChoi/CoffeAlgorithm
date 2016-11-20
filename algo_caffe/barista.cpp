#include "barista.h"
using namespace std;

Barista::Barista() {}
Barista::Barista(char _name, float _coffeePTime, float _juicePTime, float _toastPTime) {
	coffeePTime = _coffeePTime;
	juicePTime = _juicePTime;
	toastPTime = _toastPTime;
	name = _name;

	makeTime = 0;
}

Barista getBarista(fstream &inStream) {
	char name;
	float cPTime;
	float jPTime;
	float tPTime;

	inStream >> name >> cPTime >> jPTime >> tPTime;
	Barista barista(name, cPTime, jPTime, tPTime);
	
	return barista;
}
queue<string> Barista::whoIsNext(queue<string> _myQueue) {
	if ()
	return _myQueue;
}

queue<string> Barista::assignOrder(Barista b, queue<string> _orderQueue, queue<string> _myQueue) {
	int time = 0;

	while (!_orderQueue.empty())
	{
		string tmp = _orderQueue.front();

		if (tmp.compare("mochaLatte")){
			time = makeTime + b.coffeePTime * mochaLatte;
			makeTime += b.coffeePTime * mochaLatte;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}
		if (tmp.compare("americano")){
			time = makeTime + b.coffeePTime * americano;
			makeTime += b.coffeePTime * americano;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}
		if (tmp.compare("hotChoco")){
			time = makeTime + b.coffeePTime * hotChoco;
			makeTime += b.coffeePTime * hotChoco;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}
		if (tmp.compare("milkTea")){
			time = makeTime + b.coffeePTime * milkTea;
			makeTime += b.coffeePTime * milkTea;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}

		if (tmp.compare("juice")){
			time = makeTime + b.coffeePTime * juice;
			makeTime += b.coffeePTime * juice;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}
		if (tmp.compare("toast")){
			time = makeTime + b.coffeePTime * toast;
			makeTime += b.coffeePTime * toast;
			_myQueue.push(tmp);
			_orderQueue.pop();
		}
	}
	_myQueue.push(_orderQueue.front());
	_orderQueue.pop();
	return _orderQueue; 
}


void print(queue<string> _orderQueue) {
	cout << _orderQueue.front() << endl;
}