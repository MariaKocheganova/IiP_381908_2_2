#include <iostream>
using namespace std;
class Money {
private:
	int rub;
	int kop;
public:
	Money() {
		rub = 0;
		kop = 0;
	}
	Money(int x, int y) {
		rub = x;
		kop = y;
	}
	Money(int f) {
		rub = f;
	}


	Money operator+(const Money& rub0);
	Money operator-(const Money& rub0);
	Money operator*(const Money& rub0);
	Money operator/(const Money& rub0);
	friend istream& operator>>(istream& is, Money& s);
	friend ostream& operator<<(ostream& os, const Money& s);
	bool  operator==(const Money& rub0) {
		return(rub == rub0.rub && kop == rub0.kop);
	}



};