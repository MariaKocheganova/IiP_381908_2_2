#include "Hex.h"
#include <Windows.h>
int main() 
{

	Hex a("FFFF"); // 65535
	Hex b(); // 0
	Hex c("A"); //10
	Hex e(c);
	Hex d = a - c;
	cout << d << endl;
	Hex m("AB");
	cout << a - m << endl;
	if (a > m) cout << "+";
	if (a < m) cout << "-";
	if (c == e) cout << "equal" << endl;
	Hex j;
	cin >> j;
	cout << j << endl;


	system("pause");
	return 0;
}