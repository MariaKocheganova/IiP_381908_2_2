#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class ProcCenter {
	/*BUG Это не процессинговый центр. Это один клиент  */
private:
	int numofcard;
	int sum;
	int countofpin;
	/*BUG Что это такое? */

	string pin;  /*BUG Почему string? */
	string name;

	bool status;//status of card: 0 - blocked, 1 - not blocked
public:

	ProcCenter(int num, string _pin, int _sum, string _name);
	ProcCenter();
	~ProcCenter();
	int IsPinRight(string _pin);
	void PrintClientStatus();
	bool IsBlocked();
	void AddMoney(int _mon);
	int SubMoney(int _mon);
	bool GetStatus() const { return status; }
	/*BUG Чем отличается от IsBlocked?  */
	int GetNumOfCard() const { return numofcard; }
	int GetSum() const { return sum; }
	string GetName() const { return name; }
	ProcCenter& operator=(const ProcCenter _card);

	void SetName(string _name) { name = _name; }
	void SetNumOfCard(int _num) { numofcard = _num; }
	void SetPin(string _pin) { pin = _pin; }
	void SetSum(int _sum) { sum = _sum; }

	friend istream& operator >> (istream& stream, ProcCenter& pc);
};