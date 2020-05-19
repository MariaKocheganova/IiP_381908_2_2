#include "Polinom.h"
#include <iostream>
using namespace std;

int main()
{
	int v1=0, v2=0, v3=0; double v4=0.0;
	Polinom P1(v1), P2(v2), P3, P4;
	ifstream in; ofstream out;

	cout << "Input from: 1 - keyboard; 2 - file\n"; 
	cin >> v1;
	cout << "Enter the max powers of two polynomials:\n"; 
	cin >> v2 >> v3;

	switch (v1) 
	{
		case 1:
			cout << "Enter x\n";
			cin >> v4;
			cout << "Enter the coefficients of the first polynomial:\n";
			cin >> P1;
			cout << "Enter the coefficients of the second polynomial:\n";
			cin >> P2;
			break;

		case 2:
			in >> v4;
			in >> P1;
			in >> P2;
	}

		cout << "The first polynomial:" << P1 << "\n";
		cout << "The second polynomial:" << P2 << "\n";
		cout << "Two polynomials summarized:" << (P4 = P1 + P2) << "\n";
		cout << "Derivative of the first one:" << P1.OrigDeriv() << "\n";
		cout << "Value of the first one at x:" << P1.xValue(v4) << "\n";

		out.open("Polinom.txt");
		out << "The first polynomial:" << P1 << "\n";
		out << "The second polynomial:" << P2 << "\n";
		out << "Two polynomials summarized:" << P4 << "\n";
		out << "Derivative of the first one:" << P1.OrigDeriv() << "\n";
		out << "Value of the first one at x:" << P1.xValue(v4) << "\n";
		out.close();

		system("pause");
}