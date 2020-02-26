#include "CString.h"
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	CString s1;
	CString s2(10, '*');
	CString s3(s2);
	CString s4("123456");
	s1.Output();
	s2.Output();
	s3.Output();
	s4.Output();
	return 0;
}