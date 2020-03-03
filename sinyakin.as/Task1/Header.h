#pragma once
#include <iostream>

class CString
{
private:
	int size;
	int len;
	char* str;
public:
	CString();
	CString(int s,char sym = '*');
	CString(const CString& string);
	CString(char* string);
	~CString();
	int GetSize();
	int GetLen();
	void OutPut(const char* name);
	CString& operator=(const CString& s); //=
	CString& operator+(const CString& s);   //+
	CString& operator+=(const CString& s); //+=
	friend istream& operator>>(istream& is, CString& s);
	friend ostream& operator<<(istream& os, CString& s);
};