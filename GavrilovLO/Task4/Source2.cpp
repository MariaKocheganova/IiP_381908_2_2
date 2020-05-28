#include "Header.h"

istream& operator>>(istream& is, hz &s) {
	char c;
	char *str = new char[1024];
	int n = 0;
	ifstream base("c://gg//gg20.txt");
	while (!base.eof())
	{
		base.getline(str, 1024, '\n');
		n++;
	}
	base.close();
	delete str;

	ifstream fin;
	fin.open("c://gg//gg20.txt", ios::in);
	for (int i = 0; i < n; i++) {
		fin >> s.shagi2[i] >> s.dd3[i] >> c >> s.mes3[i] >> c >> s.gg3[i] >> s.hh3[i] >> c >> s.mm3[i] >> c >> s.ss3[i];
	}
	for (int i = 0; i < n; i++) {
		cout << s.shagi2[i] << " " << s.dd3[i] << "." << s.mes3[i] << "." << s.gg3[i] << " " << s.hh3[i] << ":" << s.mm3[i] << ":" << s.ss3[i];
	}
	return is;
}