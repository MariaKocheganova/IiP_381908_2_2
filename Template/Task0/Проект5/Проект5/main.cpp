#include <iostream>
#include <fstream>
#include "Fun.h"
using namespace std;
int main()
{
	int tab = 1;
	while (tab == 1)
	{
		setlocale(LC_ALL, "RUSSIAN");
		int menu = 0;
		cout << "1.Проверка класса Ccomplex." << endl;
		cout << "2.Проверка класса Cstring." << endl;
		cout << "Введите номер пункта:";
		cin >> menu;
		switch (menu)
		{
			case 1:
			{
				Ccomplex num1;
				Ccomplex num2;
				Ccomplex res1;
				Ccomplex res2;
				Ccomplex num3;
				Ccomplex num4;
				Ccomplex res3;
				Ccomplex res4;
				num1.InPut();
				cout << "Введите для второго числа.";
				cout << endl;
				num2.InPut();
				num3 = num1;
				num4 = num2;
				res1 = num1.Add(num2);
				res2 = num1.Mlt(num2);
				cout << "Результат сложения:";
				res1.output();
				cout << "       //Через метод//Вывод через метод";
				cout << endl;
				cout << "Результат умножения:";
				res2.output();
				cout << "       //Через метод//Вывод через метод";
				cout << endl;
				res3 = num3 + num4;
				res4 = num3 *num4;
				cout << "Результат сложения:";
				cout << res3;
				cout << "       //Через операцию//Вывод через операцию";
				cout << endl;
				cout << "Результат умножения:";
				cout << res4;
				cout << "       //Через операцию//Вывод через операцию";
				cout << endl;
				break;
			}
			case 2:
			{
				Cstring s1;
				Cstring s3(10, '*');
				Cstring s4(15);
				Cstring s2("Мария ");
				Cstring s5(s2);
				s3.outPut("s3");
				s4.outPut("s4");
				s2.outPut("s2");
				s5.outPut("s5");
				s3 = s2;
				s3.outPut("s3");
				s2 = "Кочеганова";
				s2.outPut("s2");
				s5 = s3 + s2;
				s5.outPut("s5");
				s3 += s2;
				s3 = "Сигареты";
				s3 += " - вредны  для здоровья";
				s3.outPut("s3");
				// Запись в поток
				s1 = "Даниил ";
				s2 = "Пигасин";
				ofstream os; // поток для записи
				os.open("str.txt"); // файл для записи
				os << s1 << s2 << endl;
				os.close();
				// Чтение из потока
				ifstream is; // поток для чтения
				is.open("str.txt"); // файл для чтения
				is >> s3 >> s4;
				cout << "s3: " << s3;
				cout << "s4: " << s4;
				is.close();
				break;
			}
		}
		cout << "Если хотите запустить программу заново нажмите '1'...";
		cin >> tab;
	} 
	cout << endl;
	system("pause");
	return 0;
}