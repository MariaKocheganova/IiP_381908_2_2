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
	delete str;
}