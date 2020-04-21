#include"Octal.h"
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Debug/Octal_In.txt");
	fout.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Debug/Octal_Out.txt");
	if (fout.is_open()) { cout << "all is ok" << endl; }
	Octal a("111"), b("12");
	Octal c = a - b;
	fout << c << endl;
	c = a - b;
	fout << c << endl;
	fout << 78 << endl;
	char s[255];
	fin.getline(s, 255);
	cout << s << endl;
	fout << a;
	fin.close();
	fout.close();
	return(0);
}