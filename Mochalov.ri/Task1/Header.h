#pragma once
#include<iostream>
using namespace std;
class CTime {
	unsigned int hou, min, sec;
public:
	CTime();
	CTime(int h, int m, int s);
	CTime(const CTime& t);
	CTime(const char s[9]);
	~CTime();
	char* TtoStr();
	CTime& operator=(const CTime& t);
	friend CTime operator+(const CTime& t, const CTime& t1);
	friend CTime operator+(const CTime& t, const int s);
	friend CTime operator-(const CTime& t, const CTime& t1);
	friend bool operator==(const CTime& t, const CTime& t1);
	friend istream& operator>>(istream& is, CTime& t);
	friend ostream& operator<<(ostream& os, const CTime& t);
};
CTime operator+(const CTime& t, const CTime& t1);
CTime operator+(const CTime& t, const int s);
CTime operator-(const CTime& t, const CTime& t1);
bool operator==(const CTime& t, const CTime& t1);
istream& operator>>(istream& is, CTime& t);
ostream& operator<<(ostream& os, const CTime& t);