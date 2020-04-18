#pragma once
using namespace std;
#include<iostream>
#include<string>

string Reverse(string a);
string ItoS(int a);
unsigned int StoI(string a);

string Summ_str(string a, string b);
string Mins_str(string a, string b);
string Multpl_str(string a, string b);
string Divs_str(string a, string b);

int Compare(string a, string b);

class LongLong {

private:
	unsigned int old, young;

public:

/*---------------Конструкторы---------------*/
	LongLong() { old = 0; young = 0; }
	LongLong(unsigned int old_copy, unsigned int young_copy) { old = old_copy, young = young_copy; }
	LongLong(const LongLong& copy);
	LongLong(string a);
	
/*---------------Методы---------------*/
	void SetOld(unsigned int old_copy);
	void SetYoung(unsigned int young_copy);
	unsigned int GetOld();
	unsigned int GetYoung();
	
/*---------------Переопределение операторов---------------*/
	LongLong operator+(LongLong& copy);
	LongLong operator-(LongLong& copy);
	LongLong operator*(LongLong& copy);
	LongLong operator/(LongLong& copy);
	LongLong& operator=(const LongLong& copy);
	friend istream& operator>>(istream& is, LongLong& copy);
	friend ostream& operator<<(ostream& os, LongLong& copy);

};

LongLong Str_To_LongLong(string a);
string LongLong_To_Str(LongLong& a);
istream& operator>>(istream& is, LongLong& copy);
ostream& operator<<(ostream& os, LongLong& copy);