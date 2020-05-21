#pragma once
#ifndef INCLUDE_FloorScales_H_
#define INCLUDE_FloorScales_H_
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;


struct SForFile
{
	string Name;
	int Day;
	int Mes;
	int Year;
	int Ves;
};
struct stry
{
	int Day;
	int Mes;
	int Year;
};




class Nabludenie {
public:
	friend class FloorScales;
	friend class Pers;
	void Print2();
	Nabludenie() {}
	~Nabludenie() {}
	Nabludenie(int _day, int _mes, int _year, int _ves);
	int Getday() { return persDataDay; }
	int Getmes() { return persDataMes; }
	int Getyear() { return persDataYear; }
	int GetVes() { return persVes; }

	void SetNabl(int day, int mes, int year, int ves) {
		persDataDay = day;
		persDataMes = mes;
		persDataYear = year;
		persVes = ves;
	}
private:
	int persDataDay;
	int persDataMes;
	int persDataYear;
	int persVes;

};
class FloorScales {
public:
	void minv1();
	FloorScales(vector<Nabludenie> dat, string name);
	void vi(ofstream fin);
	friend class Pers;
	int maxmes1(int keyMes, int keyYear);
	void max_with_output(int keyMes, int keyYear);
	void maxmes();
	int maxv();
	void maxv1();
	void sredv1();
	int minmes(int keyMes, int keyYear);
	void minmes_with_output(int keyMes, int keyYear);
	void minmes();
	int minv();
	int sredmes(int keyMes, int keyYear);
	void sred_with_output(int keyMes, int keyYear);
	void sredmes();
	int sredv();
	void input();
	void Mes();
	void vvodkeyDate();
	void Poisk();
	void addnablpers();
	void PrintNabl();
	void PrintName();
	void SetName(string name) { persName = name; }
	void Print();
	FloorScales(const Nabludenie &d, string name);
	FloorScales() {}
	~FloorScales() {}
	void SetNABL(vector <Nabludenie> nabl1) {
		nabl = nabl1;
	}

private:
	stry stry;
	vector <Nabludenie> nabl;
	string persName;
};
class Pers {
public:
	Pers(vector<Nabludenie> dat, string name);
	friend class FloorScales;
	void LoadFromFileTest(string filename);
	void SaveToFileTest(string filename);
	void SaveToFile();
	bool DataFromFile(string filename);
	bool DataToFile(string filename);
	void LoadFromFile();
	void file();
	void MaxVes();
	void MinVes();
	void SredVes();
	void dateVes();
	void PrintPers();
	void vivodpers();
	void AddNabl();

	void PrintAll();
	void AddFloorScales();
	void vibor();
	void SetNABL2(vector <FloorScales> nabl1) {
		pers = nabl1;
	}
	void SetNABL3(vector <FloorScales> nabl1) {
		pers = nabl1;
	}
	Pers() {}
	~Pers() {}
	Pers(const FloorScales &d);
private:
	vector <FloorScales> pers;
};
void PrintMenu();
void AddFloorScales();
void PrintAll();
void vibor();
#endif  // INCLUDE_FloorScales_H_