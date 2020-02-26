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
	CString(CString& string);
	CString(char* string);
	~CString();
	int GetSize();
	int GetLen();
	void OutPut(const char* name);
};