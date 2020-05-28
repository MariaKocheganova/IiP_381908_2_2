#include "Tabulator.h" 
int main() {
	setlocale(LC_ALL, "Russian");
	Tabulator x;
	int x1, a1, b1, n1, m;
	cout « "1.Дать интервал табулирования [a, b] и заданном количестве точек табуляции"«endl«"2.Задать число точек табулирования n"«endl«"3.Узнать интервал табулирования"«endl«"4.Узнать число точек табулирования"«endl«"5.Выполнить табулирование функции"«endl«"6.Вычислить значение табулированной функции в заданной точке x и сравнить это значение со значением исходной функции в этой точке"«endl«"7.Завершить работу"«endl;

	do {
		cin » m;
		switch (m) {
		case 1:
			cout « "Задайте интервал табулирования a и b" « endl;
			cin » a1 » b1;
			cout « a1 « b1;
			x.interval(a1, b1);
			break;
		case 2:
			cout « "Задайте число точек табулирования n" « endl;
			cin » n1;
			x.num(n1);
			break;
		case 3:
			float s[2];
			x.interval1(s[0], s[1]);
			cout « s[1] « s[0];

			break;
		case 4:
			int n0;
			n0 = x.num1();
			cout « n0;
			break;
		case 5:
			x.tab();

			break;
		case 6:


			break;
		}
	} while (m != 7);





	return 0;
}
