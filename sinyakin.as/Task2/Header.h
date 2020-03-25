#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Hex
{

	int size;
	char* hex;
public:
	Hex();
	Hex(const char _number[], int _size);
	Hex(const Hex& B);
	Hex(int A);
	Hex(const char* a);
	~Hex();
	Hex operator+(const Hex& a);
	Hex operator-(const Hex& a);
	bool operator==(const Hex& a);
	bool operator!=(const Hex& a);
	Hex& operator=(const Hex& a);
	friend ostream& operator<<(ostream& out, const Hex& a);
	friend ostream& operator>>(istream& in, const Hex& a);
};