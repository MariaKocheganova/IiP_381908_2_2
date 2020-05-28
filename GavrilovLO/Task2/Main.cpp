#include"Header.h"
#include<stdlib.h>
#include <cassert>
#include <fstream>
using namespace std;
void main() {
	Polinom f;
	Polinom f1;
	cin >> f;

	cin >> f1;
	f.zapicvfail();
	f.ctenie_s_fail();
	f.proizvodnia();
	f.sum();
	f.chet_x();
	f.ctenie_s_fail();
	cin >> f1;

	getchar();
	getchar();
}