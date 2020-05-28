#include <iostream>
#include <clocale>
#include <cmath>
#include "Vector.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");

	double a;
	int answer;
	int t = 1;
	Vector v1;
	Vector v2;
	Vector v3;

	while (t) {
		cout << "Что вы хотите сделать?" << endl << "1) Сложить " << endl << "2) Вычесть " << endl << "3) Вычислить скалярное произведение " << endl << "4) Умножить на число " << endl << "5) Сравнение векторов по длине" << endl;
		cin >> answer;

		if (answer == 4) {
			cout << endl << "Введите координаты вектора a: ";
			cin >> v1;

			cout << "На какое число вы хотите умножить вектор? ";
			cin >> a;

		}
		else if (answer != 4 && abs(answer) < 6) {
			cout << endl << "Введите координаты первого вектора a: ";
			cin >> v1;

			cout << "Введите координаты второго вектора b: ";
			cin >> v2;
		}

		switch (answer) {
		case 1:
			v3 = v1 + v2;
			break;
		case 2:
			v3 = v1 - v2;
			break;
		case 3:
			 v3=v1 % v2;
			break;
		case 4:
			v3 = v1 * a;
			break;
		case 5:
			v3 = (v1 == v2);
			break;

		default:
			cout << "Вы ничего не выбрали";
			return 0;
		}

		cout << v3;

		cout << "Хотите выполнить другое действие?" << endl << "Да - 1" << endl << "Нет - 0" << endl;
		cin >> t;
		while (t != 1 && t != 0) {
			cout << "Введите 1 или 0 :) ";
			cin >> t;
		}
	}

	return 0;
}