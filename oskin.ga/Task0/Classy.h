#pragma once
#include <iostream>
#include <clocale>

using namespace std;

class Cstring
{
private:
	int size;
	int len;
	char* str;
	
	
public:
	Cstring();
	Cstring(int s, char sym = '*');
	Cstring(const Cstring& string);
	Cstring(char* string);
	~Cstring();
	Cstring* operator = (char& string);
	Cstring& operator=(const Cstring& cms);
	Cstring operator+(const Cstring& cms);
	Cstring& operator+=(const Cstring& cms);
	friend ostream& operator<<(ostream& stream, const Cstring& _str);
	friend istream& operator>>(istream& stream, const Cstring _str);
	

};

ostream& operator<<(ostream& stream, const Cstring& _str);
istream& operator>>(istream& stream, const Cstring& _str);


class Ccomplex
{
	double re;
	double im;
public:
	Ccomplex Add(Ccomplex a);
	Ccomplex Mlt(Ccomplex a);
	void InPut();
	void Output(Ccomplex a);
	void SetRe(double _re)
	{
		re = _re;
	}
	double GetRe()
	{
		return re;
	}
};
