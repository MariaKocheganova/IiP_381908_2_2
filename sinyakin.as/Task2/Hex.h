#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

	using namespace std;

	class Hex 
	{
	private:
		unsigned char* h;
		int size;
	public:
		Hex();
		Hex(unsigned char a);
		Hex(unsigned char* a, int s);
		Hex(string a);
		Hex(const Hex& a);
		~Hex();

		Hex operator+(const Hex& t);
		Hex operator-(const Hex& t);
		Hex& operator=(const Hex& t);
		bool operator==(const Hex& t);
		bool operator!=(const Hex& t);
		bool operator>(const Hex& t);
		bool operator<(const Hex& t);
		bool operator>=(const Hex& t);
		bool operator<=(const Hex& t);

		friend int toDec(Hex a);
		friend Hex toHex(int a);

		friend ostream& operator << (ostream& stream, const Hex& a);
		friend istream& operator >> (istream& stream, Hex& a);
	
	};
