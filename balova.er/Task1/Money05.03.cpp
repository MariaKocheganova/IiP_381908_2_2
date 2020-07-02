#include"Money05.03.h"



Money::Money() {
	rub = 0;
	cop = 0;
}

Money::Money(int _rub, int _cop) {
	rub = _rub;
	cop = _cop;
	while (cop > 99)
	{
		rub++;
		cop = cop - 100;
	}
	
}

Money::Money(int c) {
	rub = c;
	cop = 0;
}

Money::Money(const Money& c) {
	rub = c.rub;
	cop = c.cop;
}

Money::~Money() {
	rub = 0;
	cop = 0;
}

//operator

bool Money :: operator<(const Money& c) {
	if (rub < c.rub) {
		return 1;
		if (cop < c.cop) {
			return 1;
		}
	}
	return 0;
}


bool Money :: operator>(const Money& c) {
	if (rub > c.rub) {
		return 1;
		if (cop > c.cop) {
			return 1;
		}
	}
	return 0;
}


bool Money :: operator==(const Money& c) {
	bool res = 0;
	if (rub == c.rub) {
		if (cop == c.cop) { res = 1; }
	}
	return res;
}


Money& Money::operator=(const Money& c) {
	rub = c.rub;
	cop = c.cop;
	return *this;
}


Money operator +(const Money& c, const Money& c1) {
	Money res;
	res.rub = c.rub + c1.rub;
	res.cop = c.cop + c1.cop;
	while (res.cop > 99)
	{
		res.rub++;
		res.cop = res.cop - 100;
	}
	return res;
}

Money Money::operator-(const Money& c) {
	Money res;
	res.rub = rub - c.rub;
	res.cop = cop - c.cop;
	if (res.cop < 0)
	{
		res.rub--;
		res.cop = 100 - abs(cop - c.cop);
	
	}

	return res;
}




Money Money::operator*(double c)
{
	Money res;
	res.cop = cop;
	if (rub > 0) {
		while (rub > 0)
		{
			rub = rub - 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop * c;
		while (res.cop > 99)
		{
			res.rub++;
			res.cop = res.cop - 100;
		}
	}
	else {
		while (rub < 0)
		{
			rub = rub + 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop * c;
		while (res.cop > 99)
		{
			res.rub--;
			res.cop = res.cop - 100;
		}
	}
	return res;
}



Money Money::operator/(double c) {
	Money res;
	res.cop = cop;
	if (rub > 0) {
		while (rub > 0)
		{
			rub = rub - 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop / c;
		while (res.cop > 99)
		{
			res.rub++;
			res.cop = res.cop - 100;
		}
	}
	else {
		while (rub < 0)
		{
			rub = rub + 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop / c;
		while (res.cop > 99)
		{
			res.rub--;
			res.cop = res.cop - 100;
		}
	}
	return res;
}


void Money::output() {
	cout << rub << "." << cop;
}


void Money::input() {
	char c;
	cin >> rub >> c >> cop;

}

istream& operator>>(istream& is, Money& c) {
	char a;
	is >> c.rub >> a >> c.cop;
	return is;
}

ostream& operator<<(ostream& os, const Money& c) {

	os << c.rub << "." << c.cop;
	return os;
}


//MAINNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Запиишите две денежные суммы в ввиде:  рр.кк " << endl;
	
	Money a;
	Money g;
	cin >> a;
	cin >> g;
	int l;
	cout << "1)Сумма" << endl;
	cout << "2)Разность" << endl;
	cout << "3)Умножение на 10" << endl;
	cout << "4)Деление на 10" << endl;
	cout << "5)Сравнение" << endl;
	cin >> l;
	switch (l) {
	case 1:
		a = a + g;
		cout << a << endl;
		break;
	case 2:
		a = a - g;
		if (a < 0) {
			cout << "Ошибка. Ответ отрицательный" << endl;
		}else{ cout << a << endl; }
		
		break;
	case 3:
		a = a * 10;
		g = g * 10;
		cout << a << endl;
		cout << g << endl;
		break;

	case 4:
		a = a / 10;
		g = g / 10;
		cout << a << endl;
		cout << g << endl;
		break;
	case 5:
		a= a == g;
		cout << a << endl;
		break;
}
	system("pause");
	return 0;
	}

