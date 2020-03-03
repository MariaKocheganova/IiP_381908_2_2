#pragma once
#include <iostream>
using namespace std;
//Класс Cstring-------------------------------------------------
class Cstring
{
public:
	void outPut(const char* name);
	int GetSize()const;
	int GetLen()const;
	Cstring(void); // По умолчанию
	Cstring(int S, char fill = '*'); // Инициализатор
	Cstring(const char* string); // Преобразования типа
	Cstring(const Cstring& string); // Копирования
	~Cstring(); // Деструктор
	// Перегрузка опенраций
	Cstring& operator= (const Cstring& string);
	Cstring operator+ (const Cstring& string);
	Cstring& operator+=(const Cstring& string);
	friend ostream& operator<<(ostream& stream, const Cstring& string);
	friend istream& operator >> (istream& stream, Cstring& string);
private:
	char* str; // строка
	int size; // размер буфера
	int len; // длина реальная
};
ostream& operator<<(ostream& stream, const Cstring& string);
istream& operator >> (istream& stream, Cstring& string);
//Класс Ccomplex-------------------------------------------------
class Ccomplex 
{
public:
	Ccomplex(); // Конструктор по умолчанию
	Ccomplex(const Ccomplex &c); // Конструктор копирования
	Ccomplex(double _re, double _im);// Конструктор инициализации
	Ccomplex(double _re); // Конструктор преобразования типа
	~Ccomplex(); // Деструктор
	void output();
	Ccomplex Add(Ccomplex a);
	Ccomplex Mlt(Ccomplex a);
	void InPut();
	void SetRe(double _re)
	{
		re = _re;
	}
	double GetRe()
	{
		return re;
	}
	void SetIm(double _im)
	{
		re = _im;
	}
	double GetIm()
	{
		return im;
	}
	Ccomplex& operator=(const Ccomplex& c);
	Ccomplex  operator+(const Ccomplex& c);
	Ccomplex operator*(const Ccomplex& c);
	friend Ccomplex operator*(double d, const Ccomplex& c);
	friend ostream& operator<<(ostream& stream, const Ccomplex& c);
	friend istream& operator >> (istream& stream, Ccomplex& c);
private:
	double re; // действительная часть
	double im; // мнимая часть
};
Ccomplex operator*(double d, const Ccomplex& c);
ostream& operator<<(ostream& stream, const Ccomplex& c);
istream& operator >> (istream& stream, Ccomplex& c);