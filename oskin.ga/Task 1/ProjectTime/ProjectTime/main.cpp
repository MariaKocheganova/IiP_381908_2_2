#include "Time.h"

int main() {
	string tt = "13:40:00";
	Time a, b(12,30,00), c(a), d(tt);
	cout << a << endl;
	a = b;
	cout << a << endl;
	Time tem1(1,30,01), tem2(0,30,00);
	a = tem1 + tem2;
	cout << a << endl;
	a = tem1 - tem2;
	cout << a << endl;
	if (a < b) cout << "+" << endl;
	if (b > a) cout << "+" << endl;
	Time temp;
	cin >> temp;
	if (temp == a) cout << "equal" << endl;
	if (a != d) cout << "not equal" << endl;

	return 0;
}