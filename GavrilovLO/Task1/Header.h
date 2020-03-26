#pragma once
#include<iostream>
#include <cassert>
using namespace std;
class Money {
private:
	int rub;
	int kop;

public:
	double res10;
	double res11;
	double res12;
	Money::Money();
	int Money::Preobr(double s);
	Money::Money(const Money &copy) :rub(copy.rub), kop(copy.kop) {};//конструктор копирования
	friend Money operator+(const Money& s, const Money& s1);
	void Money::Input_money();
	void Money::Output_money();
	friend Money operator*(const Money& s, int n);
	friend Money operator==(const Money&s, const Money& s1);
	Money::Money() :res10(6, 0), res11(44, 13), res12(12, 33);
	Money::~Money();
	friend Money operator/(const Money& s, int n);
	friend istream& operator>>(istream& is, Money &s);
	friend ostream& operator<<(ostream& os, Money &s);

};
istream& operator>>(istream& is, Money &s);


