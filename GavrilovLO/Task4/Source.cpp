#include "Header.h"
Shagomer::Shagomer() {
	i1 = 0;
}
istream& operator>>(istream& is, Shagomer &s) {
	char c;
	cout << "vvedite daty";
	is >> s.dd[s.i1] >> c >> s.mes[s.i1] >> c >> s.gg[s.i1];
	cout << "vvedite vremie";
	is >> s.hh[s.i1] >> c >> s.mm[s.i1] >> c >> s.ss[s.i1];
	cout << "vvedite kol-vo shagov";
	is >> s.shagi[s.i1];
	cout << "********************************";
	s.i1 = s.i1 + 1;
	return is;
}
void Shagomer::srednee() {
	int summa = 0;
	double srednee = 0.0;
	for (int i = 0; i < this->i1; i++)
	{
		summa = summa + this->shagi[i];
	}
	srednee = summa / this->i1;
	cout << "srednee " << srednee;

}
void Shagomer::maximym() {
	int max = 0;
	int n = 0;
	for (int i = 0; i < this->i1; i++) {
		if (this->shagi[i] > max) {
			max = this->shagi[i];
			n = i;
		}
	}
	cout << max << " " << this->dd[n] << "." << this->mes[n] << "." << this->gg[n] << "  " << this->hh[n] << this->mm[n] << this->ss[n];
}
ostream& operator<<(ostream& os, Shagomer &s) {
	ofstream fout;
	fout.open("c://gg//gg20.txt", ios::app);
	for (int i = 0; i < s.i1; i++) {
		fout << s.shagi[i] << "  " << s.dd[i] << "." << s.mes[i] << "." << s.gg[i] << "  " << s.hh[i] << ":" << s.mm[i] << ":" << s.ss[i];
		fout << "\n";

	}
	fout.close();
	return os;
}
