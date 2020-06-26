#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Polinom
{
public:
	Polinom &operator=(const Polinom &);
	Polinom operator+(const Polinom &); 
	friend ostream &operator<<(ostream &s, const Polinom &v);
	friend istream &operator>>(istream &s, Polinom &v);
	double xValue(double x);
	Polinom OrigDeriv();
	double &operator[](int xx);
	Polinom equalPowers(Polinom);
	Polinom();
	~Polinom();
	Polinom(int power2);
	Polinom(const Polinom &);

private:
	int power;
	double *coeff;
};