#include <clocale>
#include <iostream>
#include <cstdlib>
#include "ClassDate.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int z, z1;
	do
	{	cout << "1 - Прибавить к дате\n";
		cout << "2 - Вычесть из даты\n";
		cout << "3 - Сравнить две даты\n";
		cout << "0 - Выход\n";
		cout << "Выбор опции: ";
		cin >> z;
		if (z == 1)
		{
			Date res;
			int days;
			cout << "Выберите режим ввода даты: 1-по числам; Любое другое-строкой: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1;
				cout << "Введите дату: \n";
				cin >> DT1;
				cout << "Введите количество дней: ";
				cin >> days;
				res = DT1+days;
				cout << "Новая дата: " << res;
			}
			else
			{
				string DT1;
				Date DT2;
				cout << "Введите дату: \n";
				cin >> DT1;
				DT2 = DT1;
				cout << "Введите количество дней: ";
				cin >> days;
				res = DT2+days;
				cout << "Новая дата: " << res;
			}
		}
		if (z == 2)
		{
			Date res;
			int days;
			cout << "Выберите режим ввода даты: 1-по числам; Любое другое-строкой: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1;
				cout << "Введите дату: \n";
				cin >> DT1;
				cout << "Введите количество дней: ";
				cin >> days;
				res = DT1-days;
				cout << "Новая дата: " << res;
			}
			else
			{
				string DT1;
				Date DT2;
				cout << "Введите дату: \n";
				cin >> DT1;
				DT2 = DT1;
				cout << "Введите количество дней: ";
				cin >> days;
				res = DT2-days;
				cout << "Новая дата: " << res;
			}
		}
		if (z == 3)
		{
			cout << "Выберите режим ввода даты: 1-по числам; Любое другое-строкой: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1,DT2;
				cout << "Введите первую и вторую даты: \n";
				cin >> DT1;
				cin >> DT2;
				if (DT1==DT2)
				{
					cout << "Даты равны";
				}
				if (DT1 > DT2)
				{
					cout << "Первая дата больше";
				}
				if (DT1 < DT2)
				{
					cout << "Вторая дата больше";
				}
			}
			else
			{
				string DT1,DT2;
				cout << "Введите первую и вторую даты: \n";
				cin >> DT1;
				cin >> DT2;
				if (DT1 == DT2)
				{
					cout << "Даты равны";
				}
				if (DT1 > DT2)
				{
					cout << "Первая дата больше";
				}
				if (DT1 < DT2)
				{
					cout << "Вторая дата больше";
				}
			}
		}
		if ((z != 1) && (z != 2) && (z != 3) && (z != 0))
		{
			cout << "Ошибка 3: неверная опция\n";
		}
		if (z == 0)
		{
			return 0;
		}
		
		cout << "Продолжить работу? 0-Нет; Любое другое- Да\n";
		cin >> z;
		cout << "\n";
		
	} while (z != 0);
	return 0;
}