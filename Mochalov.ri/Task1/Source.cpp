#include "Header.h"
using namespace std;

CTime::CTime() {
	hou = 0;
	min = 0;
	sec = 0;
}
CTime::CTime(int h, int m, int s) {
	if (h > 0 && m > 0 && s > 0) {
		sec = (h * 3600 + m * 60 + s) % 86400;
		hou = sec / 3600;
		min = sec % 3600 / 60;
		sec %= 60;
	}
	else { hou = 0; min = 0; sec = 0; cout << "time can't be lower than zero!!!"; }
}
CTime::CTime(const CTime& t) {
	hou = t.hou;
	min = t.min;
	sec = t.sec;
}
CTime::CTime(const char s[9]) {
	hou = (s[0] - '0') * 10 + s[1] - '0';
	min = (s[3] - '0') * 10 + s[4] - '0';
	sec = (s[6] - '0') * 10 + s[7] - '0';
}
CTime::~CTime() {
	hou = 0;
	min = 0;
	sec = 0;
}
char* CTime::TtoStr() {
	char* s = new char[9];
	s[8] = 0;
	s[0] = hou / 10 + '0';
	s[1] = hou % 10 + '0';
	s[2] = ':';
	s[3] = min / 10 + '0';
	s[4] = min % 10 + '0';
	s[5] = ':';
	s[6] = sec / 10 + '0';
	s[7] = sec % 10 + '0';
	return s;
}
CTime& CTime::operator=(const CTime& t) {
	sec = (t.hou * 3600 + t.min * 60 + t.sec) % 86400;
	hou = sec / 3600;
	min = sec % 3600 / 60;
	sec %= 60;
	return *this;
}
CTime operator+(const CTime& t, const CTime& t1) {
	CTime res;
	res.sec = ((t.hou * 3600 + t.min * 60 + t.sec) + (t1.hou * 3600 + t1.min * 60 + t1.sec)) % 86400;
	res.hou = res.sec / 3600;
	res.min = res.sec % 3600 / 60;
	res.sec %= 60;
	return res;
}
CTime operator+(const CTime& t, const int s) {
	CTime res;
	res.sec = ((t.hou * 3600 + t.min * 60 + t.sec) + s) % 86400;
	res.hou = res.sec / 3600;
	res.min = res.sec % 3600 / 60;
	res.sec %= 60;
	return res;
}
CTime operator-(const CTime& t, const CTime& t1) {
	CTime res;
	if ((t.hou * 3600 + t.min * 60 + t.sec) < (t1.hou * 3600 + t1.min * 60 + t1.sec))
		res.sec = 86400 - ((t1.hou * 3600 + t1.min * 60 + t1.sec) - (t.hou * 3600 + t.min * 60 + t.sec));
	else res.sec = (t.hou * 3600 + t.min * 60 + t.sec) - (t1.hou * 3600 + t1.min * 60 + t1.sec);
	res.hou = res.sec / 3600;
	res.min = res.sec % 3600 / 60;
	res.sec %= 60;
	return res;
}
bool operator==(const CTime& t, const CTime& t1) {
	return (t.hou * 3600 + t.min * 60 + t.sec == t1.hou * 3600 + t1.min * 60 + t1.sec);
}
istream& operator>>(istream& is, CTime& t) {
	char s;
	int a, b, c;
	is >> a >> s >> b >> s >> c;
	if (a > 0 && b > 0 && c > 0) {
		t.sec = (a * 3600 + b * 60 + c) % 86400;
		t.hou = t.sec / 3600;
		t.min = t.sec % 3600 / 60;
		t.sec %= 60;
	}
	else { t.hou = 0; t.min = 0; t.sec = 0; cout << "time can't be lower than zero!!!"; }
	return is;
}
ostream& operator<<(ostream& os, const CTime& t) {
	os << t.hou << ':' << t.min << ':' << t.sec;
	return os;
}