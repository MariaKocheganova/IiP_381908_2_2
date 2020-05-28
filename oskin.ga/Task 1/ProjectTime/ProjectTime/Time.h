#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;
using std::string;
using std::basic_string;


class Time {
	int hou, min, sec;

public:
	Time();
	Time(int i, int j, int k);
	Time(const Time& a);
	Time(const string& a);
	~Time();
	Time& operator=(const Time& a);
	Time operator+(const Time& a);
	Time operator-(const Time& a);
	bool operator==(const Time& a);
	bool operator!=(const Time& a);
	bool operator>(const Time& a);
	bool operator<(const Time& a);
	bool operator>=(const Time& a);
	bool operator<=(const Time& a);
	friend ostream& operator<<(ostream& os, const Time& a);
	friend istream& operator>>(istream& is, Time& a);

};




