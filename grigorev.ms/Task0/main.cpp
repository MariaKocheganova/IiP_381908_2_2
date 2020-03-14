#include "CString.h"
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	CString s1;
	CString s2(10, '*');
	CString s3(s2);
	CString s4("123456");
	CString s5, s6;
	s1 = s2 + s4;
	cout << s1 << endl;
	s1 = s1 + s4;
	cout << s1 << endl;
	s1 += s2;
	cout << s1 << endl;
	cin >> s5 >> s6;
	cout << s5 << endl << s6 << endl;
	cout << s5 + s6 << endl;
	s5 = s5 * 10;
	cout << s5 << endl;
	s5 = s3 * 0;
	cout << "s5 = " << endl <<  s5 << "|" << endl;
	cout << sizeof(int);
	return 0;
}