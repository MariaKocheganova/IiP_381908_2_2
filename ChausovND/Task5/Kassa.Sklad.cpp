#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Sklad
{
public:
	string returnName(int i) //возврат названи€ товара
	{
		return name[i];
	}
	int returnPrice(int i)  //возврат стоимости товара
	{
		return price[i];
	}
	void newItem() //добавление нового товара в каталог
	{
		int brcd2, price2;
		string name2;
		cout << "-- New catalog entry --\n";
		cout << "Enter barcode: "; cin >> brcd2;
		brcd.push_back(brcd2);
		cout << "Enter name: "; cin >> name2;
		name.push_back(name2);
		cout << "Enter price: "; cin >> price2;
		price.push_back(price2);
		cout << "Entry added to the catalog successfully\n";
	}
	int search(int brcd4) //поиск нужного товара в каталоге
	{
		for (int i = 0; i < brcd.size(); i++)
			if (brcd4 == brcd[i])
				return i; //если находим - возвращаем его индекс
		return 1; //если не находим - возвращаем 1 (будет использоватьс€ как false)
	}

private:
	vector <int> brcd; vector <string>name; vector <int> price; //хранение штрихкода, названи€ и стоимости товара
};

class Kassa
{
public:
	void menu() //основное меню
	{
		int menu;
		bool flag = true; //флажок дл€ определени€ необходимости повторного вывода меню
		while (flag)
		{
			cout << "----- Choose an action -----" << endl;
			cout << "1) Add a new item to the catalog..." << endl;
			cout << "2) Choose an item to buy..." << endl;
			cout << "3) Display cheque" << endl;
			cout << "4) Display item description..." << endl;
			cout << "5) Remove the last item from the cheque " << endl;
			cout << "6) Exit" << endl;
			cin >> menu;

			switch (menu)  //выбор пункта меню
			{
			case 1:
				wrhs.newItem(); //добавление нового товара в каталог
				break;
			case 2: //ѕоиск и добавление товара в чек
			{
				int brcd3;
				cout << "----- Cash register -----\n";
				cout << "Enter barcode: "; cin >> brcd3;
				menu = wrhs.search(brcd3);

				if (menu == 1)
					cout << "Found no item with such barcode" << endl;
				else
				{
					cout << "Item found and added to the cheque" << endl;
					cheque.push_back(menu);
				}
				break;
			}
			case 3: //вывод чека
				formCheque();
				break;
			case 4: //вывод информации о выбранном по штрихкоду товаре
			{
				int brcd5;
				cout << "Enter barcode: "; cin >> brcd5;
				menu = wrhs.search(brcd5);

				if (menu == 1)
					cout << "Found no item with such barcode" << endl;
				else
				{
					int menu2;
					cout << "Item found" << endl;
					cout << "Name: " << wrhs.returnName(menu) << endl;
					cout << "Price: " << wrhs.returnPrice(menu) << endl;
				}
				break;
			}
			case 5: //удаление последнего добавленного в чек товара
				if (cheque.size() != 0)
				{
					cheque.pop_back();
					cout << "----- The last added item has been removed from the cheque -----\n";
				}
				else
					cout << "----- The cheque is empty -----\n";
				break;
			case 6: //выход из программы
				flag = false; //сн€тие флажка при желании выйти из программы
				break;
			default: //просьба выбрать правильный номер действи€
				cout << "Wrong action number. Enter a number from 1-6:" << endl;
				break;
			}
		}
	}
	void formCheque() //формирование чека
	{
		int	 total = 0;
		if (cheque.size() == 0)
			cout << "The cheque is empty" << endl;
		else 
		{
			int q = 1;
			sort(cheque.begin(), cheque.end()); 
			cheque.push_back(9999);
			cout << "----- The cheque -----" << endl;
			for (int i = 1; i < cheque.size(); i++) //заполнение чека информацией о товарах
			{
				if (cheque[i - 1] != cheque[i]) 
				{
					cout << "Name: " << wrhs.returnName(cheque[i - 1]) << endl;
					cout << "Price: " << wrhs.returnPrice(cheque[i - 1]) << endl;
					cout << "Quantity: " << q << endl;
					total += wrhs.returnPrice(cheque[i - 1]) * q;
					cout << "--------------------" << endl;
					q = 1;
				}
				else //если товар повтор€етс€ - увеличить количество, не добавл€€ ещЄ один
					q++; 
			}
			cout << "Total: " << total << endl;
			cheque.pop_back();
		}
	}

private:
	Sklad wrhs;
	vector <int> cheque; //хранение чека
};