#include "Bankomat.h"


Bankomat::Bankomat(int _size, int _buf, ProcCenter* _cards)
{
	
	count1 = 1600;
	count2 = 1600;
	count5 = 1600;
	count10 = 1600;
	count20 = 1600;
	count50 = 1600;
	clientcount = _size;
	bufsize = _buf;
	cards = new ProcCenter[bufsize];
	for (int i = 0; i < clientcount; i++)
		cards[i] = _cards[i];
}
Bankomat::Bankomat(string filename)
{

	count1 = 1600;
	count2 = 1600;
	count5 = 1600;
	count10 = 1600;
	count20 = 1600;
	count50 = 1600;
	ifstream stream;
	stream.open(filename);
	stream >> clientcount;
	stream.ignore();
	cards = new ProcCenter[clientcount + 20];
	for (int i = 0; i < clientcount; i++)
	{
		stream >> cards[i];
		stream.ignore();
	}
}
int Bankomat::InsertCard(int _num)
/*BUG Непонятно, что за метод  */
{
	int ex = 0;
	for (int i = 0; i < clientcount; i++)
	{
		if (cards[i].GetNumOfCard() == _num)
		{
			card = cards[i];
			ex++;
		}
	}
	if (ex) return 1;
	else return 4;
}
int Bankomat::CashDeposit(int _mon)
{
	int count = 0;
	if (!card.IsBlocked())
	{
		if (_mon % 100 == 0)
		{
			count += _mon / 5000;
			count50 += _mon / 5000;
			_mon %= 5000;
			count += _mon / 2000;
			count20 += _mon / 2000;
			_mon %= 2000;
			count += _mon / 1000;
			count10 += _mon / 1000;
			_mon %= 1000;
			count += _mon / 500;
			count5 += _mon / 500;
			_mon %= 500;
			count += _mon / 200;
			count2 += _mon / 200;
			_mon %= 200;
			count += _mon / 100;
			count1 += _mon / 100;
			_mon %= 100;
			if (count <= 40)
			{
				if (this->IsCount())
				{
					card.AddMoney(_mon);
					return 1;
				}
				else return 2;
			}
			else return 3;
		}
		else return 0;
	}
	else return -1;
}
int Bankomat::CashWithdraw(int _mon)
{
	int count = 0;
	if (!card.IsBlocked())
	{
		if (_mon % 100 == 0)
		{
			count += _mon / 5000;
			count50 -= _mon / 5000;
			_mon %= 5000;
			count += _mon / 2000;
			count20 -= _mon / 2000;
			_mon %= 2000;
			count += _mon / 1000;
			count10 -= _mon / 1000;
			_mon %= 1000;
			count += _mon / 500;
			count5 -= _mon / 500;
			_mon %= 500;
			count += _mon / 200;
			count2 -= _mon / 200;
			_mon %= 200;
			count += _mon / 200;
			count1 -= _mon / 100;
			_mon %= 100;
			if (count <= 40)
			{
				if (this->IsCount())
				{
					if (card.SubMoney(_mon) == 1)
						return 1;
					else return -2;
				}
				else return 5;
			}
			else return 3;
		}
		else return 0;
	}
	else return -1;
}
bool Bankomat::IsCount()
{
	if (count1 <= 2000 && count2 <= 2000 && count5 <= 2000 && count10 <= 2000 && count20 <= 2000 && count50 <= 2000)
		return true;
	else return false;
}
string Bankomat::GetNameByCardNum(int _num)
{
	for (int i = 0; i < clientcount; i++)
	{
		if (cards[i].GetNumOfCard() == _num)
			return cards[i].GetName();
	}
}
void Bankomat::PrintAnsw(int _ans)
{
	if (_ans == 1) cout << "Операция успешно выполнена. " << endl;
	if (_ans == -1) cout << "Ошибка. Карта заблокирована. " << endl;
	if (_ans == -2) cout << "Ошибка. На вашем счете недостаточно средств для выполнения операции." << endl;
	if (_ans == 0) cout << "Ошибка. Сумма вносимых/снимаемых денег должна быть кратна 100. " << endl;
	if (_ans == 2) cout << "Ошибка. Кассеты(а) банкомата переполнены. Просим прощения за неудобства." << endl;
	if (_ans == 3) cout << "Ошибка. Банкомат может совершать оперцаии с не более чем 40 купюрами. " << endl;
	if (_ans == 4) cout << "Ошибка. Клиента с таким номером карты нет в базе данных." << endl;
	if (_ans == 5) cout << "Ошибка. Кассеты(а) банкоматы пусты. Просим прощения за неудобства. " << endl;
}
void Bankomat::PrintStatus()
{
	card.PrintClientStatus();
}
int Bankomat::PinSt(string _pin)
{
	return card.IsPinRight(_pin);
}
istream& operator >> (istream& stream, Bankomat& b)
{
	int n;
	stream >> n;
	stream.ignore();
	int sum, num;
	string pin, name;
	for (int i = 0; i < n; i++)
	{
		stream >> num;
		stream >> name;
		stream >> pin;
		stream >> sum;
		b.cards[i].SetNumOfCard(num);
		b.cards[i].SetName(name);
		b.cards[i].SetPin(pin);
		b.cards[i].SetSum(sum);
		stream.ignore();
		stream.ignore();
	}
	return stream;
}