#include "ClassDate.h"
#include <cstdlib>
#include<cstdio>
#include <clocale>
#include <iostream>

using namespace std;


Date::Date(int days, int month, int year)
{
	if (year < 0)
		throw exception("Неверный год");
	if((month>=13)||(month<=0))
		throw exception("Неверный месяц");
	if(days<=0)
		throw exception("Неверный день");
	if (((days>=32)||(days<=0))&&(month == 1) && (month == 3) && (month == 5) && (month == 7) && (month == 8) && (month == 10) && (month == 12))
		throw exception("Неверный день");
	if (((days>=31)||(days<=0))&&(month==4) && (month == 6) && (month == 9) && (month == 11))
		throw exception("Неверный день");
	if (((days>=30)||(days<=0))&&(month ==2)&&(year%4==0))
		throw exception("Неверный день");
	if (((days >= 29) || (days <= 0)) && (month == 2) && (year % 4 != 0))
		throw exception("Неверный день");
	d = days;
	m = month;
	y = year;
}


Date::Date(string TRSdate)
{
	Date();
	int cdv = 0;
	for (int i = 0; i < 10; i++)
	{
		if (((TRSdate[i] < '0') || (TRSdate[i] > '9'))&&((i==0)|| (i == 1) || (i == 3) || (i == 4) || (i == 6) || (i == 7) || (i == 8) || (i == 9)))
		{
			abort(); //другие способы прерывания конструктора мне пока не известны (это убийство)
		}
	}
	if (cdv == 0)
	{
		string FD = ""; //fd строка
		FD += TRSdate[0];
		FD += TRSdate[1];
		d = atoi(FD.c_str()); //atoi конвертация строки в числовой вид (я решил сделать через функцию, чтобы не искать из кучи
		FD = "";
		FD += TRSdate[3];
		FD += TRSdate[4];  //поочереди все символы
		m = atoi(FD.c_str());
		FD = "";
		FD += TRSdate[6];
		FD += TRSdate[7];
		FD += TRSdate[8];
		FD += TRSdate[9];
		y = atoi(FD.c_str());
	}
}


Date Date::operator= (const Date& dt) //оператор присваивания
{
	
	d = dt.d;
	m = dt.m;
	y = dt.y;
	return *this;
}

istream& operator>> (istream& stream, Date& dt) //ввод
{
	stream >> dt.d >> dt.m >> dt.y;
	return stream;
}

ostream& operator<< (ostream& stream, const Date& dt) //вывод
{
	stream << dt.d <<"."<< dt.m <<"."<< dt.y <<endl;
	return stream;
}

const Date Date::operator+(int dp) //сложение
{
	while (dp > 0)
	{
		if ((d == 0) || (m == 0))
		{
			throw exception("Ошибка ввода");
			break;
		}
		d = d + 1;
		dp = dp - 1;
		if ((d == 32) && ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)))
		{
			d = 1;
			m = m + 1;
		}
		if ((d == 31) && ((m == 4) || (m == 6) || (m == 9) || (m == 11)))
		{
			d = 1;
			m = m + 1;
		}
		if ((d == 30) && (m == 2) && (y % 4 == 0))
		{
			d = 1;
			m = m + 1;
		}
		if ((d == 29) && (m == 2) && (y % 4 != 0))
		{
			d = 1;
			m = m + 1;
		}
		if (m == 13)
		{
			m = 1;
			y = y + 1;
		}
	}
	return *this;
}

const Date Date::operator-(int dm) //вычитание
{
	while (dm > 0)
	{
		if ((d == 0) || (m == 0))
		{
			throw exception("Ошибка ввода");
			break;
		}
		d = d - 1;
		dm = dm - 1;
		if ((d == 0) && ((m == 5) || (m == 7) || (m == 10) || (m == 12)))
		{
			d = 30;
			m = m - 1;
		}
		if ((d == 0) && ((m == 4) || (m == 6) || (m == 8) || (m == 9) || (m == 11) || (m == 1) || (m == 2)))
		{
			d = 31;
			m = m - 1;
		}
		if ((d == 0) && (m == 3) && (y % 4 == 0))
		{
			d = 29;
			m = m - 1;
		}
		if ((d == 0) && (m == 3) && (y % 4 != 0))
		{
			d = 28;
			m = m - 1;
		}
		if (m == 0)
		{
			m = 12;
			y = y - 1;
		}
		if (y < 0)
			throw exception("Ошибка 2 : нет работы с годами до нашей эры");
	}
	return *this;
}

bool Date::operator==(const Date& dt) //сравнение
{
	if ((d == dt.m) && (m == dt.m) && (y == dt.y))
		return true;
	else
		return false;
}

bool Date::operator>(const Date& dt)//>
{
	if (y > dt.y)
	{
		return true;
	}
	else
	{
		if ((y == dt.y) && (m > dt.m))
		{
			return true;
		}
		else
		{
			if ((y == dt.y) && (m == dt.m) && (d > dt.d))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator<(const Date& dt) //<
{
	if (y < dt.y)
	{
		return true;
	}
	else
	{
		if ((y == dt.y) && (m < dt.m))
		{
			return true;
		}
		else
		{
			if ((y == dt.y) && (m == dt.m) && (d < dt.d))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
bool Date::operator!=(const Date& dt)
{
	if ((d != dt.d) || (m != dt.m) || (y != dt.y))
		return true;
	else
		return false;
}