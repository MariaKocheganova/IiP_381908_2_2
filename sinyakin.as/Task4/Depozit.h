#pragma once
#include "ProcCenter.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;
struct CreditCardStruct
{
	int Password;
	string NumCard;
};

class Depozit
{
public:
	friend class ProcCenterVec;
	friend class ProcCenter;

	Depozit() {}
	~Depozit() {}
	void PasswordCheck(ProcCenterVec& c);
	void Autorization(ProcCenterVec& c);
	void Start(ProcCenterVec& c);
	/*void Check(ProcCenterVec& c);*/
	void ShowAbleDepozits(ProcCenterVec& c);
	void Menu(ProcCenterVec& c);
	void BalancePerson(ProcCenterVec& c);

private:
	CreditCardStruct Cardpass;
	int Num;
};
