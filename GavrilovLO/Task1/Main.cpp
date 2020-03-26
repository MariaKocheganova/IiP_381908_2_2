#include"Header.h"
#include<stdlib.h>
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
	cout << "2)symma" << endl;
	cout << "3)proizvedenie" << endl;
	cout << "4)delenie" << endl;
	cout << "5)sravnenie" << endl;
	cin >> c;
	switch (c) {
	case 1:
		a = a + f;
		cout << a;
		break;
	case 2:
		a += f;
		cout << a;
		break;
	case 3:
		s = 10;
		a = a* s;


		cout << a;

		break;
	case 4:
		j = 10;
		a = a / j;
		cout << a;
		break;
	case 5:
		a == f;
		break;

	case 6:
		s = 10;
		a = a* s;
		cout << a;
		break;
	}

	getchar();
	getchar();
}