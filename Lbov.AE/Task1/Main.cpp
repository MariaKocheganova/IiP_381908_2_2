#include"Header.h"
int  main() {
	setlocale(LC_ALL, "rus");
	 int n,k,n1,k1;
	 float f;
	Money rub,m;
	n = 0; f = 0; n1 = 0;
	cout << "Пожалуйста,введите ваш баланс в формате (Рубли, Enter ,Копейки)"<<endl;
	cin >> rub;
	cout << rub;
	m.setOp(n, f, n1);
	do {

		cout << "1.Внести или снять сумму со счёта" << endl << "2.Умножить или разделить сумму" << endl << "3.Сравнить начальный баланс и текущий" << endl << "4.Завершить обслуживание" << endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "1.Внести сумму" << endl << "2.Снять сумму" << endl;
			cin >> k1;
			if (k1 == 1) {
				f = 0;
				cout << "Количество рублей ";
				cin >> n;
				cout << "Количество копеек ";
				cin >> n1;
				m.setOp(n, f, n1);
				rub = rub + m;
				cout << rub;
			}
			if (k1 == 2) {
				f = 0;
				cout << "Количество рублей ";
				cin >> n;
				cout << "Количество копеек ";
				cin >> n1;
				m.setOp(n, f, n1);
				rub = rub - m;
				cout << rub;
		
			}
			break;
		case 2:
			cout << "1.Умножить сумму" << endl << "2.Разделить сумму" << endl;
			cin >> k1;
			if (k1 == 1) {
				n = 0; n1 = 0;
				cout << "Во сколько раз увеличить сумму?" << endl << "В "; cin >> f;
				m.setOp(n, f, n1);
				rub = rub * m;
				cout << rub;
				}
			if (k1 == 2) {
				n = 0; n1 = 0;
				cout << "Во сколько раз уменьшить сумму?" << endl << "В "; cin >> f;
				m.setOp(n, f, n1);
				rub = rub / m;
				cout << rub;
		}
			break;
		case 3:
			rub == m;
			break;
		}
		
	}
		while (k != 4);
	

	return 0;
}
