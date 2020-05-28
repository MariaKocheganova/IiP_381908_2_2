#include"coniow.h"
#include<iostream>
#include"TextEditor.h"
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	bool exit = true;
	TextEditor Window(1, 1, 40);
	while (exit) {
		unsigned int choise;	
		cout << "Выберите дальнейшее действие" << '\n';
		cout << "    1 - Ввод положения и размера окна" << '\n';
		cout << "    2 - Показать редактор" << '\n';
		cout << "    3 - Убрать редактор" << '\n';
		cout << "    4 - Ввод и редактирование текста" << '\n';
		cout << "    5 - Завершение работы" << '\n';
		cout << "Ваш выбор: ";
		cin >> choise;
		switch(choise){
		case(1):
			textbackground(BLUE);
			textcolor(WHITE);
			Window.SetSize(0, 0, 10);
			break;
		case(2): // Показать редактор
			textbackground(BLUE);
			textcolor(WHITE);
			Window.OutputText();
			break;
		case(3): // Убрать редактор
			break;
		case(4): // Введите и отредактируйте текст
			textbackground(BLUE);
			textcolor(WHITE);
			Window.InputText();
			break;
		case(5): // Завершение работы
			exit = false;
			cout << '\n' << "До свидания! Хорошего дня!" << '\n';
			break;
		}
	}
}