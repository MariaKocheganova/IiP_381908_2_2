#include "Time.h"
using namespace std;
using std::string;
using std::basic_string;



Time::Time() {
	SYSTEMTIME tn;
	GetSystemTime(&tn);
	hou = tn.wHour;
	min = tn.wMinute;
	sec = tn.wSecond;

}
Time::Time(int i, int j, int k) {
	for (;;) {
		if ((i < 23 && i>0) && (j < 59 && j>0) && (k < 59 && i>0)) {
			hou = i;
			min = j;
			sec = k;
		}
		else {
			cout << "Введите значения соответсвующие международному формату времени";
			break;
		}
	}
}
Time::Time(const Time& a) {
	
	hou = a.hou;
	min = a.min;
	sec = a.sec;
}
Time::Time(const string& a) {

	string temp = a.substr(0, 2);
	hou = atoi(temp.c_str());
	temp = a.substr(2, 2);
	min = atoi(temp.c_str());
	temp = a.substr(5, 2);
	sec = atoi(temp.c_str());


}
Time::~Time() {
	cout << "Class Destroyed" << endl;
}

Time& Time::operator=(const Time& a) {
	hou = a.hou;
	min = a.min;
	sec = a.sec;
	return *this;
}
Time Time::operator+(const Time& temp) {
	Time res;
	
	if (hou + temp.hou > 23) {
		if (temp.hou == 24) res.hou+=0;
		else hou = hou + temp.hou - 24;
	}
	else hou += temp.hou;
	if (min + temp.min > 59) {
		min = min + temp.min - 60;
		hou += (min + temp.min) / 60;
	}
	else min += temp.min;
	
	if (sec + temp.sec > 59) {
		sec = sec + temp.sec - 60;
		min += (sec + temp.sec) / 60;
	}
	else sec += temp.sec;
	if (res.sec == 60) {
		res.sec = 0;
		res.min++;
	}
	if (res.min == 60) {
		res.min = 0;
		res.hou++;
	}
	if (res.hou == 24) res.hou = 0;
	return res;
	
}
Time Time::operator-(const Time& temp) {
	Time res;
	if (sec - temp.sec < 0) {
		min -= 1;
		sec = 60 + (sec - temp.sec);
	}
	else sec -= temp.sec;
	
	if (min - temp.min < 0) {
		hou -= 1;
		min = 60 + (min - temp.min);
	}
	else min -= temp.min;
	
	if (hou - temp.hou < 0) {
		if (temp.hou == 24) res.hou += 0;
		else hou = hou - temp.hou + 24;
	}
	else hou -= temp.hou;
	if (res.sec == 60) {
		res.sec = 0;
		res.min++;
	}
	if (res.min == 60) {
		res.min = 0;
		res.hou++;
	}
	if (res.hou == 24) res.hou = 0;
	return res;

}
bool Time::operator==(const Time& temp) {
	

	if ((hou == temp.hou) && (min== temp.min) && (sec == temp.sec)) return true;
	else return false;
}
bool Time::operator!=(const Time& temp) {
	if ((hou!= temp.hou) ||(min != temp.min) || (sec != temp.sec)) return true;
	else return false;
}
bool Time::operator>(const Time& temp) {
	if ((hou > temp.hou))return true;
	if ((hou == temp.hou) && (min > temp.min)) return true;
	if ((hou == temp.hou) && (min == temp.min) && (sec > temp.sec)) return true;
	else return false;
}
bool Time::operator<(const Time& temp) {
	if ((hou < temp.hou))return true;
	if ((hou == temp.hou) && (min < temp.min)) return true;
	if ((hou == temp.hou) && (min == temp.min) && (sec < temp.sec)) return true;
	else return false;
}
bool Time::operator>=(const Time& temp) {
	if ((hou>= temp.hou))return true;
	if ((hou == temp.hou) && (min >= temp.min)) return true;
	if ((hou == temp.hou) && (min == temp.min) && (sec >= temp.sec)) return true;
	else return false;
}
bool Time::operator<=(const Time& temp) {

	if ((hou <= temp.hou))return true;
	if ((hou == temp.hou) && (min <= temp.min)) return true;
	if ((hou == temp.hou) && (min == temp.min) && (sec <= temp.sec)) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Time& a){
	int h, m, s;
	h = a.hou;
	m = a.min;
	s = a.sec;
	os << h << ':' << m << ':' << s;
	return os;
}
istream& operator>>(istream& is, Time& a) {
	string time,temp;
	is >> time;
	temp = time.substr(0, 2);
	a.hou = atoi(temp.c_str());
	temp = time.substr(2, 2);
	a.min = atoi(temp.c_str());
	temp = time.substr(5, 2);
	a.sec = atoi(temp.c_str());
	return is;
}