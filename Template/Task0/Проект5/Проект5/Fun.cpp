#include <iostream>
#include "Fun.h"
using namespace std;
// Описание класса Cstring====================================================
void Cstring::outPut(const char* name)
{
	cout << name << ": " << str << endl;
}
Cstring::Cstring(void) // По умолчанию
{
	len = 0; size = 0; str = 0;
}
Cstring::Cstring(int S, char fill) // Инициализатор
{
	len = S; size = S + 1;
	str = new char[size];
	for (int i = 0; i < len; i++) str[i] = fill;
	str[len] = 0;
}
Cstring::Cstring(const char* string) // Преобразования типа
{
	len = 0;
	while (string[len])
	{
		len++;
	}
	size = len + 1;
	str = new char[size];
	for (int i = 0; i < size; i++)
		str[i] = string[i];
}
Cstring::Cstring(const Cstring& string) // Копирования
{
	size = string.size;
	len = string.len;
	str = new char[size];
	for (int i = 0; i < size; i++)
		str[i] = string.str[i];
}
Cstring::~Cstring() // Деструктор
{
	delete[] str;
	len = 0; size = 0; str = NULL;
}
Cstring& Cstring::operator= (const Cstring& string)
{
	if (string.len + 1 > size)
	{
		size = string.len + 1;
		len = size - 1;
		delete[]str;
		str = new char[size];
	}
	int i = 0;
	while (string.str[i])
	{
		str[i] = string.str[i];
		i++;
	}
	len = i;
	str[i] = 0;
	return *this;
}
Cstring Cstring::operator+ (const Cstring& string)
{
	Cstring res;
	res.len = len + string.len;
	res.size = res.len + 1;
	res.str = new char[res.size];
	int i = 0;
	while (str[i])
	{
		res.str[i] = str[i];
		i++;
	}
	int j = 0;
	while (string.str[j])
	{
		res.str[i + j] = string.str[j];
		j++;
	}
	res.str[i + j] = 0;
	return res;
}
Cstring& Cstring::operator+=(const Cstring& string)
{
	if (len + string.len + 1 > size)
	{
		size = len + string.len + 1;
		char* tmp = new char[size];
		int i = 0;
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
		delete[]str;
		str = tmp;
	}
	int i = 0;
	while (string.str[i])
	{
		str[len + i] = string.str[i];
		i++;
	}
	len = len + i;
	str[len] = 0;
	return *this;
}
ostream& operator<<(ostream& stream, const Cstring& string)

{

	stream << string.str << endl;

	return stream;

}
istream& operator >> (istream& stream, Cstring& string)
{
	char ss[255];
	stream.getline(ss, 255);
	string = ss;
	return stream;
}
int Cstring::GetSize()const
{
	return size;
}
int Cstring::GetLen()const
{
	return len;
}
// Описание класса Ccomplex==========================================================
Ccomplex::Ccomplex()// Конструктор по умолчанию
{
	re = 0.0; im = 0.0;
}
Ccomplex::Ccomplex(const Ccomplex &c) // Конструктор копирования
{
	re = c.re; im = c.im;
}
Ccomplex::Ccomplex(double _re, double _im) : re(_re), im(_im) { }// Конструктор инициализации
Ccomplex::Ccomplex(double _re) // Конструктор преобразования типа
{
	re = _re; im = 0.0;
}
Ccomplex::~Ccomplex() // Деструктор
{
	re = 0.0; im = 0.0;
}
void Ccomplex::output() 
{
	if (im == 0)
	{
		cout << re ;
	}
	else
	{
		cout << re << "+" << im << "i";
	}
}
Ccomplex& Ccomplex::operator=(const Ccomplex& c) 
{
	(*this).re = c.re; im = c.im;
	return *this;
}
Ccomplex Ccomplex::operator*(const Ccomplex& c)
{
	Ccomplex res;
	res.re = re * c.re + im * c.im;
	res.im = re * c.im + im * c.re;
	return res;
}

Ccomplex operator*(double d, const Ccomplex& c) 
{
	Ccomplex res;
	res.re = d * c.re;
	res.im = d * c.im;
	return res;
}
ostream& operator<<(ostream& stream, const Ccomplex& c)
{
	stream << c.re << "+" << c.im <<"i";
	return stream;
}
istream& operator >> (istream& stream, Ccomplex& c) 
{
	stream >> c.re >> c.im;
	return stream;
}
Ccomplex Ccomplex::Add(Ccomplex c)
{
	Ccomplex res;
	res.re = re + c.re;
	res.im = im + c.im;
	return res;
}
Ccomplex Ccomplex::Mlt(Ccomplex c)
{
	Ccomplex res;
	res.re = re * c.re + im * c.im;
	res.im = re * c.im + im * c.re;
	return res;
}
void Ccomplex::InPut()
{
	cout << "Введите действительные часть:";
	cin >> re;
	cout << "Введите мнимую часть:";
	cin >> im;
}
Ccomplex Ccomplex::operator+(const Ccomplex& c)
{
	Ccomplex res;
	res.re = re + c.re;
	res.im = im + c.im;
	return res;
}