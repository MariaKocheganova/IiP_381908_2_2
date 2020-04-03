#include "Header.h"
using namespace std;
void main() {
	CTime t1, t2(6, 45, 8), t3, t5, t6, t7, t8("14:25:03");
	char* s = t2.TtoStr();
	int tmp = (t2 == t5);
	cin >> t3 >> t5;
	cout << endl;
	cout << endl;
	CTime t4(t3);
	t6 = t2 + t3;
	t7 = t4 - t5;
	for (int i = 0; i < 8; i++) cout << s[i];
	cout << endl << endl;
	cout << tmp << endl << t1 << endl << t2 << endl << t3 << endl << t4 << endl << t5 << endl << t6 << endl << t7 << endl << t8;

}