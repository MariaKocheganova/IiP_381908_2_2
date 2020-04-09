#include "Time.h"

int main() {
	string tt = "13:40:00";
	Time a(13,41,12), b(13, 30, 10), c(a), d(tt), e;
	e = a + b;
	cout << e << endl;
	e = a - b;
	cout << e << endl;

	return 0;
}