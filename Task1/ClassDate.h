#pragma once
#include <iostream>
using namespace std;

class Date
{
	private:
		int d, m, y;

	public:
		Date(int days=1, int month=1, int year=1);
		Date(string TRSdate);
		Date operator= (const Date& dt);
		friend std::istream& operator>>(istream& stream, Date& dt);
		friend std::ostream& operator<<(ostream& stream, const Date& dt);
		const Date operator+(int dp);
		const Date operator-(int dm);
		bool operator==(const Date& dt);
		bool operator>(const Date& dt);
		bool operator<(const Date& dt);
		bool operator!=(const Date& dt);	
};
