#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Vector3D v(1.0, 2.0, 3.0);

	cout << "Vector1 = " << v;
	v = v * 3;
	cout << "\nVector1 * 3 = " << v;

	system("pause");
	getchar();
}