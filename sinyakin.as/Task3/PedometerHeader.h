#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once


#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

class Date {
	friend class Pedometer;
private:
	int* h_s;
	int* h_e;
	int* data;
	int st;
public:
	Date();
	~Date();
	Date(int* _h_s, int* _h_e, int* _data, int _st);
	Date(const Date& c);
	void getdate();
	void inpsetdate();

	Date operator=(Date& c);
};

class Pedometer {
private:
	int count = 0;
	Date* num;
public:
	Pedometer();
	~Pedometer();
	Pedometer(int* h_s, int* h_e, int* data, int st);
	Pedometer(const Pedometer& c);
	Pedometer operator=(Pedometer& c);
	void setdate(Date new_data);
	void info();
	int srmonth();
	int maxmonth();
	void show_maxmonth();
	void infile();
	void outfile();
	void onedate();
	void show_srmonth();
	int inpmonth();
	int inpinfoday();
	int inpinfomonth();
	int inpinfoyear();
	int inpinfoh_s0();
	int inpinfoh_s1();
	int inpinfoh_e0();
	int inpinfoh_e1();
	void menu();
};
#endif  // INCLUDE_ADD_H_