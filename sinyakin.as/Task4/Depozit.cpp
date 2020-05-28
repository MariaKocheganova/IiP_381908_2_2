#include "Depozit.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;

void PrintMenu()
{
	cout << "What do you want?" << endl;
	cout << "1 - Autorize myself" << endl;
	cout << "2 - Show the information of an able depozits" << endl;
	cout << "3 - Check free depozits" << endl;
	cout << "4 - Open Depozit " << endl;
	cout << "5 - Show a condition of depozit " << endl;
	cout << "6 - Witdrawn Procents " << endl;
	cout << "7 - Close Depozit " << endl;
}

void Depozit::Autorization(ProcCenterVec& c)
{
	Start(c);
}
void Depozit::Start(ProcCenterVec& c)
{
	cout << " Enter Card Number ";
	cin >> Cardpass.NumCard;
	PasswordCheck(c);
}

void Depozit::PasswordCheck(ProcCenterVec& c)
{
	bool t = false;
	for (int i = 0; i < c.Vect.size(); i++)
	{
		if ((c.Vect[i].CardNumber == Cardpass.NumCard))
		{
			Num = i;
			t = true;
		}
	}
	if (t == false)
	{
		cout << "Wrong Number" << endl;
		cout << "Press 1 if you wanna try again" << endl;
		cout << "Press 2 if you wanna register yourself" << endl;
		int Select = -1;
		while (Select < 1 || Select > 2) {
			cin >> Select;
		}
		switch (Select)
		{
		case 1:
			Start(c);
			break;
		case 2:
			c.AddPerson();
			Num = c.Vect.size() - 1;
			Menu(c);
			break;
		}
	}
}



