#include"Header.h"
#include<stdlib.h>
#include <fstream>
#include<string>
using namespace std;


Polinom::Polinom() {


	n = 0;
	for (int i = 0; i <= 40; i++)
		koef2[i] = 0.0;
}
Polinom::~Polinom() {
	n = 0;

}
istream& operator>>(istream& is, Polinom &s) {
	is >> s.n;

	cout << "*********************\n";
	for (int i = 0; i <= s.n; i++) {
		is >> s.koef2[i];
	};
	for (int i = 0; i <= s.n; i++) {
		cout << s.koef2[i] << " ";
	}


	cout << "***************************** \n";
	return is;
}

double Polinom::sum() {

	double s;
	s = 0.0;
	for (int i = 0; i <= this->n; i++) {
		s = s + this->koef2[i];
	}
	cout << "\n";
	cout << s;
	return s;
}
void Polinom::summa2pol(Polinom &s, Polinom &s1) {
	Polinom res;
	cout << " \n";
	cout << "summa 2 polinomov \n";
	for (int i = 0; i <= s.n; i++) {
		res.koef2[i] = s.koef2[i] + s1.koef2[i];
		cout << res.koef2[i] << " ";
	}
}
Polinom operator+(Polinom &s, Polinom &s1) {
	Polinom res;
	if (s.n > s1.n) {
		for (int i = 0; i <= s.n; i++)

		{
			res.koef2[i] = s.koef2[i] + s1.koef2[i];
		}
		for (int i = 0; i <= s.n; i++) {
			if (i == 0)
			{
				cout << res.koef2[i] << "+";
			}
			else {
				if (i == s.n) {
					cout << res.koef2[i] << "x^" << i;
				}
				else {
					cout << res.koef2[i] << "x^" << i << "+";
				}
			}

		}

	}
	else {
		for (int i = 0; i <= s1.n; i++)
		{
			res.koef2[i] = s.koef2[i] + s1.koef2[i];
		}

		for (int i = 0; i <= s1.n; i++) {
			if (i == 0)
			{
				cout << res.koef2[i] << "+";
			}
			else {
				if (i == s1.n) {
					cout << res.koef2[i] << "x^" << i;
				}
				else {
					cout << res.koef2[i] << "x^" << i << "+";
				}
			}

		}
	}
	return res;// неявно исп конструктор копирования
}
void Polinom::output() {
	cout << "************************\n";
	cout << "************************\n";

	for (int i = 0; i <= this->n; i++) {
		if (i == 0)
		{
			cout << this->koef2[i] << "+";
		}
		else {
			if (i == this->n) {
				cout << this->koef2[i] << "x^" << i;
			}
			else {
				cout << this->koef2[i] << "x^" << i << "+";
			}
		}

	}
}
double Polinom::chet_x() {//возврат double
	double x;
	double znach;
	x = 0.0;
	znach = 0.0;
	cin >> x; // ввод c main
	for (int i = 0; i <= this->n; i++) {
		znach = znach + this->koef2[i] * pow(x, i);
	}
	cout << "  znach v tochke x =" << znach;
	return znach;
}
void Polinom::proizvodnia() {
	double s;
	double x;
	s = 0.0;
	x = 0.0;
	cin >> x;
	for (int i = 0; i <= this->n; i++) {//Polinom res
		if (i == 0) {
			koef2[i] = 0;
		}
		else {
			s = s + this->koef2[i] * i*pow(x, i - 1);
		}
	}
	cout << s << " proizvidnia ot polinoma";// Polinom res(return);
}
/*void Polinom::proizvodnia1() {
Polinom res;//gjkbyjd

}*/
void Polinom::zapicvfail() {
	ofstream out;
	out.open("C:\\gg\\gg20.txt");
	for (int i = 0; i <= this->n; i++) {
		if (i == 0) {
			out << this->koef2[i] << "+";
		}
		else {
			if (i == this->n) {
				out << this->koef2[i] << "x^" << i;
			}
			else {
				out << this->koef2[i] << "x^" << i << "+";

			}
		}
	}
	out.close();
	cout << "zapic proizochla";

}
Polinom Polinom::kopirovania() {
	Polinom kop;
	kop.n = this->n;
	for (int i = 0; i < n; i++) {
		kop.koef2[i] = this->koef2[i];
	}
	return kop;
}
void Polinom::ctenie_s_fail() {
	char per[50];
	ifstream file("C:\\gg\\gg20.txt");
	file.getline(per, 50);
	file.close();
	cout << "\n";
	cout << per;
}
double& Polinom:: operator[](int i) {
	return koef2[i];
}

//всё отдельно