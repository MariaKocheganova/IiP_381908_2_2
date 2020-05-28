#pragma once
#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Vector {
private:
	double x, y, z;                               // координаты

public:
	double choice;
	void newchoice(const  int a);
	Vector();                                     // по умолчанию
	Vector(double _x, double _y, double _z);      // инициализация вектора
	Vector(double a);                             // преобразование типа
	Vector(const Vector& v);                      // копирование
	~Vector();                                    // деструктор

	friend std::ostream& operator<<(std::ostream& stream, const Vector& v);
	friend std::istream& operator>>(std::istream& stream, Vector& v);

	bool CompVector(const Vector& v);

	Vector &operator=(const Vector& v);//присваивание

	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v);
	Vector operator%(const Vector& v);//скалярное произведение
	Vector operator*(const double &v);//умножение на скаляр
	bool operator==(const Vector& v);//сравнение длин
};