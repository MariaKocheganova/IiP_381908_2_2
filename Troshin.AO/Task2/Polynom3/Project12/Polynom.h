#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Polynom
{
private:
	int n; //степень полинома
	double *koef; //указатель на массив коэффициентов полинома koef[i] - коэффициент при i-й степени

public:
		Polynom();
	Polynom(int an);//конструктор с параметрами
	Polynom(const Polynom &); //копирования
	~Polynom();//деструктор

	Polynom operator+(const Polynom &);   //оператор сложения двух полиномов
	Polynom& operator=(const Polynom &);   //оператор присваивания
	
	Polynom derivative();//производная
    double Calculate(double x);//нхождение полинома в точке х

	Polynom zeropow(Polynom );
	friend ostream &operator<< (ostream &s, const Polynom &c); // перегруженный оператор вывода
	friend istream &operator >> (istream &s, Polynom &c); // перегруженный оператор ввода

};