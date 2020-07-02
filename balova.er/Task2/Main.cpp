#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Vector v, v1;
	int k, x, l, x1;
	cout << v;
	cout << "1.—ложение векторов" << endl;
		cout << "2.»ндексаци€" << endl;
		cout << "3.—кал€рное умножение векторов" << endl;
		cout << "4.”множение вектора на скал€р" << endl;
		cout << "5.Ќахождение длины вектора" << endl;
		cout << "6.ѕрисваивание вектора числу" << endl;
	cin >> k;
	switch (k) {
	case 1:
		cout << "”кажите номера векторов которые будете складывать";
		cin >> x >> x1;
		v.setOp(x, x1);
		v + v1;
		break;
	case 2:
		cout << "”кажите номер вектора " << endl;
		cin >> k;
		cout << "¬ведите 1, если хотите изменить x переменную и 2 если y" << endl;
		cin >> x;
		cout << "¬ведите новое значение переменной" << endl;
		cin >> l;
		v[k * 4 + x - 2] = l;
		break;
	case 3:
		cout << "”кажите номера векторов которые будете умножать";
		cin >> x >> x1;
		v.setOp(x, x1);
		v* v1;
		break;
	case 4:
		cout << "”кажите номер вектора и число которое будете умножать";
		cin >> x >> x1;
		v.setOp(x, x1);
		v *= v1;
		break;
	case 5:
		cout << "”кажите номер вектора,длину которого хотите найти";
		cin >> x;
		v.dl(x);
		break;
	case 6:
		cout << "”кажите номер вектора и число которому будете присваивать";
		cin >> x >> x1;
		v.setOp(x, x1);
		v = v1;
		break;
	}
	cin >> v;
	return 0;
}