#include"LongLong.h"
#include<iostream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	LongLong a("10000");
	LongLong b, c;
	cin >> b;
	char* answer = 0;
	answer = Reverse("0005000001");
	cout << answer << endl;
	delete[] answer;
	answer =  Cut(Plus_Str(Reverse("1000000000"), Reverse("5000")));
	cout << answer << endl;
	delete[] answer;
	answer = Cut(Minus_Str(Reverse("1000000000"), Reverse("5000")));
	cout << answer << endl;
	delete[] answer;
	answer = Mul_Str(Reverse("1000000000"), Reverse("5000"));
	cout << answer << endl;
	delete[] answer;
	/*answer = Div_Str(Reverse("1000000000"), Reverse("5000"));
	cout << answer << endl;
	delete[] answer;
	cout << "b = " << b << endl;
	c = a + b;
	cout << "c = " << c << endl;
	c = a - b;
	cout << "c = " << c << endl;
	c = a / b;
	cout << "c = " << c << endl;
	c = a * b;
	cout << "c = " << c << endl;*/
	return 0;
}