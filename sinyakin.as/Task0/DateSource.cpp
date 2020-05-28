#include "DateHeader.h"

using namespace std;

Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

Date::Date(int i, int j, int k) : Day(i), Month(j), Year(k) { }

Date::Date(const Date& s)
{
	Day = s.Day;
	Month = s.Month;
	Year = s.Year;
}

Date::Date(string s)
{
	Date();
	int X = 0;
	for (int i = 0; i < 10; i++)
	{
		if (((s[i] < '0') || (s[i] > '9')) && ((i == 0) || (i == 1) || (i == 3) || (i == 4) || (i == 6) || (i == 7) || (i == 8) || (i == 9)))
		{
			abort();
		}
	}
	if (X == 0)
	{
		string STR = "";

		STR += s[0];
		STR += s[1];

		Day = atoi(STR.c_str());

		STR = "";
		STR += s[3];
		STR += s[4];

		Month = atoi(STR.c_str());

		STR = "";
		STR += s[6];
		STR += s[7];
		STR += s[8];
		STR += s[9];

		Year = atoi(STR.c_str());
	}
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

Date Date::operator+(int j)
{
	Date res;
	res.Day = this->Day;
	res.Month = this->Month;
	res.Year = this->Year;
	res.Day = res.Day + j;
	while (res.Day > 30)
	{
		res.Day = res.Day - 30;
		res.Month++;
		if (res.Month > 12)
		{
			res.Month = res.Month - 12;
			res.Year++;
		}


	}
	return res;
}

Date Date::operator-(int j)
{
	Date res;
	res.Day = this->Day;
	res.Month = this->Month;
	res.Year = this->Year;
	res.Day = res.Day - j;
	while (res.Day <= 0)
	{
		if (res.Day <= 0)
		{
			res.Day = 30 + res.Day;
			res.Month--;
			if (res.Month <= 0)
			{
				res.Month = 12 - res.Month;
				res.Year--;
			}

		}
	}
	return res;
}

bool Date::operator==(const Date& c)
{

	if (Day == c.Day && Month == c.Month && Year == c.Year)
		return true;
	else return false;

}

bool Date::operator>(const Date& c)
{
	if (Year > c.Year)
	{
		true;
	}
	else
	{
		if ((Year == c.Year) && (Month > c.Month))
		{
			true;
		}
		else
		{
			if ((Year == c.Year) && (Month == c.Month) && (Day > c.Day))
			{
				true;
			}
			else
			{
				false;
			}
		}
	}
}

bool Date::operator<(const Date& c)
{
	if (Year < c.Year)
	{
		true;
	}
	else
	{
		if ((Year == c.Year) && (Month < c.Month))
		{
			true;
		}
		else
		{
			if ((Year == c.Year) && (Month == c.Month) && (Day < c.Day))
			{
				true;
			}
			else
			{
				false;
			}
		}
	}
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
