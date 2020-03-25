#include "Header.h"

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

	string s1;
	string s2;
	string s3;
	s1.assign(s, 0, 2);
	int i = std::stoi(s1);
	s2.assign(s, 3, 5);
	int i2 = std::stoi(s2);
	Day = i;
	s3.assign(s, 6, 10);
	int i3 = std::stoi(s3);
	Month = i2;
	Year = i3;
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
		if (res.Day > 30)
		{
			res.Day = res.Day - 30;
			res.Month++;
			if (res.Month > 12)
			{
				res.Month = res.Month - 12;
				res.Year++;
			}

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
