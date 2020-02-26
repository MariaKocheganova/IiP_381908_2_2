#pragma once
#include <iostream>
using namespace std;
class CString {
private:
	int size;
	int len;
	char* str;
public:
	CString();
	CString(int s, char sym = '*');
	CString(const CString& string);
	CString(char* string);
	~CString();
	char GetSym(int ind) const { return str[ind]; };
	int GetSize() const { return size; };
	int GetLen() const { return len; };
	void Output() const {
		if(size != 0 || len != 0)
			cout << str << '\n'; 
	};
};