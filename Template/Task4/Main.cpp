#include <iostream>
#include"FloorScales.h"
#include "User.h"

using namespace std;

int main() {
	int n;
	cin >> n;
	system("cls");
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = abs(n - i);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	vector <Unit> a;

}