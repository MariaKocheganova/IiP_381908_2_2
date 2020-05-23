#include"Money.h"
#include <cmath>

istream& operator>>(istream& in, Money& s) {
	in >> s.rub >> s.kop;
	return in;
}
ostream& operator <<(ostream& out, const Money& s) {
	out << "Ваш баланс  " << s.rub << " рублей и " << s.kop << " копеек" << endl;
	return out;
}

Money Money :: operator +(const Money& rub0) {
	Money temp; int l;
	l = kop + rub0.kop;;
	temp.kop = (kop + rub0.kop) % 100;
	temp.rub = (rub + rub0.rub) + ((l - temp.kop) / 100);
	return temp;
}


Money  Money ::operator -(const Money& rub0) {
	int rubk;
	Money temp;
	temp.kop = (rub * 100 + kop) - rub0.rub * 100 - rub0.kop;
	rubk = temp.kop;
	temp.kop = temp.kop % 100;
	temp.rub = (rubk - temp.kop) / 100;
	return temp;
}

Money Money :: operator *(const Money& rub0) {
	int rubk;
	Money temp;
	temp.kop = (rub * 100 + kop) * rub0.rub;
	rubk = temp.kop;
	temp.kop = temp.kop % 100;
	temp.rub = (rubk - temp.kop) / 100;
	return temp;

}

Money Money :: operator /(const Money& rub0) {
	Money temp;
	int rubk;
	temp.kop = (rub * 100 + kop) / rub0.rub;
	rubk = temp.kop;
	temp.kop = temp.kop % 100;
	temp.rub = (rubk - temp.kop) / 100;
	return temp;
}

Money Money :: operator ==(const Money& rub0) {
	Money temp;
	if (rub > rub0.rub) 
		cout << "Текущий баланс больше введёной суммы" << endl;
	else if (rub == rub0.rub) {
		if (kop > rub0.kop)
			cout << "Текущий баланс больше введёной суммы" << endl;
		else if (kop == rub0.kop)
			cout << "Баланс и введённая сумма равны";
		else
			cout << "Введённая сумма больше баланса" << endl;
	}
	else
		cout << "Введённая сумма больше баланса" << endl;

	return temp;
}


