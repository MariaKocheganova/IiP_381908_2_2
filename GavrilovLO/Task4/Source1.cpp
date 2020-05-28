#include "Header.h"
void Shag::info(Shagomer&s1) {

	for (int i = 0; i < s1.i1; i++) {
		if (this->dd1 <= s1.dd[i] && this->dd2 >= s1.dd[i] && this->mes1 <= s1.mes[i] && this->mes2 >= s1.mes[i] && this->gg1 <= s1.gg[i] && this->gg2 >= s1.gg[i]) {
			if (this->hh1 <= s1.hh[i] && this->hh2 >= s1.hh[i] && this->mm1 <= s1.mm[i] && this->mm2 >= s1.mm[i] && this->ss1 <= s1.ss[i] && this->ss2 >= s1.ss[i]) {
				cout << "\n" << s1.shagi[i];
			}
		}
	}
}
istream& operator>>(istream& is, Shag &s) {
	char c;
	cout << "vvedite nach daty";
	is >> s.dd1 >> c >> s.mes1 >> c >> s.gg1;
	cout << "vvedite konechnyu daty";
	is >> s.dd2 >> c >> s.mes2 >> c >> s.gg2;
	cout << "vvedite  nach vremie";
	is >> s.hh1 >> c >> s.mm1 >> c >> s.ss1;
	cout << "vvedite  conechnoe vremie";
	is >> s.hh2 >> c >> s.mm2 >> c >> s.ss2;

	cout << "********************************";
	return is;
}