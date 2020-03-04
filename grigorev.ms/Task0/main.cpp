#include "CString.h"
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	CString s1;
	CString s2(10, '*');
	CString s3(s2);
	CString s4("123456");
	CString s5;
	s1 = s2 + s4;
	cout << s1;
	s1 = s1 + s4;
	cout << s1;
	s1 += s2;
	cout << s1;
	cin >> s5;
	cout << s5;
	return 0;
}