#include "Header.h"

using namespace std;


int main()
{
	int i, j, k;
	cout << "Enter Days -  " << endl;
	cin >> i;
	cout << "Enter Months -  " << endl;
	cin >> j;
	cout << "Enter Years -  " << endl;
	cin >> k;

	cout << i << "." << j << ":" << k << endl;


	Date a(i, j, k);
	if (i <= 31 && j <= 12 && k > 0)
	{
		a.operator=(a);
		a.operator+(j);
		a.operator-(j);

	}
	else cout << "Error" << endl;



	system("pause");
	return 0;
}
