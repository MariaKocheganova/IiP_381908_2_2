
#include "Classy.h"

using namespace std;

void Cstring::outPut(const char* name)
{
	cout << name << ": " << str << endl;
}

Cstring::Cstring()
{
	size = 0;
	len = 0;
	str = 0;
}

Cstring::Cstring(int s, char sym) {
	len = s;
	size = s + 1;
	str = new char[size];
	for (int i = 0; i < len; i++)
	{
		str[i] = sym;

	}
	str[size] = 0;
}

Cstring::Cstring(const Cstring& string) {
	len = string.len;
	size = string.size;
	str = new char[string.size];
	for (int i = 0; i < string.len; i++)
	{
		str[i] = string.str[i];
	}
	str[string.len] = 0;

}

Cstring::Cstring(const char* string) {
	len = 0;
	while (string[len]) len++;
	size = len + 1;
	str = new char[size];
	for (int i = 0; i < size; i++) str[i] = string[i];
}
Cstring::~Cstring()
{
	delete[] str;
	size = 0; len = 0; str = NULL;
}


Ccomplex Ccomplex::Add(Ccomplex a)
{
	Ccomplex res;
	res.re = re + a.re;
	res.im = im + a.im;
	return res;
}
Ccomplex Ccomplex::Mlt(Ccomplex a)
{
	Ccomplex res;
	res.re = re * a.re - im * a.im;
	res.im = re * a.im + im * a.re;
	return res;
}
void Ccomplex::InPut()
{
	cout << "¬ведите действительные часть:";
	cin >> re;
	cout << "¬ведите мнимую часть:";
	cin >> im;
}
void Ccomplex::Output(Ccomplex a)
{
	if (a.im < 0)
	{
		cout << a.re << a.im << "i";
	}
	else
	{
		cout << a.re << "+" << a.im << "i";
	}
}
Cstring& Cstring::operator=(const Cstring& cms)
{
	if (cms.len + 1 > size)
	{
		size = cms.len + 1;
		len = size - 1;
		delete[]str;
		str = new char[size];
	}
	int i = 0;
	while (cms.str[i])
	{
		str[i] = cms.str[i];
		i++;
	}
	len = i;
	str[i] = 0;
	return *this;
}

Cstring Cstring::operator+(const Cstring& cms) 
{
	Cstring res;
	res.len = len + cms.len;
	res.size = res.len + 1;
	res.str = new char[res.size];
	int i = 0;
	while (str[i]) {
		res.str[i] = str[i];
		i++;
	}
	int j = 0;
	while (cms.str[j]) {
		res.str[i + j] = cms.str[j];
		j++;
	}
	return res;
}
Cstring& Cstring::operator+=(const Cstring& cms) {
	if (len + cms.len + 1 > size) {
		size = len + cms.len + 1;
		char* tmp = new char[size];
		int i = 0;
		while (str[i]) {
			tmp[i] = str[i];
			i++;
		}
		delete[]str;
		str = tmp;
	}
	int i = 0;
	while (cms.str[i]) 
	{
		str[len + i] = cms.str[i];
		i++;
	}
	len = len + i;
	str[len] = 0;
	return *this;
}
istream& operator>>(istream& stream, Cstring& _str) {
	char string[1000];
	int i = 0;
	stream.getline(string, 1000);
	_str = string;
	return stream;
}
ostream& operator<<(ostream& stream, const Cstring& _str) {
	stream << _str.str << endl;
	return stream;
}

