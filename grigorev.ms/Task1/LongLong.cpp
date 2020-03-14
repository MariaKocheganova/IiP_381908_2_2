#include "LongLong.h"
#include<iostream>
#include<cmath>
using namespace std;
char* Reverse(char* a) {
	int size = 0;
	while (a[size] != 0) { size++; }
	char* answer = new char[(size + 1)];
	for (int i = 0; i < size; i++) {
		answer[i] = a[size - 1 - i];
	}
	answer[size] = 0;
	return(answer);
}
bool Compare(char* a, char* b) {  //Проверка того, что a < b
	int size_a = 0, size_b = 0;
	while (a[size_a] != 0) { size_a++; }
	while (b[size_b] != 0) { size_b++; }
	if (size_a < size_b) { return true; }
	else if (size_a > size_b) { return false; }
	else {
		int pos = size_a - 1;
		while (a[pos] == b[pos]) { pos--; }
		if (a[pos] < b[pos]) { return true; }
		else { return false; }
	}
}
char* Plus_Str(char* a, char* b) {
	int size_a = 0, size_b = 0, range = 0, max = 0, s, ost = 0;
	while (a[size_a] != 0) { size_a++; }
	while (b[size_b] != 0) { size_b++; }
	(size_a < size_b) ? range = size_a : range = size_b;
	(size_a < size_b) ? max = size_b : max = size_a;
	char* answer = new char[max+2];
	for (int i = 0; i < max + 2; i++) { answer[i] = '0'; }
	for (int i = 0; i < range; i++) {
		s = a[i] + b[i] + ost - '0' - '0';
		if (s >= 10) {
			ost = 1;
			answer[i] = s - 10 + '0';
		}
		else {
			answer[i] = s + '0';
		}
	}
	if (size_a < size_b) {
		for (int i = range; i < max; i++) {
			s = b[i] + ost - '0';
			if (s >= 10) {
				ost = 1;
				answer[i] = b[i] + ost + '0';
			}
			else {
				answer[i] = s + '0';
			}
		}
		if (ost != 0) { answer[max] = ost + '0'; }
	}
	else {
		for (int i = range; i < max; i++) {
			s = a[i] + ost - '0';
			if (s >= 10) {
				ost = 1;
				answer[i] = a[i] + ost + '0';
			}
			else {
				answer[i] = s + '0';
			}
		}
		if (ost != 0) { answer[max] = ost + '0'; }
	}
	answer[max+1] = 0;
	return answer;
}
char* Minus_Str(char* a, char* b) {
	int size_a = 0, size_b = 0, range = 0, max = 0, s, ost = 0, pos;
	while (a[size_a] != 0) { size_a++; }
	while (b[size_b] != 0) { size_b++; }
	(size_a < size_b) ? range = size_a : range = size_b;
	(size_a < size_b) ? max = size_b : max = size_a;
	char* answer = new char(max + 1);
	if (Compare(a,b) == false) {
		for (int i = 0; i < range; i++) {
			while (a[i] < b[i]) { a[i] = a[i] + 10; a[i+1] = a[i+1] - 1; }
			answer[i] = a[i] - b[i] + '0';
		}
		for (int i = range; i < max; i++) {
			while (a[i] < '0') { a[i] = a[i] + 10; a[i + 1] = a[i + 1] - 1; }
			answer[i] = a[i];
		}
		answer[max] = 0;
	}
	else {
		for (int i = 0; i < range; i++) {
			while (b[i] < a[i]) { b[i] = b[i] + 10; b[i + 1] = b[i + 1] - 1; }
			answer[i] = a[i] - b[i] + '0';
		}
		for (int i = range; i < max; i++) {
			while (b[i] < '0') { b[i] = b[i] + 10; b[i + 1] = b[i + 1] - 1; }
			answer[i] = b[i];
		}
		answer[max] = 0;
	}
	return(answer);
}
char* Mul_Str(char* a, char* b) {
	int size_a = 0, size_b = 0, s = 0, ost = 0;
	while (a[size_a] != 0) { size_a++; }
	while (b[size_b] != 0) { size_b++; }
	char** mas = new char* [size_b];
	for (int i = 0; i < size_b; i++) {
		mas[i] = new char[size_a + 2 + i];
		for (int j = 0; j < size_a + 2 + i; j++) { mas[i][j] = '0'; }
		for (int j = 0; j < i; j++) { mas[i][j] = '0'; }
		for (int j = 0; j < size_a; j++) {
			s = (a[j] - '0') * (b[i] - '0') + ost;
			if (s >= 10) { ost = s / 10; s = s % 10; }
			mas[i][j + i] = s + '0';
		}
		mas[i][size_a + 1 + i] = 0;
	}
	char* answer = new char[2];
	answer[0] = '0';
	answer[1] = 0;
	for (int i = 0; i < size_b; i++) {
		answer = Plus_Str(answer, mas[i]);
	}
	return answer;
}
char* Div_Str(char* a, char* b) {
	char* answer = new char[2];
	answer[0] = '0';
	answer[1] = 0;
	answer = Reverse(answer);
	if (Compare(a, b) == true) {
		return answer;
	}
	char* ost = new char[2];
	ost[0] = '0';
	ost[1] = 0;
	ost = Reverse(ost);
	while (Compare(ost, a) == true) {
		ost = Plus_Str(ost, b);
		answer = Plus_Str(answer, "1");
	}
	ost = Minus_Str(ost, b);
	a = Minus_Str(a, ost);
	
	return answer;
}
LongLong::LongLong(char* a) {
	int size_a = 0;
	while (a[size_a] != 0) { size_a++; }
	a = Reverse(a);
	if (size_a != 0) {
		(a[0] == '-') ? sign = true : sign = false;
		char* old_char = Div_Str(a, "5927694924");
		cout << "old_char " << Reverse(old_char) << endl;
		old = 0;
		young = 0;
		int old_char_size = 0;
		while (old_char[old_char_size] != 0) { old_char_size++; }
		for (int i = 0; i < old_char_size; i++) {
			old = old + (old_char[i] - '0') * pow(10, i);
		}
		size_a = 0;
		while (a[size_a] != 0) { size_a++; }
		for (int i = 0; i < size_a; i++) {
			young = young + (a[i] - '0') * pow(10, i);
		}
	}
}
LongLong& LongLong::operator=(const LongLong& a) {
	sign = a.sign;
	old = a.old;
	young = a.young;
	return *this;
}