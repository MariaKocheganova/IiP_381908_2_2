#pragma once
# include <iostream>
#include <clocale> 
#include <fstream>

using namespace std;

class Money {

private:

	int rub;
	int cop;

public:

	//контрукторы
	Money();
	Money(int _rub, int _cop);
	Money(int c);
	Money(const Money& c);
	~Money();

	//операторы

	void output();
	void input();
	Money& operator =(const Money& c);
	bool operator ==(const Money& c);

	friend Money operator +(const Money& c, const Money& c1);
	Money operator -(const Money& c);
	Money operator * (double c);
	Money operator / (double c);

	bool operator <(const Money& c);
	bool operator >(const Money& c);

	friend ostream& operator<<(ostream& os, const Money& c);
	friend istream& operator>>(istream& is, Money& c);
};

