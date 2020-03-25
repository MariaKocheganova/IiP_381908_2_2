#include "Header.h"

using namespace std;


int main()
{
	int k;
	string s = "12.15:2000";
	setlocale(LC_CTYPE, "Russian");
	Date d0(20, 8, 2000);
	Date d1;
	Date d2(12, 5, 1990);
	Date d3;
	Date d5(6, 6, 1950);
	Date d7(6, 6, 1951);
	Date d8;
	Date d9;
	Date d10;
	Date d11(s);


	system("pause");
	return 0;
}
