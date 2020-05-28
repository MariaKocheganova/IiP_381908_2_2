#pragma once
#include<iostream>
#include <cassert>
using namespace std;
class Polinom {
private:
	int n;
	double koef2[40];

public:
	Polinom::~Polinom();
	Polinom::Polinom();
	friend istream& operator>>(istream& is, Polinom &s);

	double Polinom::sum();
	void Polinom::summa2pol(Polinom &s, Polinom &s1);  //сложение 2 полиномов
	void Polinom::output();
	double Polinom::chet_x();
	void Polinom::proizvodnia();
	void Polinom::zapicvfail();
	friend Polinom operator+(Polinom &s, Polinom &s1);
	Polinom Polinom::kopirovania();
	void Polinom::ctenie_s_fail();
	double&  operator[](int i);
}
;//инициализатор,преобразования
