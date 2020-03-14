#pragma once
#include<iostream>
using namespace std;
class LongLong {
private:
	unsigned int old, young;
	bool sign;
public:
	LongLong() { old = 0; young = 0; sign = false; };
	LongLong(const LongLong& a) { old = a.old; young = a.young; sign = a.sign; };
	LongLong(char* a);
	~LongLong() { old = 0; young = 0; sign = false; };
	unsigned int Get_Old() const { return old; }
	unsigned int Get_Young() const { return young; }
	LongLong& operator=(const LongLong& a);
	LongLong operator+(const LongLong& a);
	LongLong operator-(const LongLong& a);
	LongLong operator*(const LongLong& a);
	LongLong operator/(const LongLong& a);
	LongLong operator<(const LongLong& a);
	LongLong operator>(const LongLong& a);
	friend istream& operator>>(istream& is, LongLong& a);
	friend istream& operator<<(ostream& os, LongLong& a);
};
istream& operator>>(istream& is, LongLong& a);
istream& operator<<(ostream& os, LongLong& a);
char* Reverse(char* a);
bool Compare(char* a, char* b);
char* Minus_Str(char* a, char* b);
char* Plus_Str(char* a, char* b);
char* Mul_Str(char* a, char* b);
char* Div_Str(char* a, char* b);