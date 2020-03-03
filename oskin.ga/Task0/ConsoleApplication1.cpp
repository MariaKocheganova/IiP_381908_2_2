#include "Classy.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int menu = 0;
	cout << "1.Проверка класса Ccomplex.";
	cout << "2.Проверка класса Cstring.";
	cout << "Введите номер пункта:";
	cin >> menu;
	switch (menu)
	{
	case 1:
	{
		Ccomplex num1;
		Ccomplex num2;
		Ccomplex res1;
		Ccomplex res2;
		num1.InPut();
		cout << "Введите для второго числа.";
		cout << endl;
		num2.InPut();
		res1 = num1.Add(num2);

		res2 = num1.Mlt(num2);
		res1.Output(res1);
		cout << endl;
		res2.Output(res2);
	}
	case 2:
	{

	}
	}
}

