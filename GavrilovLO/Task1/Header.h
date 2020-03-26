#pragma once
#include<iostream>
using namespace std;
class Money {
private:
	int rub;
	int kop;
	int n;
	double s;

public:
	Money::Money();
	friend Money operator+(const Money& s, const Money& s1);
	void Money::Input_money();
	void Money::Output_money();
	friend Money operator*(const Money& s, int n);
	friend Money operator==(const Money&s, const Money& s1);
	Money& operator+=(Money& s);
	Money::~Money();
	friend Money operator/(const Money& s, int n);
	friend istream& operator>>(istream& is, Money &s);
	friend ostream& operator<<(ostream& os, Money &s);
};
istream& operator>>(istream& is, Money &s);

