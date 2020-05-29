#include <iostream>
#include "ClassIntegrals.h"
using namespace std;
Integrals::Integrals() {
	a = 0;
	b = 0;
	n = 0;
}
Integrals::Integrals(int _a, int _b, int _n) {
	a = _a;
	b = _b;
	n = _n;
}

Integrals::Integrals(const Integrals& c) {
	a = c.a;
	b = c.b;
	n = c.n;
}

void Integrals::input() {
	cout << "nachal'naya tochka otrezka: ";
	cin >> a;
	cout << "final'naya tochka otrezka: ";
	cin >> b;
	cout << "vvedite nomer otrezka: ";
	cin >> n;
}
double s_srednee = 0;
int numOffunc() {
	int _f;
	cout << "1 - y = 8 + 2*x - x^2" << endl;
	cout << "2 - y = x^5" << endl;
	cout << "3 - y = x^2*sin(x)" << endl;
	cout << "4 - y = 1/(x^2+4*x+3)" << endl;
	cout << "5 - y =  sqrt(x^2 + 4*x + 3)" << endl << endl;
	cout << "vibrat' func: ";
	cin >> _f;
	return _f;
}

int f = numOffunc();

double func(double x, int num_of_func) {
	switch (num_of_func) {
	case 1:
		return 8 + 2 * x - pow(x, 2);
		f = num_of_func;
		break;
	case 2:
		return pow(x, 5);
		f = num_of_func;
		break;
	case 3:
		return sin(x);
		f = num_of_func;
		break;
	case 4:
		return 1 / (pow(x, 2) + 4 * x + 3);
		f = num_of_func;
		break;
	case 5:
		return sqrt(pow(x, 2) + 4 * x + 3);
		f = num_of_func;
		break;
	}
}

double Integrals::metod_centre() {
	double h = (b - a) / n;   // shag razbieniya
	double p = h / 2;  // polovina shaga razbieniya
	double y = 0;
	double x1, x2, y1, y2;
	double tmp = 0;
	double s = 0;
	for (double x = a + p; x < b; x = x + h) {
		y = func(x, f);      //INTEGRAL
		x1 = x - p;
		x2 = x + p;
		y1 = y;
		y2 = 0;
		tmp = abs(x1 - x2) * abs(y1 - y2);
		s = s + tmp;
	}
	s_srednee = s_srednee + s;
	cout << "priblijonnoe znachenie (sredniy) = " << s << endl;
	return s;
}


double Integrals::metod_left() {
	double h = (b - a) / n;   // shag razbieniya
	double y = 0;
	double x1, x2, y1, y2;
	double tmp = 0;
	double s = 0;
	for (double x = a; x < b; x = x + h) {
		y = func(x, f);;      //INTEGRAL
		x1 = x;
		x2 = x + h;
		y1 = y;
		y2 = 0;
		tmp = abs(x1 - x2) * abs(y1 - y2);
		s = s + tmp;
	}
	s_srednee = s_srednee + s;
	cout << "priblijonnoe znachenie (leviy) = " << s << endl;
	return s;
}

double Integrals::metod_right() {
	double h = (b - a) / n;   // shag razbieniya
	double y = 0;
	double x1, x2, y1, y2;
	double tmp = 0;
	double s = 0;
	for (double x = a + h; x <= b; x = x + h) {
		y = func(x, f);       //INTEGRAL
		x1 = x - h;
		x2 = x;
		y1 = y;
		y2 = 0;
		tmp = abs(x1 - x2) * abs(y1 - y2);
		s = s + tmp;
	}
	s_srednee = s_srednee + s;
	cout << "priblijonnoe znachenie (praviy) = " << s << endl;
	return s;
}

double Integrals::sr_znach() {
	s_srednee = s_srednee / 3;
	cout << "srednyaya velichina = " << s_srednee << endl;
	return s_srednee;
}
