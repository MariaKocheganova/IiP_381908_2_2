#include"Header.h"
#include <cmath>

istream& operator>>(istream& in, Money& s) {
	in >> s.rub >> s.kop;
	return in;
}
ostream& operator <<(ostream& out, const Money& s) {
	out << "Баланс " << s.rub << " рублей и " << s.kop << " копеек" << endl;
	return out;
}

Money operator +(const Money& rub, const Money& n) {
	Money temp;
	temp.rub = rub.rub + n.n;
	temp.kop = rub.kop+n.n1;
	return temp;
}
Money operator -(const Money& rub, const Money& n) {
	Money temp;
	temp.rub =( rub.rub - n.n);
	temp.kop =( rub.kop-n.n1);
	return temp;
}
Money operator *(const Money& rub, const Money& op_f) {
	Money temp;
	temp.kop = (rub.rub * 100 + rub.kop)*op_f.f;
	temp.rubk = temp.kop;
	temp.kop = temp.kop % 100;
	temp.rub = (temp.rubk - temp.kop)/100;
	return temp;
}
Money operator /(const Money& rub, const Money& op_f) {
	Money temp;
	temp.kop = (rub.rub * 100 + rub.kop) / op_f.f;
	temp.rubk = temp.kop;
	temp.kop = temp.kop % 100;
	temp.rub = (temp.rubk - temp.kop) / 100;
	return temp;
}
Money operator ==(const Money& rub,const Money& m) {
	Money ch1, ch2;
	ch1.rubk = rub.rub * 100 + rub.kop;
	ch2.rubk1 = m.clor * 100 + m.clork;
	cout << ch2.rubk1;
	if (ch1.rubk > ch2.rubk1) 
		cout << "Первоначальный баланс меньше текущено на " << rub.rub - m.clor << " рублей" << endl;
	else if (rub.kop > m.clork)
		cout << "Первоначальный баланс меньше текущего на " << rub.kop - m.clork << " копеек" << endl;
	else if (ch1.rubk < ch2.rubk1)
		cout << "Первоначальный баланс больше текущего на" << m.clor - rub.rub << " рублей" << endl;
	else if (rub.kop < m.clork)
		cout << "Первоначальный баланс больше текущего на" << m.clork - rub.kop << " копеек" << endl;
	else cout << "Первоначальный баланс равен текущему" << endl;
	return ch1,ch2;
}

