#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"

int main()
{
	setlocale(LC_ALL, "");
	int n, m;
	double x;
	cout << "Введите степень полинома A и степень полинома B:" << '\n';
	cin >> n >> m;
	Polynom A(n);
	Polynom B(m);
	Polynom D;
	Polynom C;
	Polynom test;
	cout << "Введите коэфициенты полинома A:" << '\n';
	cin >> A;
	cout << "Введите коэфициенты полинома B:" << '\n';
	cin >> B;
	cout << "Введите значение х:" << '\n';
	cin >> x;
	
	cout << "Многочлен А:" << A << '\n';
	cout << "Многочлен B:" <<  B << '\n';
	cout << "Многочлен D=A+B:" << (D = A + B) << '\n';
	
	cout << "Производная от A:" << A.derivative() << '\n';

	

	cout << "Значение полинома в точке " << x << " = "<< A.Calculate(x, n) <<'\n';
	test.output_file(A);
	test.output_file(B);
	test.output_file(D);

	system("pause");
}