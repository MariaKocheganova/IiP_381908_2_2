#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Polynom
{
public:
	int n,m; //степень полинома
	double *koef; //указатель на массив коэффициентов полинома koef[i] - коэффициент при i-й степени
	Polynom();
	Polynom(int an);//конструктор с параметрами
	Polynom(const Polynom &); //копирования
	~Polynom();//деструктор

	Polynom operator+(const Polynom &);   //оператор сложения двух полиномов
	Polynom operator=(const Polynom &);   //оператор присваивания
	Polynom derivative();//производная
	
	 Polynom Calculate(double x, int n);//нхождение полинома в точке х
	void output_file(const Polynom &c);

	friend ostream &operator<< (ostream &s, const Polynom &c); // перегруженный оператор вывода
	friend istream &operator >> (istream &s, Polynom &c); // перегруженный оператор ввода

};