#include "ProcCenter.h"


vector<ProcCenter> buff;
ProcCenter::ProcCenter(string name, string middleName, string lastName, string cardNumber, int balance, int pin)
{
	string Name, MiddleName, LastName, CardNumber;
	int Balance, PIN;
	Name = name;
	LastName = lastName;
	MiddleName = middleName;
	Balance = balance;
	PIN = pin;
	SetProcC(Name, MiddleName, LastName, CardNumber, Balance, PIN);

}
void ProcCenter::SetProcC(string name, string middleName, string lastName, string cardNumber, int balance, int password)
{
	Name = name;
	MiddleName = middleName;
	LastName = lastName;
	CardNumber = cardNumber;
	Balance = balance;
	Password = password;

}
void ProcCenterVec::AddPerson()
{
	string Name, MiddleName, LastName, CardNumber;
	int Balance;
	int Password;

	cout << endl;
	cout << "Enter Name: ";
	cin >> Name;

	cout << endl << "Enter Middle Name: ";
	cin >> MiddleName;

	cout << endl << "Enter Last Name: ";
	cin >> LastName;

	cout << endl << "CreditCard Number ";
	cin >> CardNumber;

	cout << endl << "Balance: ";
	cin >> Balance;

	cout << endl << "Password ";
	cin >> Password;

	ProcCenter bufNabl(Name, MiddleName, LastName, CardNumber, Balance, Password);
	Vect.push_back(bufNabl);

}
ProcCenterVec::ProcCenterVec(const ProcCenter& d)
{
	buff.push_back(d);
	SetnameV(buff);
	Vect.pop_back();