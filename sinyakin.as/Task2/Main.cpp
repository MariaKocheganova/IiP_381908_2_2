#include "Header.h"

int main()
{
	Hex c1("4A458", 5);
	Hex c2("F122", 4);
	Hex c8("23A5", 4);
	Hex c9("917", 3);
	Hex c11("CD32", 4);
	Hex c12("42B", 3);
	Hex c13;
	Hex c3;
	Hex c4;
	Hex c5;
	Hex c6;
	Hex c7;
	Hex c10;
	Hex c14;

	cin >> c7;

	cout << "F122 - 4A458" << endl;
	c5 = c2 - c1;
	cout << c5;
	cout << "CD32 - 42B" << endl;
	c14 = c11 - c12;
	cout << c14;
	cout << "CD32 + 42B" << endl;
	c13 = c12 + c11;
	cout << c13;

	cout << "23A5 + 917" << endl;
	c10 = c8 + c9;
	cout << c10;
	cout << "4A458 + F122" << endl;
	c3 = c2 + c1;
	cout << c3;
	cout << "4A458 - F122" << endl;
	c4 = c1 - c2;
	cout << c4;


	if (c1 == c1)
		cout << "c1 = c1" << endl;
	else
		cout << "c1 != c1" << endl;

	if (c1 != c2)
		cout << "c1 != c2" << endl;
	else
		cout << "c1 == c2" << endl;
}