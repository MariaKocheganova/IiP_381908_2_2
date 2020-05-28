#include"Header.h"
istream& operator>>(istream& is, Teilor &s) {
	is >> s.n;
	is >> s.a;
	return is;
}
double Teilor::koeficienti() {

	int g = 1;
	cout << "*********************\n";
	//if (koef !=0) {delete [] koef;}
	koef = new  double[this->n]; // правильное написание
	for (int i = 0; i <= this->n; i++) {
		if (i == 0)
		{
			koef[i] = sin(this->a);
			this->koef2[i] = koef[i];
		}
		else {
			if (i % 2 == 0) {
				if (i == 2 || i == 6)
				{
					g = g*i;
					koef[i] = -(sin(this->a) / g);
					this->koef2[i] = koef[i];

				}
				else {

					g = g*i;
					koef[i] = sin(this->a) / g;
					this->koef2[i] = koef[i];

				}
			}
			else {
				g = g*i;
				if (i == 3 || i == 7) {
					koef[i] = -(cos(this->a) / g);
					this->koef2[i] = koef[i];

				}
				else {
					g = g*i;
					koef[i] = cos(this->a) / g;
					this->koef2[i] = koef[i];

				}
			}
		}
	}
	for (int i = 0; i <= this->n; i++) {
		cout << koef[i] << " ";
	}
	for (int i = 0; i <= this->n; i++) {
		return koef[i];
	}
	cout << "***************************** \n";
}
void Teilor::vivod_na_ikran() {
	cout << "***************************** \n";

	for (int i = 0; i <= this->n; i++)
	{
		if (i == 1 || i == 5 || i == 0 || i == n || i == 2 || i == 6) {
			if (i == 0) {
				cout << this->koef2[i] << "(X-" << this->a << ")" << "+";
			}
			if (i == 1 || i == 5 || i == 2 || i == 6) { cout << this->koef2[i] << "(X-" << this->a << ")^" << i; }
			if (i == n) { cout << this->koef2[i] << "(X-" << this->a << ")^" << i; }
		}
		else { cout << this->koef2[i] << "(X-" << this->a << ")^" << i << "+"; }
	}

}
void Teilor::zad_chlen_riad() {
	int i;
	cout << "\n";
	cin >> i;
	cout << this->koef2[i];
}
void Teilor::znach_riad() {
	int x;
	double s;
	s = 0.0;
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		s = s + koef2[i] * pow((x - this->a), i);
	}
	cout << s;
}
