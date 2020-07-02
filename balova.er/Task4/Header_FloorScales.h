#ifndef INCLUDE_FloorScales_H_
#define INCLUDE_FloorScales_H_

#pragma once
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;

class FloorScales {
public:
  FloorScales() {}
  ~FloorScales() {}
  string GetName() { return persName; }
  int GetDay() { return persDataDay; }
  int GetMes() { return persDataMes; }
  int GetYear() { return persDataYear; }
  int GetWeight() { return persweight; }
  void SetNABL(vector <FloorScales> nabl1) {
    nabl = nabl1;
  }
  void SetName(string name) { persName = name; }
  void SetNabl(int day, int mes, int year, int weight) {
    persDataDay = day;
    persDataMes = mes;
    persDataYear = year;
    persweight = weight;
    kolvonabl = 1;
  }
  void Print();
  void PrintName();
  void PrintNabl2(int n);
  void PrintNabl();
  void addnablpers();
  void Mes();
  void Poisk();
  
  
  
  void sredmes();
  void sredw();
  void minmes();
  
  void minw();
  void maxmes();
  void maxw();
private:
  vector <FloorScales> nabl;
  string persName;
  int persDataDay;
  int persDataMes;
  int persDataYear;
  int kolvonabl;
  int persweight;
  static int cmpfield;
};
void AddFloorScales();
void PrintAll();
void vibor();
void infile();
void outfile();
void menu();
void PrintPers();



#endif  
