#include "DateHeader.h"

using namespace std;

int main()
{
	int A, B;
	do
	{

		cin >> A;
		if (A == 1)
		{
			Date res;
			int DaysPlus;
			cout << "Choose:  " << endl;
			cout << "1 - by number " << endl;
			cout << "2 - by string: " << endl;
			cin >> B;
			if (B == 1)
			{
				Date d1;
				cout << "ENTER DATE:" << endl;
				cin >> d1;
				cout << "ENTER NUMBER OF DAYS: " << endl;
				cin >> DaysPlus;
				res = d1 + DaysPlus;
				cout << "The date is: " << res << endl;
			}
			if (B == 2)
			{
				string d1;
				Date d2;
				cout << "ENTER DATE:" << endl;
				cin >> d1;
				d2 = d1;
				cout << "ENTER NUMBER OF DAYS: " << endl;
				cin >> DaysPlus;
				res = d2 + DaysPlus;
				cout << "The date is: " << res << endl;
			}
		}
		if (A == 2)
		{
			Date res;
			int DaysMinus;
			cout << "Choose:  " << endl;
			cout << "1 - by number " << endl;
			cout << "2 - by string: " << endl;
			cin >> B;
			if (B == 1)
			{
				Date d1;
				cout << "ENTER DATE:" << endl;
				cin >> d1;
				cout << "ENTER NUMBER OF DAYS: " << endl;
				cin >> DaysMinus;
				res = d1 - DaysMinus;
				cout << "The date is: " << res << endl;
			}
			if (B == 2)
			{
				string d1;
				Date d2;
				cout << "ENTER DATE:" << endl;
				cin >> d1;
				d2 = d1;
				cout << "ENTER NUMBER OF DAYS: " << endl;
				cin >> DaysMinus;
				res = d2 - DaysMinus;
				cout << "The date is: " << res << endl;
			}
		}
		if (A == 3)
		{
			cout << "Choose:  " << endl;
			cout << "1 - by number " << endl;
			cout << "2 - by string: " << endl;
			cin >> B;
			if (B == 1)
			{
				Date d1, d2;
				cout << "ENTER FIRST AND SECOND DATE: " << endl;
				cin >> d1;
				cin >> d2;
				if (d1 == d2)
				{
					cout << "They are equal!" << endl;
				}
				if (d1 > d2)
				{
					cout << " Date 1 > Date 2 " << endl;
				}
				if (d1 < d2)
				{
					cout << " Date 1 < Date 2 " << endl;
				}
			}
			if (B == 2)
			{
				string d1, d2;
				cout << "ENTER FIRST AND SECOND DATE: " << endl;
				cin >> d1;
				cin >> d2;
				if (d1 == d2)
				{
					cout << "They are equal!" << endl;
				}
				if (d1 > d2)
				{
					cout << " Date 1 > Date 2" << endl;
				}
				if (d1 < d2)
				{
					cout << " Date 1 < Date 2 " << endl;
				}
			}
		}
	} while (A != 0);
	return 0;
}

