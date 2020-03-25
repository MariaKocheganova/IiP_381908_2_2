#include "Header.h"
#define MAX 1000

Hex::Hex()
{
	size = 5;
	hex = 0;
	char* number = new char[1000];
	for (int i = 0; i < size; i++)
		number[i] = '0';
}

Hex::Hex(const char _number[], int _size)
{
	size = _size;
	hex = (char*)_number;
	const int s = size;
	char* number = new char[s];
}
Hex::Hex(const Hex& B)
{
	size = B.size;
	hex = B.hex;
	const int s = size;
	char* number = new char[s];
}

Hex::Hex(int A)
{
	int A_copy = A;
	size = 0;
	while (A_copy != 0)
	{
		A_copy / 16;
		size++;
	}
	if (A == 0)
	{
		size = 1;
	}
	hex = new char[size];
	for (int i = 0; i < size; i++)
	{
		hex[i] = (A_copy % 16);
		A_copy / 10;
	}
}
Hex::~Hex()
{
	size = 0;
	if (hex != 0)
		delete[] hex;
}

Hex& Hex::operator=(const Hex& a)
{
	const int size_ = size;
	this->hex = new char[size_];
	for (int i = 0; i < size; i++)
	{
		hex[i] = a.hex[i];
	}
	return *this;
}


bool Hex::operator==(const Hex& a)
{
	bool res = true;
	if (size == a.size) {
		for (int i = 0; i < a.size; i++)
		{
			if (hex[i] != a.hex[i])
			{
				res = false;
				break;
			}
		}
	}
	else {
		res = false;
	}
	return res;
}

ostream& operator<<(ostream& out, const Hex& a)
{
	out << "Number = ";
	int u = 0;
	for (int i = 0; i < u; i++) {
		out << a.hex[i];
	}

	cout << endl;
	return out;
}

ostream& operator>>(istream& in, const Hex& a)
{
	cout << "Input size of Hex number: ";
	in >> a.size;
	cout << endl;
	cout << "Input Hex Number: " << endl;

	const int _s = a.size;
	a.hex = new char[_s];


	for (int i = 0; i < a.size; i++)
		in >> a.hex[i];

	return in;

}