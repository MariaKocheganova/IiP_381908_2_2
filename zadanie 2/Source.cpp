#include "Octa.h"
ostream& operator<<(ostream& stream, const Octal& d);
istream& operator>>(istream& stream, Octal& d);


Octal::Octal() //констркуктор по умолчанию
{
	size = 0;
	oct = NULL;
}

Octal::Octal(int _size) : size(_size) //инициализатор
{
	oct = new unsigned char[size]; //длина массива
}

Octal::Octal(const char* get) { //инициализатор

	size = strlen(get);
	oct = new unsigned char[size];
	for (int i = size - 1; i >= 0; i--, get++) //само число
	{
		oct[i] = *get;
	}
}

Octal::Octal(const Octal& d) { //конструктор копирования
	size = d.size;
	oct = new unsigned char[size]; 
	for (int i = 0; i < size; ++i)
		oct[i] = d.oct[i];
}


Octal::~Octal() { //деструктор 
	if (oct != NULL)
	{
		delete[] oct;
		oct = NULL;
		size = 0;
	}
}
ostream& operator<<(ostream& stream, const Octal& d) { //вывод
	for (int i = d.size - 1; i < d.size; --i)
		stream << d.oct[i];
	stream << endl;
	return stream;
}
Octal& Octal::operator=(const Octal& d) { //перегрузка присваивания
	if (this != &d) {
		if (size != d.size)
		{
			delete[] oct;
			size = d.size;
			oct = new unsigned char[size];
		}
		for (int i = 0; i < size; ++i)
			oct[i] = d.oct[i];
	}
	return *this;
}

Octal Octal::operator+(const Octal& c) { //перегрузка сложения
	int s, s1, ms1;
	int k = 0;
	s = (size < c.size) ? c.size : size; //?-сокращённый if-else
	s1 = (size > c.size) ? c.size : size;
	ms1 = s - s1;
	int* b = new int[s];
	if (size < c.size) {
		Octal this_copy(size + ms1);
		Octal c_copy(c);
		for (int i = 0; i < s1; i++) {
			this_copy.oct[i] = oct[i];
		}
		for (int i = s1; i < s; ++i) {
			this_copy.oct[i] = '0';
		}
		for (int i = 0; i < s; i++) {
			b[i] = (this_copy.oct[i] - '0') + (c_copy.oct[i] - '0') + k;
			k = 0;
			if (b[i] > 7) {
				b[i] = fmod(b[i], 8);
				k = 1;
			}
		}if (k == 1) {
			Octal res(s + 1);
			b[s] = 1;
			for (int i = s; i >= 0; i--) {
				res.oct[i] = b[i];
				res.oct[i] = res.oct[i] + 48;
			}
			return res;
		}
		else {
			Octal res(s);
			for (int i = s - 1; i >= 0; i--) {
				res.oct[i] = b[i];
				res.oct[i] = res.oct[i] + 48;
			}
			return res;
		}
	}
	else {
		if (size > c.size) {
			Octal c_copy(c.size + ms1);
			Octal this_copy(*this);
			for (int i = 0; i < s1; i++) {
				c_copy.oct[i] = c.oct[i];
			}
			for (int i = s1; i < s; ++i) {
				c_copy.oct[i] = '0';
			}
			for (int i = 0; i < s; i++) {
				b[i] = (this_copy.oct[i] - '0') + (c_copy.oct[i] - '0') + k;
				k = 0;
				if (b[i] > 7) {
					b[i] = fmod(b[i], 8);
					k = 1;
				}
			}if (k == 1) {
				Octal res(s + 1);
				b[s] = 1;
				for (int i = s; i >= 0; i--) {
					res.oct[i] = b[i];
					res.oct[i] = res.oct[i] + 48;
				}
				return res;
			}
			else {
				Octal res(s);
				for (int i = s - 1; i >= 0; i--) {
					res.oct[i] = b[i];
					res.oct[i] = res.oct[i] + 48;
				}
				return res;
			}
		}
		else {
			Octal c_copy(c);
			Octal this_copy(*this);
			for (int i = 0; i < s; i++) {
				b[i] = (this_copy.oct[i] - '0') + (c_copy.oct[i] - '0') + k;
				k = 0;
				if (b[i] > 7) {
					b[i] = fmod(b[i], 8);
					k = 1;
				}
			}if (k == 1) {
				Octal res(s + 1);
				b[s] = 1;
				for (int i = s; i >= 0; i--) {
					res.oct[i] = b[i];
					res.oct[i] = res.oct[i] + 48;
				}
				return res;
			}
			else {
				Octal res(s);
				for (int i = s - 1; i >= 0; i--) {
					res.oct[i] = b[i];
					res.oct[i] = res.oct[i] + 48;
				}
				return res;
			}
		}
	}
}

