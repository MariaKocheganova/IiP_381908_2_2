#include "User.h"

void User::setData(double _data, int i) {
	list[i].data = _data;
}

void User::setTime(int _day, int _month, int _year, int i) {
	list[i].day = _day;
	list[i].month = _month;
	list[i].year = _year;
}

int User::getDay(int i) {
	return list[i].day;
}

int User::getMonth(int i) {
	return list[i].month;
}

int User::getYear(int i) {
	return list[i].year;
}

double User::getData(int i) {
	return list[i].data;
}

void User::Usort() {
	for (int j = 0; j < len; j++)
		for (int i = len; i < len - 1; i++) {
			if (list[i].year < list[i + 1].year) {
				Unit temp(list[i]);
				list[i].Ucopy(list[i + 1]);
				list[i + 1].Ucopy(temp);
			}
			else
				if (list[i].month < list[i + 1].month) {
					Unit temp(list[i]);
					list[i].Ucopy(list[i + 1]);
					list[i + 1].Ucopy(temp);
				}
				else
					if (list[i].day < list[i + 1].day) {
						Unit temp(list[i]);
						list[i].Ucopy(list[i + 1]);
						list[i + 1].Ucopy(temp);
					}
		}
}

void User::add(double _data, int _day, int _month, int _year) { // Add to end
	list.push_back;
	list[len].data = _data;
	list[len].day = _day;
	list[len].month = _month;
	list[len].year = _year;
	len++;
	Usort();
}

void User::setName(string _name) {
	name = _name;
}

string User::getName() {
	return name;
}