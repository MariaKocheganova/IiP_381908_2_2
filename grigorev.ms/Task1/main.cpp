#include"LongLong.h"
#include<iostream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << Reverse("12345") << endl;
	cout << Compare("5005", "1000101") << endl;
	cout << Reverse(Plus_Str("005", "005")) << endl;
	cout << Reverse(Minus_Str(Reverse("10003"), Reverse("52"))) << endl;
	cout << Reverse(Mul_Str(Reverse("999"), Reverse("0"))) << endl;
	cout << Reverse(Div_Str(Reverse("5"), Reverse("5"))) << endl;
	cout << Reverse(Div_Str(Reverse("1000"), Reverse("300"))) << endl;
	cout << Reverse(Div_Str("4321", "5927694924")) << endl;
	LongLong a("8589934592");
	cout << a.Get_Old() << " " << a.Get_Young() << endl;
	return 0;
}