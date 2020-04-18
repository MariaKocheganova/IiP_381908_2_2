#include"LongLong.h"
string Reverse(string a) {
	int pos = 0;
	while (a[pos] != 0) { pos++; }
	string ans(pos, '0');
	for (int i = 0; i < pos; i++) {
		ans[i] = a[pos - 1 - i];
	}
	ans[pos] = 0;
	return(ans);
}
string ItoS(int a) {
	int copy = a, a_len = 0;
	if (a == 0) { return("0"); }
	while (copy != 0) { copy = copy / 10; a_len++; }
	string ans(a_len, '0');
	int pos = 0;
	while (a != 0) {
		ans[pos] = (a % 10) + '0';
		a = a / 10;
		pos++;
	}
	return(ans);
}
unsigned int StoI(string a) {
	unsigned int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans = ans + (a[i] - '0') * pow(10, i);
	}
	return(ans);
}

string Summ_str(string a, string b) {
	int a_len = 0, b_len = 0, ans_len = 0;
	while (a[a_len] != 0) { a_len++; }
	while (b[b_len] != 0) { b_len++; }
	if (a_len < b_len) { ans_len = b_len + 1; }
	else { ans_len = a_len + 1; }
	string ans(ans_len, '0');
	if (a_len < b_len) {
		int ost = 0;
		for (int i = 0; i < a_len; i++) {
			int ch = a[i] + b[i] - '0' - '0' + ost;
			ost = ch / 10;
			ch = ch % 10;
			ans[i] = ch + '0';
		}
		for (int i = a_len; i < b_len; i++) {
			int ch = b[i] - '0' + ost;
			ost = ch / 10;
			ch = ch % 10;
			ans[i] = ch + '0';
		}
		ans[b_len] = ost + '0';
	}
	else {
		int ost = 0;
		for (int i = 0; i < b_len; i++) {
			int ch = a[i] + b[i] - '0' - '0' + ost;
			ost = ch / 10;
			ch = ch % 10;
			ans[i] = ch + '0';
		}
		for (int i = b_len; i < a_len; i++) {
			int ch = a[i] - '0' + ost;
			ost = ch / 10;
			ch = ch % 10;
			ans[i] = ch + '0';
		}
		ans[a_len] = ost + '0';
	}
	int pos = ans_len - 1;
	while (ans[pos] == '0' && pos > 0) { pos--; }
	ans = ans.substr(0, pos + 1);
	return(ans);
}
string Mins_str(string a, string b) {
	int a_len = 0, b_len = 0, ans_len = 0;
	while (a[a_len] != 0) { a_len++; }
	while (b[b_len] != 0) { b_len++; }
	if (a_len < b_len) { ans_len = b_len; }
	else { ans_len = a_len; }
	string ans(ans_len, '0');
	if (a_len < b_len) { //b - a
		for (int i = 0; i < a_len; i++) {
			while (b[i] < a[i]) {
				b[i + 1] = b[i + 1] - 1;
				b[i] = b[i] + 10;
			}
			ans[i] = b[i] - a[i] + '0';
		}
		cout << "ans" << ans << endl;
		for (int i = a_len; i < b_len; i++) {
			while (b[i] < '0') {
				b[i + 1] = b[i + 1] - 1;
				b[i] = b[i] + 10;
			}
			ans[i] = b[i];
		}
		cout << "ans" << ans << endl;
	}
	else if (b_len < a_len) {//a - b
		for (int i = 0; i < b_len; i++) {
			while (a[i] < b[i]) {
				a[i + 1] = a[i + 1] - 1;
				a[i] = a[i] + 10;
			}
			ans[i] = a[i] - b[i] + '0';
		}
		for (int i = b_len; i < a_len; i++) {
			while (a[i] < '0') {
				a[i + 1] = a[i + 1] - 1;
				a[i] = a[i] + 10;
			}
			ans[i] = a[i];
		}
	}
	else {
		if (Compare(a, b) == 1) { // a < b
			for (int i = 0; i < a_len; i++) {
				while (b[i] < a[i]) {
					b[i + 1] = b[i + 1] - 1;
					b[i] = b[i] + 10;
				}
				ans[i] = b[i] - a[i] + '0';
			}
		}
		else if (Compare(a, b) == 2) { // b < a
			for (int i = 0; i < a_len; i++) {
				while (a[i] < b[i]) {
					a[i + 1] = a[i + 1] - 1;
					a[i] = a[i] + 10;
				}
				ans[i] = a[i] - b[i] + '0';
			}
		}
	}
	int pos = ans_len - 1;
	while (ans[pos] == '0' && pos > 0) { pos--; }
	ans = ans.substr(0, pos + 1);
	return(ans);
}
string Multpl_str(string a, string b) {
	int a_len = 0, b_len = 0;
	while (a[a_len] != 0) { a_len++; }
	while (b[b_len] != 0) { b_len++; }
	string answer(a_len + 1 + b_len, 0);
	for (int i = 0; i < b_len; i++) {
		string a_copy(a_len + 1 + i, '0');
		int ost = 0;
		for (int j = 0; j < a_len; j++) {
			int ch = (a[j] - '0') * (b[i] - '0') + ost;
			ost = ch / 10;
			ch = ch % 10;
			a_copy[j + i] = ch + '0';
		}
		a_copy[a_len + i] = ost + '0';
		answer = Summ_str(answer, a_copy);
	}
	return(answer);
}
string Divs_str(string a, string b) { // a/b
	int a_len = 0, b_len = 0, summ_len = 0, step = 0;
	while (a[a_len] != 0) { a_len++; }
	while (b[b_len] != 0) { b_len++; }
	if (a_len < b_len) { summ_len = b_len + 1; }
	else { summ_len = a_len + 1; }
	string summ(summ_len, '0');
	while (Compare(summ, a) == 1) {
		step++;
		summ = Summ_str(summ, b);
	}
	if (Compare(summ, a) == 2) { step--; }
	string ans = ItoS(step);
	return(ans);
}

