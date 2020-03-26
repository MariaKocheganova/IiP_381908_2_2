#include"Header.h"
#include<stdlib.h>
#include <cassert>
using namespace std;
void main() {
	int f1;
	int s;
	int j;
	Money f;
	Money a;
	cin >> a;
	cin >> f;


	int c;
	cout << "1)symma 2 chetov" << endl;

	cout << "2)proizvedenie" << endl;
	cout << "3)delenie" << endl;
	cout << "4)sravnenie" << endl;
	cin >> c;
	switch (c) {
	case 1:
		a = a + f;
		cout << a;
		break;

	case 2:
		s = 10;
		a = a* s;
		cout << a;

		break;
	case 3:
		j = 6;
		a = a / j;
		cout << a;
		break;
	case 4:
		a == f;
		break;

	}

	getchar();
	getchar();
}