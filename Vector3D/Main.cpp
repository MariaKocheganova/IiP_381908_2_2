#include <iostream>
#include "Vecor3D.h"

using namespace std;

int main() {
	Vector3d a(0, 0, 0);
	Vector3d b(5, 2, 3);
	Vector3d c(2, 6, 7);

	cin >> a;

	if (a == b) cout << "\nTrue";
	if (a != c) cout << "\nFalse";

	cout << "\na: " << a;
	cout << "\nb: " << b;
	cout << "\nc: " << c;

	a = a * 5;

	cout << "\nScalMult a * 5 = " << a;

	cout << "\n\n";
	system("pause");
}