#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Octal {
private:
	int len;
	char* num;
public:
	int get_len() { return len; }
	char* get_num() { return num; }
	Octal() { len = 0; num = 0; }
	Octal(const Octal& a);
	Octal(char* a);
	~Octal() { len = 0; delete[] num; }
	Octal& operator=(const Octal& a);
    bool operator<(const Octal& a);
	bool operator>(const Octal& a);
	Octal operator+(const Octal& a);
	Octal operator-(const Octal& a);
	char get_sym(int ind);
	friend ifstream& operator>>(ifstream& is, Octal& a);
	friend ofstream& operator<<(ofstream& os, Octal& a);
};
ifstream& operator>>(ifstream& is, Octal& a);
ofstream& operator<<(ofstream& os, Octal& a);