#include "LongLong.h"
#include<iostream>
#include<cmath>
using namespace std;
char* Cut(char* a) {
	int size = 0;
	while (a[size] != 0) { size++; }
	char* answer = new char[size + 1];
	for (int i = 0; i < size; i++) { answer[i] = a[i]; }
	int pos = size - 1;
	while (a[pos] == '0' && pos >= 0) { pos--; }
	if (pos == -1) { answer[1] = 0; }
	else {
		answer[pos + 1] = 0;
	}
	return answer;
}
char* Reverse(char* a) {
	int size = 0;
	while (a[size] != 0) { size++; }
	char* answer = new char[(size + 1)];
	for (int i = 0; i < size; i++) {
		answer[i] = a[size - 1 - i];
	}
	answer[size] = 0;
	return(Cut(answer));
}
bool Compare(char* a, char* b) {  //Проверка того, что a < b
	a = Cut(a);
	b = Cut(b);
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
		ost = 0;
		while (s >= 10) {
			ost = ost + 1;
			s = s - 10;
		}
		answer[i] = s + '0';
	}
	if (size_a < size_b) {
		for (int i = range; i < max; i++) {
			s = b[i] + ost - '0';
			ost = 0;
			while (s >= 10) {
				ost = ost + 1;
				s = s - 10;
			}
			answer[i] = s + '0';
		}
		if (ost != 0) { answer[max] = ost + '0'; }
	}
	else {
		for (int i = range; i < max; i++) {
			s = a[i] + ost - '0';
			ost = 0;
			while (s >= 10) {
				ost = ost + 1;
				s = s - 10;
			}
			answer[i] = s + '0';
		}
		if (ost != 0) { answer[max] = ost + '0'; }
	}
	answer[max+1] = 0;
	return(Cut(answer));
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
			answer[i] = b[i] - a[i] + '0';
		}
		for (int i = range; i < max; i++) {
			while (b[i] < '0') { b[i] = b[i] + 10; b[i + 1] = b[i + 1] - 1; }
			answer[i] = b[i];
		}
		answer[max] = 0;
	}
	return(Cut(answer));
}
char* Mul_Str(char* a, char* b) {
	int size_a = 0, size_b = 0, s = 0, ost = 0;
	while (a[size_a] != 0) { size_a++; }
	while (b[size_b] != 0) { size_b++; }
	char** mas = (char**)malloc(size_b * sizeof(char*));
	cout << "Test1 - " << mas << endl;
	for (int i = 0; i < size_b; i++) {
		//mas[i] = new char[(size_a + 2 + i)];
		mas[i] = (char*)malloc((size_a + 2 + i) * sizeof(char));
		cout << "Test2 - " << mas[i] << endl;
		for (int j = 0; j < size_a + 2 + i; j++) { mas[i][j] = '0'; }
		for (int j = 0; j < size_a; j++) {
			s = (a[j] - '0') * (b[i] - '0') + ost;
			ost = s / 10;
			s = s % 10;
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
	for (int i = 0; i < size_b; i++) { delete[] mas[i]; }
	delete[]mas;
	return(Cut(answer));
}
char* Div_Str(char* a, char* b) {
	if (Compare(a, b) == true) { char* answer = new char[2]; answer[0] = '0'; answer[1] = 0; return answer; }
	else {
		char* answer = new char[2];
		answer[0] = '0';
		answer[1] = 0;
		int len_a = 0;
		while (a[len_a] != 0) { len_a++; }
		char* copy_a = new char[len_a + 1];
		for (int i = 0; i < len_a; i++) {
			copy_a[i] = a[i];
		}
		copy_a[len_a] = 0;
		while (Compare(copy_a, b) == false) {
			copy_a = Minus_Str(copy_a, b);
			answer = Plus_Str(answer, "1");
		}
		return(Cut(answer));
	}
}
char* Int_To_Str(unsigned int a) {
	int b = a, size = 0;
	while (b != 0) { size++; b = b / 10; }
	char* answer = new char[size + 1];
	for (int i = 0; i < size; i++) {
		answer[i] = (a % 10) + '0';
		a = a / 10;
	}
	return(answer);
}
int Str_To_Int(char* a) {
	int size = 0;
	while (a[size] != 0) { size++; }
	int answer = 0;
	for (int i = 0; i < size; i++) {
		answer = answer + (a[i] - '0') * pow(10, i);
	}
	return answer;
}
LongLong::LongLong(const LongLong& a){
	old = a.old;
	young = a.young;
}
LongLong::LongLong(char* a) {
		char* old_str = Div_Str(a, Reverse("4294967295"));
		char* young_str = Minus_Str(a, Mul_Str(Reverse("4294967295"), old_str));
		old = Str_To_Int(old_str);
		young = Str_To_Int(young_str);
		cout << "old = " << old << endl;
		cout << "young = " << young << endl;
		delete[]old_str;
		delete[]young_str;
}
LongLong& LongLong::operator=(const LongLong& a) {
	old = a.old;
	young = a.young;
	return *this;
}
LongLong LongLong::operator+(const LongLong& a) {
	LongLong answer;
	answer.old = old + a.old;
	char* prom = Plus_Str(Int_To_Str(young), Int_To_Str(a.young));
	char* cc = Div_Str(prom, Reverse("4294967295"));
	int cc_size = 0;
	while (cc[cc_size] != 0) { cc_size++; }
	int cc_num = 0;
	for (int i = 0; i < cc_size; i++) {
		cc_num = cc_num + (cc[i] - '0') * pow(10, i);
	}
	answer.old = answer.old + cc_num;
	cc = Mul_Str(cc, Reverse("4294967295"));
	char* young_str = Minus_Str(prom, cc);
	answer.young = 0;
	int young_size = 0;
	while (young_str[young_size] != 0) { young_size++; }
	for (int i = 0; i < young_size; i++) {
		answer.young = answer.young + (young_str[i] - '0') * pow(10, i);
	}
	return(answer);
}
LongLong LongLong::operator-(const LongLong& a) {
	LongLong answer;
	answer.old = old - a.old;
	char* prom = Minus_Str(Int_To_Str(young), Int_To_Str(a.young));
	int prom_size = 0;
	while (prom[prom_size] != 0) { prom_size++; }
	answer.young = 0;
	for (int i = 0; i < prom_size; i++) {
		answer.young = answer.young + (prom[i] - '0') * pow(10, i);
	}
	return answer;
}
LongLong LongLong::operator*(const LongLong& a) {
	LongLong answer;
	char* first = Plus_Str(Mul_Str(Int_To_Str(old), Reverse("4294967295")), Int_To_Str(young));
	char* second = Plus_Str(Mul_Str(Int_To_Str(a.old), Reverse("4294967295")), Int_To_Str(a.young));
	char* result = Mul_Str(first, second);
	char* old_str = Div_Str(result, Reverse("4294967295"));
	answer.old = Str_To_Int(old_str);
	old_str = Mul_Str(old_str, Reverse("4294967295"));
	answer.young = Str_To_Int(Minus_Str(result, old_str));
	return answer;
}
LongLong LongLong::operator/(const LongLong& a) {
	LongLong answer;
	char* first = Plus_Str(Mul_Str(Int_To_Str(old), Reverse("4294967295")), Int_To_Str(young));
	char* second = Plus_Str(Mul_Str(Int_To_Str(a.old), Reverse("4294967295")), Int_To_Str(a.young));
	char* result = Div_Str(first, second);
	answer.old = Str_To_Int(result);
	char* young_str = Minus_Str(first, Mul_Str(second, result));
	answer.young = Str_To_Int(young_str);
	return answer;
}
bool LongLong::operator<(const LongLong& a) {
	if (old < a.old) { return true; }
	else if (old == a.old && young < a.young) { return true; }
	else { return false; }
}
bool LongLong::operator>(const LongLong& a) {
	if (old > a.old) { return true; }
	else if (old == a.old && young > a.young) { return true; }
	else { return false; }
}
istream& operator>>(istream& is, LongLong& a) {
	char* s = new char[255];
	is.getline(s, 255);
	s = Reverse(s);
	char* old_str = Div_Str(s, Reverse("4294967295"));
	char* young_str = Minus_Str(s, Mul_Str(Reverse("4294967295"), old_str));
	a.old = Str_To_Int(old_str);
	a.young = Str_To_Int(young_str);
	return is;
}
ostream& operator<<(ostream& os, LongLong& a) {
	cout << a.old << "*o + " << a.young << endl;
	return(os);
}