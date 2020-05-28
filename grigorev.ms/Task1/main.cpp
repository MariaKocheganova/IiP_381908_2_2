#include"LongLong.h"
#include<iostream>
#include<string>
using namespace std;
int main() {
	string ans;
	ans = Summ_str("999", "999");
	cout << ans << endl;
	cout << Reverse("321") << endl;
	cout << Reverse(Multpl_str("1234", "999")) << endl;
	cout << Reverse(Mins_str("0004", "0")) << endl;
	cout << Reverse(Divs_str("123", "35")) << endl;
	cout << Compare("321", "077777") << endl;
	cout << sizeof(unsigned int) << endl;
	cout << StoI("321321") << endl;
	cout << ItoS(123123) << endl;
	Str_To_LongLong("123");
	LongLong a, b, c;
	cin >> a;
	cin >> b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	c = a + b;
	cout << "c = a + b = ";
	cout << c << endl;
	c = a - b;
	cout << "c = a - b = " << c << endl;
	c = a * b;
	cout << "c = a * b = " << c << endl;
	c = a / b;
	cout << "c = a / b = " << c << endl;
	LongLong abs[10];
	cin >> abs[3];
}