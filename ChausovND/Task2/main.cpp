#include "Polinom.h"
#include <iostream>
using namespace std;

int main()
{
	int menu1, menu2, menu3, menu4, v1 = 0, v2 = 0, v3 = 0; 
	double v4 = 0.0;
	bool flag = true;
	Polinom P1(v1), P2(v2), P3, P4;
	ifstream in; ofstream out;

	while (flag)
	{
		cout << "Input from: 1 - keyboard; 2 - file\n";
		cin >> menu1;

		switch (menu1)
		{
		case 1:
			cout << "Choose an action:\n1) Form a polynomial\n2) Find the derivative\n3) Find the value at X\n4) Summarize two polynomials\n";
			cin >> menu2;
			switch (menu2)
			{
			case 1:
				cout << "Enter the max power of the polynomial:\n";
				cin >> v1;
				cout << "Enter the coefficients of the polynomial:\n";
				cin >> P1;
				break;
			case 2:
				cout << "Enter the max power of the polynomial:\n";
				cin >> v1;
				cout << "Enter the coefficients of the polynomial:\n";
				cin >> P1;
				break;
			case 3:
				cout << "Enter the max power of the polynomial:\n";
				cin >> v1;
				cout << "Enter the coefficients of the polynomial:\n";
				cin >> P1;
				cout << "Enter x\n";
				cin >> v4;
				break;
			case 4:
				cout << "Enter the max powers of the two respective polynomials:\n";
				cin >> v1 >> v2;
				cout << "Enter the coefficients of the first polynomial:\n";
				cin >> P1;
				cout << "Enter the coefficients of the second polynomial:\n";
				cin >> P2;
				break;
			}
			break;
		case 2:
			cout << "Reading from file...\n";
			ifstream in;
			in.open("C:\\Users\\geekc\\Desktop\\input.txt");
			in >> v1 >> v2 >> v4 >> P1 >> P2;
			in.close();
			break;
		}

		cout << "Output to: 1 - console; 2 - file\n";
		cin >> menu3;

		switch (menu3)
		{
		case 1:
			switch (menu2)
			{
			case 1:
				cout << "The polynomial:" << P1 << "\n";
				break;
			case 2:
				cout << "The derivative:" << P1.OrigDeriv() << "\n";
				break;
			case 3:
				cout << "The value at x:" << P1.xValue(v4) << "\n";
				break;
			case 4:
				cout << "Two polynomials summarized:" << (P4 = P1 + P2) << "\n";
				break;
			}
			break;
		case 2:
			switch (menu2)
			{
			case 1:
				out.open("C:\\Users\\geekc\\Desktop\\output.txt");
				out << "The polynomial:" << P1 << "\n";
				cout << "Done.\n";
				break;
			case 2:
				out.open("C:\\Users\\geekc\\Desktop\\output.txt");
				out << "The derivative:" << P1.OrigDeriv() << "\n";
				cout << "Done.\n";
				break;
			case 3:
				out.open("C:\\Users\\geekc\\Desktop\\output.txt");
				out << "The value at x:" << P1.xValue(v4) << "\n";
				cout << "Done.\n";
				break;
			case 4:
				out.open("C:\\Users\\geekc\\Desktop\\output.txt");
				out << "Two polynomials summarized:" << (P4 = P1 + P2) << "\n";
				cout << "Done.\n";
				break;
			}
			break;
		}
		cout << "Operation complete. 1 - start over, 2 - exit\n";
		cin >> menu4;
		if (menu4 == 2)
			flag = false;
	}
}