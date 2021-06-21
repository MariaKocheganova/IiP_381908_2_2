#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class LongLong
{
private:
	int cel;
	unsigned int ost;
public:
	LongLong();//Конструктор по умолчанию
	LongLong(const LongLong &c);//Конструктор копирования
	LongLong(int _cel,unsigned int _ost);//Конструктор инициализации
	LongLong(int _ost);//Конструктор преобразования типа
	~LongLong();//Деструктор
	LongLong& operator+=(const LongLong& c);
	LongLong& operator=(const LongLong& c);
	LongLong  operator-(const LongLong& c);
	LongLong  operator*(const LongLong& c);
	LongLong  operator+(const LongLong& c);
	bool operator == (const LongLong& c);
	friend ostream& operator << (ostream& stream, const LongLong& c);
	friend istream& operator >> (istream& stream, LongLong& c);
};
ostream& operator << (ostream& stream,const LongLong& c);
istream& operator >> (istream& stream,LongLong& c);
