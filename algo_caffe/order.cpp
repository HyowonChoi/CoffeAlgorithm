#include "order.h"
using namespace std;

Order::Order() {}

Order::Order(char _time[6], int _num, int _numMenu) {
	char* tok;
	tok = strtok(_time, ":");
	time[0] = atoi(tok);
	tok = strtok(NULL, " ");
	time[1] = atoi(tok);

	customerNum = _num;
	numMenu = _numMenu;
}

Order getOrder(fstream &inStream) {

	char time[6];
	int cNum;
	int mNum;
	string menuId;
	int mAmount;
	map<string, int> ::iterator iter;

	inStream >> time;
	inStream >> cNum;
	inStream >> mNum;
	Order order(time, cNum, mNum);

	for (int i = 0; i < mNum; i++) {
		inStream >> menuId;
		inStream >> mAmount;
		// map�� key�� �������� map�ȿ��� ���ĵ�
		order.menu.insert(pair<string, int>(menuId, mAmount));
	}
	return order;
}

queue<string> Order::makeOrderQueue(queue<string> _orderQueue) { // �ֹ� ���̺� ����
	map<string, int> ::iterator iter;
	char customerNumS[2] = { 0, };
	itoa(Order::customerNum, customerNumS, 10);

	for (iter = menu.begin(); iter != menu.end(); ++iter) { // �� ����� �ֹ��� ���̺� ��� push
		string str = iter->first;
		for (int i = 0; i < iter->second; i++) {
			_orderQueue.push(str);
		}
	}
	_orderQueue.push(customerNumS);
	return _orderQueue;
}
