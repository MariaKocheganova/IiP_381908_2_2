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

CString::CString(const CString& string)
{
	len = string.len;
	size = string.size;
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
	delete[] str;

	len = 0;
	size = 0;
	str = NULL;
}

void CString::OutPut(const char* name)
{
	cout << name << ": " << str << endl;
	
}


Cstring& CString::operator=(const CString& s) //=
{
	if (size < (s.len + 1))
	{
		delete[]str;
		size = s.len + 1;
		str = new char[size];
		len = s.len;
	}
	for (int i = 0; i <= len + 1; i++)
	{
		str[i] = s.str[i];

		return *this;
	}
}


Cstring& CString::operator+(const CString& s) //+
{
	CString res;
	res.len = len + s.len;
	res.str = new char[res.size];

	int i = 0;
	while (str[i])
	{
		res.str[i] = str[i];
		i++;
	}
	int j = 0;
	while (s.str[j])
	{
		res.str[i + j] = s.str[j];
		j++;
	}
	res.str[i + j] = 0;
	return res;
}



CString& CString::operator+=(const CString& s) //+=
{
	if (size < len + s.len)
	{
		size = len + s.len + 1;
		char* temp = new char[size];
		int i = 0;
		while (str[i])
		{
			temp[i] = str[i];
			i++;
		}
		delete[]str;
		str = temp;
	}
	int i = 0;
	while (s.str[i])
	{
		str[len + i] = s.str[i];
		i++;
	}
	len = len + i;
	str[len] = 0;

	return *this;
}


istream& operator>>(istream& is, CString&_s) // ббнд
{
	char ss[255];
	is.GetLine(ss, 255);
	s = ss;
	return is;
}

ostream& operator<<(istream& os, CString& s) // бшбнд
{
	os << s.str << endl;
	return os;
}