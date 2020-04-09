#include"Octal.h"
#include<iostream>
#include<fstream>
Octal::Octal(const Octal& a) {
	len = a.len;
	num = new char[len + 1];
	for (int i = 0; i < len; i++) {
		num[i] = a.num[i];
	}
	num[len] = 0;
}
Octal::Octal(char* a) {
	len = 0;
	while (a[len] != 0) { len++; }
	bool check = true;
	for (int i = 0; i < len; i++) {
		if (a[i] < '0' || a[i] > '7') {
			check = false;
		}
	}
	if (check) {
		num = new char[len + 1];
		for (int i = 0; i < len; i++) {
			num[i] = a[len - 1 - i];
		}
		num[len] = 0;
	}
	else {
		cout << "Ошибка, число не соответсвует требуемой системе счисления" << endl;
	}
}
Octal& Octal::operator=(const Octal& a) {
	len = a.len;
	delete[] num;
	num = new char[len + 1];
	for (int i = 0; i < len; i++) {
		num[i] = a.num[i];
	}
	num[len] = 0;
	return *this;
}
Octal Octal::operator+(const Octal& a) {
	Octal answer;
	int range, max, s, ost = 0;
	(len < a.len) ? range = len : range = a.len;
	(len < a.len) ? max = a.len : max = len;
	answer.len = max + 1;
	answer.num = new char[answer.len + 1];
	for (int i = 0; i < answer.len + 1; i++) { answer.num[i] = '0'; }
	for (int i = 0; i < range; i++) {
		s = ost + num[i] + a.num[i] - '0' - '0';
		ost = s / 8;
		s = s % 8;
		answer.num[i] = s + '0';
	}
	if (len < a.len) {
		for (int i = range; i < max; i++) {
			s = ost + a.num[i] - '0';
			ost = s / 8;
			s = s % 8;
			answer.num[i] = s + '0';
		}
	}
	else {
		for (int i = range; i < max; i++) {
			s = ost + num[i] - '0';
			ost = s / 8;
			s = s % 8;
			answer.num[i] = s + '0';
		}
	}
	answer.num[answer.len] = 0;
	return answer;
}
bool Octal::operator<(const Octal& a) {
	if (len < a.len) { return true; }
	else if (len > a.len) { return false; }
	else {
		int pos = len - 1;
		while (num[pos] == a.num[pos] && pos >= 0) { pos--; }
		if (num[pos] < a.num[pos]) { return true; }
		else { return false; }
	}
}
bool Octal::operator>(const Octal& a) {
	if (len > a.len) { return true; }
	else if (len < a.len) { return false; }
	else {
		int pos = len - 1;
		while (num[pos] == a.num[pos] && pos >= 0) { pos--; }
		if (num[pos] > a.num[pos]) { return true; }
		else { return false; }
	}
}
Octal Octal::operator-(const Octal& a) {
	Octal answer;
	/*if (*this < a) {
		answer.len = a.len;
		answer.num = new char[answer.len + 1];
		for (int i = 0; i < a.len; i++) { answer.num[i] = '0'; }
		for (int i = 0; i < len; i++) {
			while (a.num[i] < num[i] && i < len - 1) { a.num[i] = a.num[i] + 8; a.num[i + 1] --; }
			answer.num[i] = a.num[i] - num[i] + '0';
		}
		for (int i = len; i < a.len; i++) {
			while (a.num[i] < num[i] && i < a.len - 1) { a.num[i] = a.num[i] + 8; a.num[i + 1] --; }
			answer.num[i] = a.num[i] + '0';
		}
		answer.num[answer.len] = 0;
	}
	else if (*this > a) {
		answer.len = len;
		answer.num = new char[len + 1];
		for (int i = 0; i < len; i++) { answer.num[i] = '0'; }
		for (int i = 0; i < a.len; i++) {
			while ((num[i] < a.num[i]) && (i < a.len - 1)) { num[i] = num[i] + 8; num[i + 1] = num[i + 1] - 1; }
			answer.num[i] = num[i] - a.num[i] + '0';
		}
		for (int i = a.len; i < len; i++) {
			while (num[i] < a.num[i] && i < len - 1) { num[i] = num[i] + 8; num[i + 1] --; }
			answer.num[i] = num[i] + '0';
		}
		answer.num[answer.len] = 0;
	}
	else {
		answer.len = 1;
		answer.num = new char[2];
		answer.num[0] = '0';
		answer.num[1] = 0;
	}*/
	int num1 = 0, num2 = 0;
	for (int i = 0; i < len; i++) {
		num1 = num1 + (num[i] - '0') * pow(8, i);
	}
	for (int i = 0; i < a.len; i++) {
		num2 = num2 + (a.num[i] - '0') * pow(8, i);
	}
	int num3 = abs(num1 - num2);
	char num3_c[255];
	int pos = 0;
	while (num3 != 0) {
		num3_c[pos] = (num3 % 8) + '0';
		num3 = num3 / 8;
		pos++;
	}
	answer.num = new char[pos+1];
	for (int i = 0; i < pos; i++) {
		answer.num[i] = num3_c[i];
	}
	answer.num[pos] = 0;
	answer.len = pos;
	return answer;
}
char Octal::get_sym(int ind) {
	if (ind < 0 || ind > len) { cout << "Ошибка" << endl; return num[0]; }
	else { return num[ind]; }
}
ifstream& operator>>(ifstream& is, Octal& a) {
	char s[255];
	is.getline(s, 255);
	a.len = 0;
	while (s[a.len] != 0) { a.len++; }
	delete[] a.num;
	a.num = new char[a.len + 1];
	for (int i = 0; i < a.len; i++) {
		a.num[i] = s[a.len - i - 1];
	}
	a.num[a.len] = 0;
	return is;
}
ofstream& operator<<(ofstream& os, Octal& a) {
	for (int i = 0; i < a.len; i++) { os << a.num[a.len - 1 - i]; }
	os << "(8)";
	return os;
}