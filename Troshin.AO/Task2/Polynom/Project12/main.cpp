#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"

int main()
{
	setlocale(LC_ALL, "");
	int n,c, m;
	double x;
	cout << "Откуда считывать коэффициенты? 1- из файла, 2- с клавиатуры" << endl;
	cin >> c;
	cout << "Введите степень полинома A и степень полинома B:" << '\n';
	cin >> n >> m;
	Polynom A(n);
	Polynom B(m);
	Polynom D;
	Polynom C;
	ifstream ifs;
	ofstream ofs;
	switch(c) {
		case 1:
			ifs.open("Polynom.txt");

			if (!ifs.is_open())
			{
				cout << "ошибка файла ";
			}
			else
			{

				ifs >> x;
				ifs >> A;
				ifs >> B;

			}
			break;
		case 2:
			cout << "Введите коэфициенты полинома A:" << '\n';
			cin >> A;
			cout << "Введите коэфициенты полинома B:" << '\n';
			cin >> B;
			cout << "Введите значение х:" << '\n';
			cin >> x;

	}
	
	
	cout << "Многочлен А:" << A << '\n';
	cout << "Многочлен B:" <<  B << '\n';
	D = A + B;
	cout << "Многочлен D=A+B:" << D.zeropow() << '\n';
	
	cout << "Производная от A:" << A.derivative() << '\n';

	

	cout << "Значение полинома в точке " << x << " = "<< A.Calculate(x) <<'\n';
	ofs.open("Polynom.txt");
	ofs << "Многочлен А:" << A<<"\n";
	ofs << "Многочлен B:" << B<<"\n";
	ofs << "Многочлен D=A+B:" << D << "\n";
	ofs << "Производная от A : " << A.derivative() << "\n";
	ofs << "Значение полинома в точке " << x << " = " << A.Calculate(x) << "\n";
	ofs.close();
	
	system("pause");
}