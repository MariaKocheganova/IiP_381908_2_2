#include "ProcCenter.h"
ProcCenter::ProcCenter(int num, string _pin, int _sum, string _name)
{
	numofcard = num;
	pin = _pin;
	sum = _sum;
	name = _name;
	countofpin = 0;
	status = 1;
}
ProcCenter::ProcCenter()
{
	countofpin = 0;
	numofcard = 0;
	pin = "";
	sum = 0;
	name = "";
	countofpin = 0;
	status = 1;
}
ProcCenter::~ProcCenter()
{
	numofcard = 0;
	pin.clear();
	sum = 0;
	name.clear();
}
ProcCenter& ProcCenter::operator=(const ProcCenter _card)
{
	numofcard = _card.numofcard;
	pin = _card.pin;
	sum = _card.sum;
	name = _card.name;
	countofpin = 0;
	status = _card.status;
	return *this;
}
int ProcCenter::IsPinRight(string _pin)
{
	if (!(this->IsBlocked())) {
		if (pin == _pin) {

			countofpin = 0;
			return 1;
		}
		else {
			countofpin++;
			if (countofpin == 3)
			{
				status = 0;
				return -1;
			}
			return 0;
		}
	}
	else return -1;
}
void ProcCenter::PrintClientStatus()
{
	cout << "Статус клиента." << endl;
	cout << "Номер карты клиента: " << numofcard << endl;
	cout << "Имя клиента: " << name << endl;
	if (status)
		cout << "Баланс: " << this->sum << endl;
	else cout << "Ошибка. Карта заблокирована." << endl;
}
void ProcCenter::AddMoney(int _mon)
{
	sum = sum + _mon;
}
int ProcCenter::SubMoney(int _mon)
{
	sum = sum - _mon;
	if (sum <= 0)
		return 6;
	else return 1;
}
bool ProcCenter::IsBlocked()
{
	if (status) return false;
	else return true;
	/*BUG просто return status; */
}
istream& operator >> (istream& stream, ProcCenter& pc)
{
	string _name, _pin;
	int _num, _sum;
	stream >> _num;
	stream >> _name;
	stream >> _pin;
	stream >> _sum;
	pc.name = _name;
	pc.numofcard = _num;
	pc.pin = _pin;
	pc.sum = _sum;
	return stream;
}