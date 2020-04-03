#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
void main() {
	setlocale(LC_CTYPE, "Russian");
	Menu m(10, 5, 30, 3, "File Main View");
	m.Out(m);
	system("PAUSE");
}