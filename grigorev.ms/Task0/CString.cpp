#include "CString.h"
using namespace std;
CString::CString() {
	size = 0;
	len = 0;
	str = 0;
}
CString::CString(int s, char sym) {
	size = s + 1;
	len = s;
	str = new char[size];
	for (int i = 0; i < len; i++) {
		str[i] = sym;
	}
	str[len] = 0;
}
CString::CString(const CString& string) {
	size = string.GetSize();
	len = string.GetLen();
	str = new char[size];
	for (int i = 0; i < size; i++) {
		str[i] = string.GetSym(i);
	}
	str[len] = 0;
}
CString::CString(char* string) {
	int i = 0;
	while (string[i] != 0)	i++;
	size = i + 1;
	len = i;
	str = new char[size];
	for (i = 0; i < size; i++) {
		str[i] = string[i];
	}
}
CString::~CString() {
	size = 0;
	len = 0;
	delete []str;
}
CString CString::operator+(const CString& a) {
	CString res;
	res.len = len + a.len;
	res.size = res.len + 1;
	res.str = new char[res.size];
	for (int i = 0; i < len; i++)
		res.str[i] = str[i];
	for (int i = 0; i < a.len; i++)
		res.str[len + i] = a.str[i];
	res.str[res.size - 1] = 0;
	return res;
}
CString CString::operator*(int a) {
	CString res;
	res.len = len * a;
	res.size = res.len + 1;
	res.str = new char[res.size];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < len; j++) {
			res.str[i * len + j] = str[j];
		}
	}
	res.str[res.size - 1] = 0;
	return res;
}
CString& CString::operator=(const CString& a) {
	len = a.len;
	size = a.size;
	delete []str;
	str = new char[size];
	for (int i = 0; i < a.len; i++) {
		str[i] = a.str[i];
	}
	str[size - 1] = 0;
	return *this;
}
CString& CString::operator+=(const CString& a) {
	char* ftstr = new char[size];
	int ftlen = len;
	for (int i = 0; i < len; i++) {
		ftstr[i] = str[i];
	}
	ftstr[size - 1] = 0;
	len = len + a.len;
	size = len + 1;
	delete []str;
	str = new char[size];
	for (int i = 0; i < ftlen; i++)
		str[i] = ftstr[i];
	for (int i = 0; i < a.len; i++)
		str[ftlen + i] = a.str[i];
	str[size - 1] = 0;
	delete []ftstr;
	return *this;
}
istream& operator>>(istream& is, CString& a) {
	char s[255];
	int i = 0;
	is.getline(s, 255);
	while (s[i] != 0) { i++; }
	a.len = i;
	a.size = i + 1;
	a.str = new char[a.size];
	for (int j = 0; j < i; j++) {
		a.str[j] = s[j];
	}
	a.str[a.len] = 0;
	return is;
}
ostream& operator<<(ostream& os, CString& a) {
	os << a.str;
	return(os);
}