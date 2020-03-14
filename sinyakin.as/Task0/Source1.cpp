#include "Header.h"

using namespace std;

Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

Date::Date(int i, int j, int k)
{
	Day = i;
	Month = j;
	Year = k;
}


Date::Date(const Date& s)
{
	Day = s.Day;
	Month = s.Month;
	Year = s.Year;
}

Date::~Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

Date& Date::operator=(const Date& c)
{
	this->Day = c.Day;
	this->Month = c.Month;
	this->Year = c.Year;
	return *this;
}

Date& Date::operator+(int j)
{

	int n;
	cout << "Enter a number of days you wanna add to your recent date - ";
	cin >> n;
	int EndMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m;
	int l = 0;
	int p;
	int a;
	for (m = 0; m < Month; m++)
		l = l + EndMonth[m];
	l = l + j + n;
	cout << "The new brand new date is -  " << endl;
	if (l <= 365)  //Если не конец года
	{
		for (m = 0; m < 13; m++)
		{
			p = l - EndMonth[m];
			if (p <= EndMonth[m + 1])
			{
				a = m + 1;
				break;
			}
			else l = p;
		}
		cout << p << "." << a << ":" << Year;
	}
	else
	{
		l = l - 365;  //Если конец года - меняем год на следующий
		for (m = 0; m < 13; m++)
		{
			p = l - EndMonth[m];
			if (p <= EndMonth[m + 1])
			{
				a = m + 1;
				break;
			}
			else l = p;
		}
		cout << p << "." << a << ":" << Year + 1;

	}

	return *this;

}

Date& Date::operator-(int j)
{

	int n;
	cout << "Enter a number of days you wanna cut of your recent date - ";
	cin >> n;
	int EndMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m;
	int l = 0;
	int p;
	int a;
	for (m = 0; m < Month; m++)
		l = l + EndMonth[m];
	l = l + j - n;
	cout << "The new brand new date is -  " << endl;
	if (l <= 365)  //Если не конец года
	{
		for (m = 0; m < 13; m++)
		{
			p = l - EndMonth[m];
			if (p <= EndMonth[m + 1])
			{
				a = m + 1;
				break;
			}
			else l = p;
		}
		cout << p << "." << a << ":" << Year;
	}
	else
	{
		l = l - 365;  //Если конец года - меняем год на следующий
		for (m = 0; m < 13; m++)
		{
			p = l - EndMonth[m];
			if (p <= EndMonth[m + 1])
			{
				a = m + 1;
				break;
			}
			else l = p;
		}
		cout << p << "." << a << ":" << Year - 1;

	}

	return *this;

}



bool Date::operator==(const Date& c)
{

	if (Day == c.Day && Month == c.Month && Year == c.Year)
		return true;
	else return false;

}


bool Date::operator!=(const Date& c)
{

	if (Day == c.Day && Month == c.Month && Year == c.Year)
		return false;
	else return true;

}

ostream& operator<<(ostream& os, const Date& s)
{
	os << s.Month << "." << s.Day << ":" << s.Year;
	return os;
}

istream& operator>>(istream& is, Date& s)
{
	is >> s.Day;
	is >> s.Month;
	is >> s.Year;
	return is;
}
