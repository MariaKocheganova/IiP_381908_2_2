#include<iostream>
#include "Vector3D.h"
using namespace std;

int main()
{
	Vector3D vec1, vec2, vec3;
	int menu, a,b;
	bool flag = true;
	while (flag)
	{
		p1: cout << "Choose an action:\n1) Assign\n2) Summarize\n3) Subtract\n4) Compare\n5) Find the dot product\n6) Multiply by a number\n";
		cin >> menu;

		if (menu < 6 && menu >1)
		{
			cout << "Enter the first vector:";
			cin >> vec1;
			cout << "Enter the second vector:";
			cin >> vec2;
		}
		else if (menu == 6)
		{
			cout << "Enter the first vector:";
			cin >> vec1;
			cout << "Enter a number:";
			cin >> a;
		}
		else if (menu == 1)
		{
			cout << "Enter the first vector:";
			cin >> vec1;
		}
		else
		{
			cout << "Wrong number\n";
			goto p1;
		}

		switch (menu)
			{
			case 1:
				vec2 = vec1;
				cout << "vec1 has been successfully copied to vec2. "<<vec2;
				break;
			case 2:
				cout << vec1 + vec2;
				break;
			case 3:
				cout << vec1 - vec2;
				break;
			case 4:
				if (vec1 == vec2)
					cout << "Equal\n";
				else cout << "Not equal\n";
				break;
			case 5:
				cout<<"Result: "<<vec1 * vec2<<"\n";
				break;
			case 6:
				cout << vec1 * a;
				break;
			default:
				cout << "Wrong number\n";
			}
		cout << "Enter 1 to start over, 2 to exit\n";
		cin >> b;
		if (b == 2)
			flag = false;
	}
}