
#include <iostream>
#include <string>
#include "Hex.h"

using namespace std;


Hex::Hex() 
{
	h = new unsigned char[2];
	h[0] = '0';
	h[1] = '\0';
	size = 1;
}


Hex::Hex(unsigned char a)
{
	size = 1;
	h = new unsigned char[size + 1];
	h[0] = a;
	h[1] = '\0';
}
Hex::Hex(unsigned char* a, int s)
{
	size = s;
	h = new unsigned char[s + 1];
	for (int i = 0; i < size; i++)
	{
		h[i] = a[i];
	}
	h[size] = '\0';
}
Hex::Hex(string a)
{
	size = ::size(a);
	h = new unsigned char[size + 1];
	for (int i = 0; i < size + 1; i++) 
	{
		h[i] = a[i];
	}
}

Hex::Hex(const Hex& a) 
{
	size = a.size;
	h = new unsigned char[size + 1];
	for (int i = 0; i < size; i++) 
	{
		h[i] = a.h[i];
	}
	h[size] = '\0';
}

Hex::~Hex()
{
	delete[] h;
	size = 0;
}

ostream& operator << (ostream& stream, const Hex& a) 
{
	for (int i = 0; i < a.size; i++) {
		stream << a.h[i];
	}
	return stream;
}
istream& operator >> (istream& stream, Hex& a) 
{
	string S;
	stream >> S;
	int s = size(S);
	a.size = s;
	a.h = new unsigned char[s + 1];
	for (int i = 0; i < s + 1; i++) {
		a.h[i] = S[i];
	}
	return stream;
}

int AtoB(unsigned char a) 
{
	if ((a > '0') && (a <= '9')) return (a - '0');
	else {
		switch (a) {
		case('A'): return 10;
		case('B'): return 11;
		case('C'): return 12;
		case('D'): return 13;
		case('E'): return 14;
		case('F'): return 15;
		}
	}
	return (0);
}
unsigned char BtoA(int a)
{
	if ((a >= 0) && (a <= 9)) return (a + '0');
	else 
	{
		switch (a) 
		{
		case(10): return ('A');
		case(11): return ('B');
		case(12): return ('C');
		case(13): return ('D');
		case(14): return ('E');
		case(15): return ('F');
		}
	}
}

Hex toHex(int a)
{
	int i = 0;
	while ((a % 16) <= 15)
	{
		a = a / 16;
		i++;
	}
	unsigned char* temp = new unsigned char[i];
	i = 0;
	while ((a % 16) <= 15) 
	{
		a = a / 16;
		temp[i] = a % 16;
		i++;
	}

	int size = i;
	unsigned char* res = new unsigned char[size];
	for (i; i > 0; i--) 
	{
		for (int j = 0; j < size; j++)
		{
			res[j] = temp[i];
		}
	}
	res[size + 1] = '\0';
	return Hex(res, size);
	delete[]temp;
}
int toDec(Hex a)
{
	int res = 0;
	for (int i = 0; i < a.size; i++) 
	{
		for (int j = 1; j < a.size; j++) 
		{
			res += AtoB(a.h[i]) * pow(16, a.size - j);
		}
		return res;
	}
}

Hex Hex::operator+(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	Hex res = toHex(a + b);
	return res;
}

Hex Hex::operator-(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	Hex res = toHex(a - b);
	return res;
}

Hex& Hex::operator=(const Hex& t)
{
	size = t.size;
	h = new unsigned char[size + 1];
	for (int i = 0; i < size; i++)
	{
		h[i] = t.h[i];
	}
	h[size] = '\0';
	return *this;
}

bool Hex::operator==(const Hex& t)
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a == b) return 1;
	else return 0;
}

bool Hex::operator!=(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a != b) return 1;
	else return 0;
}

bool Hex::operator>(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a > b) return 1;
	else return 0;
}

bool Hex::operator>=(const Hex& t)
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a >= b) return 1;
	else return 0;
}

bool Hex::operator<(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a < b) return 1;
	else return 0;
}

bool Hex::operator<=(const Hex& t) 
{
	Hex temp = *this;
	Hex tempo = t;
	int a = toDec(temp);
	int b = toDec(tempo);
	if (a <= b) return 1;
	else return 0;
}
