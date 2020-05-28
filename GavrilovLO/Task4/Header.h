#pragma once
#include<iostream>
#include <cassert>
#include<math.h>
#include <ctime>   
#include <fstream>
using namespace std;
class Shagomer {
private:
public:
	int shagi[50];
	int  dd[50], mes[50], gg[50], hh[50], mm[50], ss[50];
	int i1;
	Shagomer::Shagomer();
	friend	istream& operator>>(istream& is, Shagomer &s);
	void Shagomer::srednee();
	void Shagomer::maximym();
	friend ostream& operator<<(ostream& os, Shagomer &s);
};
class Shag {
private:
	int dd1, dd2, mes1, mes2, gg1, gg2, hh1, hh2, mm1, mm2, ss1, ss2;
public:
	friend		istream& operator>>(istream& is, Shag &s);
	void Shag::info(Shagomer&s1);
};
class hz {
private:
public:
	int shagi2[50];
	int  dd3[50], mes3[50], gg3[50], hh3[50], mm3[50], ss3[50];
	friend	istream& operator>>(istream& is, hz &s);
};