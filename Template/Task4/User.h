#pragma once
#include <vector>
#include <string>

using namespace std;

class User {
private:
	vector <Unit> list;
	string name;
	int len;
public:
	User() { name = ""; len = 0; }
	User(string _name) { this->name = _name; len = 0; }
	~User() {}
	void add(double _data, int _day, int _month, int _year);
	void setData(double _data, int i);
	void setTime(int _day, int _month, int _year, int i);
	int getDay(int i);
	int getMonth(int i);
	int getYear(int i);
	double getData(int i);
	void Usort();
	void setName(string _name);
	string getName();
};

struct Unit
{
public:
	Unit() {
		data = 0;
		day = 0;
		month = 0;
		year = 0;
	}
	Unit(double data, int day, int month, int year) : data(data), day(day), month(month), year(year) {}
	Unit(double _data, int _day, int _month, int _year) {
		this->data = _data;
		this->day = _day;
		this->month = _month;
		this->year = _year;
	}
	Unit(Unit& temp) {
		this->data = temp.data;
		this->day = temp.day;
		this->month = temp.month;
		this->year = temp.year;
	}
	void Ucopy(Unit& temp) {
		this->data = temp.data;
		this->day = temp.day;
		this->month = temp.month;
		this->year = temp.year;
	}
	int day;
	int month;
	int year;
	double data;
};