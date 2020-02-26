#include "Header.h"
#include <iostream>
using namespace std;

CString::CString()
{
	size = 0;
	len = 0;
	str = 0;
}

CString::CString(int s, char sym = '*')
{
	len = s;
	size = s + 1;
	str = new char[size];

	for (int i = 0; i < len; i++)
	{
		str[i] = sym;
		str[len] = 0;
	}
}

CString::CString(CString& string)
{
	len = string.GetLen();
	size = string.GetSize();
	str = new char[size];
	for (int i = 0; i < size; i++)
	{
		str[i] = string.str[i];
	}
}

CString::CString(char* string)
{
	int n = 0;
	while (string[n] != 0)
		n++;
	len = n;
	size = n + 1;
	for (int i = 0; i < size; i++)
		str[i] = string[i];
}

CString::~CString()
{
	len = 0;
	size = 0;
	str = NULL;
	delete(str);
}

void CString::OutPut(const char* name)
{
	cout << name << ": " << str << endl;
	
}