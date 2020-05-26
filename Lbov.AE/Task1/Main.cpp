#include"Money.h"
int  main() {
	setlocale(LC_ALL, "rus");
	int n, k, n1, k1;
	int  f;
	Money rub, m, m1;
	n = 0;  n1 = 0;
	cout << "Пожалуйста,введите ваш баланс в формате (Рубли, Enter ,Копейки)" << endl;
	cin >> rub;
	cout << rub;

	do {

		cout << "1.Внести или снять сумму со счёта" << endl << "2.Умножить или разделить сумму" << endl << "3.Сравнить баланс и ввёденный " << endl << "4.Завершить обслуживание" << endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "1.Внести сумму" << endl << "2.Снять сумму" << endl;
			cin >> k1;
			if (k1 == 1) {

				cout << "Количество рублей ";
				cin >> n;
				cout << "Количество копеек ";
				cin >> n1;
				Money m1(n, n1);
				rub = rub + m1;
				cout << rub;
			}
			if (k1 == 2) {

				cout << "Количество рублей ";
				cin >> n;
				cout << "Количество копеек ";
				cin >> n1;
				Money m1(n, n1);
				rub = rub - m1;
				cout << rub;

			}
			break;
		case 2:
			cout << "1.Умножить сумму" << endl << "2.Разделить сумму" << endl;
			cin >> k1;
			if (k1 == 1) {
				cout << "Во сколько раз увеличить сумму?" << endl << "В "; cin >> f;
				Money m1(f);
				rub = rub * m1;
				cout << rub;
			}
			if (k1 == 2) {

				cout << "Во сколько раз уменьшить сумму?" << endl << "В "; cin >> f;
				Money m1(f);
				rub = rub / m1;
				cout << rub;
			}
			break;
		case 3:
			cout << "Введите баланс с которым будет сравнение ";
			cin >> n >> n1;
			Money m1(n, n1);
			if (rub == m1)
				cout << "Суммы равны" << endl;
			else
				cout << "Суммы не равны" << endl;
			break;

		}

	} while (k != 4);


	return 0;
}