int Compare(string a, string b) { 
	int a_len = 0, b_len = 0;
	while (a[a_len] != 0) { a_len++; }
	while (b[b_len] != 0) { b_len++; }
	int pos = a_len - 1;
	while (a[pos] == '0' && pos > 0) { pos--; }
	a = a.substr(0, pos + 1);
	a_len = pos + 1;
	pos = b_len - 1;
	while (b[pos] == '0' && pos > 0) { pos--; }
	b = b.substr(0, pos + 1);
	b_len = pos + 1;
	if (a_len < b_len) {
		return(1);
	}
	else if (b_len < a_len) {
		return(2);
	}
	else {
		int pos = a_len;
		if (a == b) { return(3); }
		while (a[pos] == b[pos] && pos > 0) { pos--; }
		if (a[pos] < b[pos]) { return(1); }
		else if (b[pos] < a[pos]) { return(2); }
	}
}
//Возвращаемые значения:| 1 - a < b | 2 - a > b | 3 - a = b |

LongLong Str_To_LongLong(string a) {
	a = Reverse(a);
	string old_copy = Divs_str(a, Reverse("4294967295"));
	string young_copy = Mins_str(a, Multpl_str(a, old_copy));
	LongLong answer(StoI(old_copy), StoI(young_copy));
	return(answer);
}
string LongLong_To_Str(LongLong& a) {
	unsigned int old_copy = a.GetOld(), young_copy = a.GetYoung();
	string answer = Summ_str(Multpl_str(ItoS(old_copy), Reverse("4294967295")), ItoS(young_copy));
	return(answer);
}

/*---------------Методы---------------*/
void LongLong::SetOld(unsigned int old_copy) {
	old = old_copy;
}
void LongLong::SetYoung(unsigned int young_copy) {
	young = young_copy;
}
unsigned int LongLong::GetOld() {
	return(old);
}
unsigned int LongLong::GetYoung() {
	return(young);
}

LongLong::LongLong(const LongLong& copy) {\
	old = copy.old;
	young = copy.young;
}
LongLong::LongLong(string a) {
	a = Reverse(a);
	string old_copy = Divs_str(a, Reverse("4294967295"));
	string young_copy = Mins_str(a, Multpl_str(a, old_copy));
	old = StoI(old_copy);
	young = StoI(young_copy);
}

/*---------------Переопределение операторов---------------*/
LongLong LongLong::operator+(LongLong& copy) {
	string this_str = LongLong_To_Str(*this);
	string copy_str = LongLong_To_Str(copy);
	string answer = Summ_str(this_str, copy_str);
	return(Str_To_LongLong(answer));
}
LongLong LongLong::operator-(LongLong& copy) {
	string this_str = LongLong_To_Str(*this);
	string copy_str = LongLong_To_Str(copy);
	string answer = Mins_str(this_str, copy_str);
	return(Str_To_LongLong(answer));
}
LongLong LongLong::operator*(LongLong& copy) {
	string this_str = LongLong_To_Str(*this);
	string copy_str = LongLong_To_Str(copy);
	string answer = Multpl_str(this_str, copy_str);
	return(Str_To_LongLong(answer));
}
LongLong LongLong::operator/(LongLong& copy) {
	string this_str = LongLong_To_Str(*this);
	string copy_str = LongLong_To_Str(copy);
	string answer = Divs_str(this_str, copy_str);
	return(Str_To_LongLong(answer));
}
LongLong& LongLong::operator=(const LongLong& copy) {
	old = copy.old;
	young = copy.young;
	return(*this);
}
istream& operator>>(istream& is, LongLong& copy) {
	string ans;
	is >> ans;
	ans = Reverse(ans);
	bool check = false;
	for (int i = 0; i < ans.size(); i++) { if (ans[i] < '0' || ans[i] > '9') check = true; }
	if (check) { cout << "Error, please try again..." << endl; copy.old = 0; copy.young = 0; }
	else {
		string old_str = Divs_str(ans, Reverse("4294967295"));
		string young_str = Mins_str(ans, Multpl_str(old_str, Reverse("4294967295")));
		copy.old = StoI(old_str);
		copy.young = StoI(young_str);
	}
	return(is);
}
ostream& operator<<(ostream& os, LongLong& copy) {
	string old = Multpl_str(ItoS(copy.old), Reverse("4294967295"));
	os << Reverse(Summ_str(old, ItoS(copy.young)));
	return(os);
}