Octal Octal::operator-(const Octal& c) { //вычитание
	int s, ms, s1, ms1;
	int k = 0;
	s = (size < c.size) ? c.size : size;
	s1 = (size > c.size) ? c.size : size;
	ms1 = s - s1;
	int* b = new int[s];
	if (size < c.size) {
		Octal this_copy(size + ms1);
		Octal c_copy(c);
		for (int i = 0; i < s1; i++) {
			this_copy.oct[i] = oct[i];
		}
		for (int i = s1; i < s; ++i) {
			this_copy.oct[i] = '0';
		}
		Octal res(s);
		for (int i = 0; i < s; i++) {
			b[i] = (c_copy.oct[i] - '0') - (this_copy.oct[i] - '0') + k;
			k = 0;
			if (b[i] < 0) {
				b[i] = b[i] + 8;
				k = -1;
			}
		}
		cout << "-";
		for (int i = s - 1; i >= 0; i--) {
			res.oct[i] = b[i];
			res.oct[i] = res.oct[i] + 48;
		}
		return res;
	}
	else {
		if (size > c.size) {
			Octal c_copy(c.size + ms1);
			Octal this_copy(*this);
			for (int i = 0; i < s1; i++) {
				c_copy.oct[i] = c.oct[i];
			}
			for (int i = s1; i < s; ++i) {
				c_copy.oct[i] = '0';
			}
			Octal res(s);
			for (int i = 0; i < s; i++) {
				b[i] = (this_copy.oct[i] - '0') - (c_copy.oct[i] - '0') + k;
				k = 0;
				if (b[i] < 0) {
					b[i] = b[i] + 8;
					k = -1;
				}
			}
			for (int i = s - 1; i >= 0; i--) {
				res.oct[i] = b[i];
				res.oct[i] = res.oct[i] + 48;
			}
			return res;
		}
		else {
			Octal c_copy(c);
			Octal this_copy(*this);
			Octal res(s);
			ms = (c_copy.oct[s - 1] - '0') - (this_copy.oct[s - 1] - '0');
			if (ms <= 0) {
				for (int i = 0; i < s; i++) {
					b[i] = (this_copy.oct[i] - '0') - (c_copy.oct[i] - '0') + k;
					k = 0;
					if (b[i] < 0) {
						b[i] = b[i] + 8;
						k = -1;
					}
				}
			}
			else {
				for (int i = 0; i < s; i++) {
					b[i] = (c_copy.oct[i] - '0') - (this_copy.oct[i] - '0') + k;
					k = 0;
					if (b[i] < 0) {
						b[i] = b[i] + 8;
						k = -1;
					}
				}
			}
			if (ms > 0) {
				cout << "-";
			}

			for (int i = s - 1; i >= 0; i--) {
				res.oct[i] = b[i];
				res.oct[i] = res.oct[i] + 48;
			}
			return res;
		}
	}
}
istream& operator>>(istream& stream, Octal& d) { //ввода
	int str;
	stream >> str;
	if (d.size != str)
	{
		if (d.oct != NULL)
			delete[] d.oct;
		d.size = str;
		d.oct = new  unsigned char[str];
	}
	for (int i = d.size - 1; i < d.size; --i)
		stream >> d.oct[i];
	return stream;
}