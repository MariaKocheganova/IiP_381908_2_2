#include "Header.h"
int main() {
	setlocale(LC_ALL, "Russian");
	Tabulator x;
	int x1, a1, b1, n1,k;
	cout << "1.���� �������� ������������� [a, b] � �������� ���������� ����� ���������"<<endl<<"2.������ ����� ����� ������������� n"<<endl<<"3.������ �������� �������������"<<endl<<"4.������ ����� ����� �������������"<<endl<<"5.��������� ������������� �������"<<endl<<"6.��������� �������� �������������� ������� � �������� ����� x � �������� ��� �������� �� ��������� �������� ������� � ���� �����"<<endl<<"7.��������� ������"<<endl;
	
	do {
		cin >> k;
		switch (k) {
		case 1:
			cout << "������� �������� ������������ a � b" << endl;
			cin >> a1 >> b1;
			x.interval(a1, b1);
			break;
		case 2:
			cout << "������� ����� ����� ������������ n" << endl;
			cin >> n1;
			x.num(n1);
			break;
		case 3:
			x.interval1();
			break;
		case 4:
			x.num1();
			break;
		case 5:
			x.tab();

			break;
		case 6:


			break;
		}
	} while (k != 7);
	




	return 0;
}