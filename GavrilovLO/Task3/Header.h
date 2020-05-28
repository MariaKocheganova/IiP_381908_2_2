#pragma once
#include<iostream>
#include <cassert>
#include<math.h>
using namespace std;
class Teilor {
private:
	int n;
	double koef2[20];
	double *koef;
	int a;
public:
	double Teilor::koeficienti();
	friend istream& operator>>(istream& is, Teilor &s);
	void Teilor::vivod_na_ikran();
	void Teilor::zad_chlen_riad();
	void Teilor::znach_riad();
};