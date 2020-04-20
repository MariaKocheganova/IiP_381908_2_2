#include <iostream>
using namespace std;
class Money {
private:
	int rub;
	int kop;
public:
	int kop1,rubk,clor,clork,rubk1;
	 int n, n1;
	float f;
	Money() {
		rub = 0;
		kop = 0;
	}
	
	friend Money operator+(const Money& rub, const Money& n);
	friend Money operator-(const Money& rub, const Money& n);
	friend Money operator*(const Money& rub, const Money &f);
	friend Money operator/(const Money& rub, const Money& op_f);
	friend istream& operator>>(istream& is, Money& s);
	friend ostream& operator<<(ostream& os,const Money& s);
	friend Money operator ==(const Money& rub, const Money& m);
	
	 void setOp( int op_n,float op_f, int op_n1) {
		n = op_n;
		f = op_f;
		n1 = op_n1;
		clor = rub;
		clork = kop;
	}
	 //поскольку нет динамического выделения памяти, то не нужно добавлять деструктор
	 
};