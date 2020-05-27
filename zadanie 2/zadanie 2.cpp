#include "Octa.h"

int main() {

	Octal a;
	cin >> a;
	Octal b;
	cin >> b;
	Octal c, f;
	cout << "a =  ";
	cout << a;
	cout << "b =  ";
	cout << b;
	cout << "a - b= ";
	c = a - b;
	cout << c;
	cout << "a + b= ";
	c = a + b;
	cout << c;

	if (a == b) {
		cout << " a ravno b";
	}
	else {
		cout << "a ne ravno b";
	}

	getchar();
	getchar();
	return 0;
}
//сначала 1 (длина числа), потом число(само число), затем 2 (второе число) и число 