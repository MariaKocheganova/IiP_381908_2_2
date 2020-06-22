#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale>
#include<iostream>
#include"coniow.h"
using namespace std;
class Menu {
	int x, y, lenght, height;
	int count;
	char** c;
public:
	Menu();
	Menu(int x, int y, int l, int c, const char* s);
	Menu(const char* f);
	~Menu();
	void Out(const Menu& m);
};