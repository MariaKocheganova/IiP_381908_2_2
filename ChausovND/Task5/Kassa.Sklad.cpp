#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Sklad
{
public:
	string returnName(int i)
	{
		return name[i];
	}
	int returnPrice(int i)
	{
		return price[i];
	}
	void newItem()
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
	int search(int brcd4)
	{
		for (int i = 0; i < brcd.size(); i++)
			if (brcd4 == brcd[i])
				return i;
		return 1;
	}

private:
	vector <int> brcd; vector <string>name; vector <int> price;
};

class Kassa
{
public:
	void menu()
	{
		int menu;
		bool flag = true;
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

			switch (menu)
			{
			case 1:
				wrhs.newItem();
				break;
			case 2:
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
			case 3:
				formCheque();
				break;
			case 4:
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
			case 5:
				if (cheque.size() != 0)
				{
					cheque.pop_back();
					cout << "----- The last added item has been removed from the cheque -----\n";
				}
				else
					cout << "----- The cheque is empty -----\n";
				break;
			case 6:
				flag = false;
				break;
			default:
				cout << "Wrong action number. Enter a number from 1-6:" << endl;
				break;
			}
		}
	}
	void formCheque()
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
			for (int i = 1; i < cheque.size(); i++)
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
				else
					q++;
			}
			cout << "Total: " << total << endl;
			cheque.pop_back();
		}
	}

private:
	Sklad wrhs;
	vector <int> cheque;
};

int main()
{
	Kassa K;
	K.menu();

	system("pause");
	return 0;
}