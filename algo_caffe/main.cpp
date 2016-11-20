#include "order.h"
#include "barista.h"
#include "MyTimer.h"
#include <conio.h>

static queue<string> orderQueue;
int main() {


	fstream inStream, inStream2;
	inStream.open("order.txt");
	Order order = getOrder(inStream);
	map<string, int> ::iterator iter;

	inStream2.open("barista.txt");
	int baristaNum;
	inStream2 >> baristaNum;
	Barista *barista = new Barista[baristaNum];
	for (int i = 0; i < baristaNum; i++) {
		barista[i] = getBarista(inStream2);
	}

	orderQueue = order.makeOrderQueue(orderQueue);
	while (!orderQueue.empty()) {
		cout << orderQueue.front() << endl;
		orderQueue.pop();
	}

	MyTimer timer;
	bool quit = false;
	while (!quit) {
		char choice = getch();
		switch (choice) {
		case 's':
			timer.start();
			break;

		case 'g':
			barista[0].makeTime = timer.getTime();
			cout << barista[0].makeTime << endl;


			break;
		case 'q':
			quit = true;
			break;
		}
	}


	inStream.close();
	inStream2.close();
	return 0;
}

/*map<string, int> ::iterator iter;
for (iter = order.menu.begin(); iter != order.menu.end(); ++iter) {
cout << iter->first << " " << iter->second << endl;
}*/