#pragma once

#include<iostream>
#include <cassert>
#include<math.h>

using namespace std;

class Taylor 
{
private:
	int n;
	double koef2[20];
	double* koef;
	int a;
public:
	double Taylor::koeficienti();
	friend istream& operator>>(istream& is, Taylor& s);
	void Taylor::OnTheScreen();
	void Taylor::ElementAtTheBack();
	void Taylor::znach_riad();
};