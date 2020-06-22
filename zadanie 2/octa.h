#include <iostream>
#include <stdexcept>
#include <cmath>
#include<fstream>

using namespace std;
class Octal {
private:
	size_t size;
	unsigned char* oct;
public:
	Octal();
	explicit Octal(int _size);
	Octal(const char* get);
	Octal(const Octal& d);
	~Octal();
	Octal& operator=(const Octal& d);
	friend bool operator==(const  Octal& left, const  Octal& right) {
		bool res = 0;
		for (int i = 0; (i < left.size) && (i < right.size) && (res = true); i++) {
			if (left.oct[i] == right.oct[i]) {
				res = true;
			}
			else {
				res = false;
			}
			return res;
		}
	}
	Octal operator+(const Octal& c);
	Octal operator-(const Octal& c);
	friend ostream& operator<<(ostream& stream, const Octal& d);
	friend istream& operator>>(istream& stream, Octal& d);
};
