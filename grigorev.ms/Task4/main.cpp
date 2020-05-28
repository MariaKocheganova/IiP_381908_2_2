#include"Songs.h"
#include<iostream>
#include<fstream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	Songs obj;
	ifstream fin;
	ofstream fout;
	fin.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Release/input.txt");
	bool check = true;
	while (check) {
		cout << endl << "Выберите дальнейшее действие:" << endl;
		cout << "    1 - добавить песню" << endl;
		cout << "    2 - изменить данные песни, выбранной по названию" << endl;
		cout << "    3 - найти песню по названию и исполнителю" << endl;
		cout << "    4 - выдать все песни заданного поэта" << endl;
		cout << "    5 - выдать все песни заданного композитора" << endl;
		cout << "    6 - выдать все песни заданного исполнителя" << endl;
		cout << "    7 - узнать текущее число песен" << endl;
		cout << "    8 - удалить песню по названию" << endl;
		cout << "    9 - сохранить песенник в файл или считать песенник из файла" << endl;
		cout << "    0 - выход" << endl << endl;
		cout << "Ваш выбор - ";
		int choise, pos;
		string name_c, lyric_c, music_c, singer_c, album_c, release_date_c;
		cin >> choise;
		switch (choise) {
		case(0):
			cout << "До свидания!!!" << endl;
			check = false;
			break;
		case(1):
			cout << endl << "Введите название - ";
			cin >> name_c;
			cout << "Введите автора текста - ";
			cin >> lyric_c;
			cout << "Введите автора музыки - ";
			cin >> music_c;
			cout  << "Введите исполнителя - ";
			cin >> singer_c;
			cout  << "Введиете название альбома - ";
			cin >> album_c;
			cout  << "Введите дату релиза - ";
			cin >> release_date_c;
			cout << endl;
			obj.Add(name_c, lyric_c, music_c, singer_c, album_c, release_date_c);
			break;
		case(2):
			cout << endl << "Введите название - ";
			cin >> name_c;
			obj.Change(name_c);
			cout << "Операция завершенна успешно" << endl;
			break;
		case(3):
			cout << endl << "Введите название - ";
			cin >> name_c;
			cout << "Введите имя исполнителя - ";
			cin >> singer_c;
			obj.Find(name_c, singer_c);
			break;
		case(4):
			cout << endl << "Введите автора текста - ";
			cin >> lyric_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Lyric() == lyric_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(5):
			cout << endl << "Введите автора музыки - ";
			cin >> music_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Music() == music_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(6):
			cout << endl << "Введите исполнителя - ";
			cin >> singer_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Singer() == singer_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(7):
			cout << endl << "Текущее число песен - " << obj.Get_Size() << endl;
			break;
		case(8):
			cout << endl << "Введите название - ";
			cin >> name_c;
			obj.Delete(name_c);
			break;
		case(9):
			cout << endl << "    Выберите дальнейшее действие:";
			cout << endl << "        1 - сохранить в файл";
			cout << endl << "        2 - загрузить из файла" << endl;
			cout << "Ваш выбор - ";
			int way;
			cin >> way;
			if (way == 1) {
				cout << "Будет сохранено " << obj.size << " песен" << endl;
				fout.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Release/input.txt");
				fout << obj.size << endl;
				for (int i = 0; i < obj.size; i++) {
					fout << obj.list[i].Get_Name() << " " << obj.list[i].Get_Lyric() << " " << obj.list[i].Get_Music() << " " << obj.list[i].Get_Singer() << " " << obj.list[i].Get_Album() << " " << obj.list[i].Get_Date() << endl;
				}
			}
			else if (way == 2) {
				int fsize;
				fin >> fsize;
				cout << "Будет загружено " << fsize << " песен" << endl;
				for (int i = 0; i < fsize; i++) {
					fin >> name_c >> lyric_c >> music_c >> singer_c >> album_c >> release_date_c;
					obj.Add(name_c, lyric_c, music_c, singer_c, album_c, release_date_c);
				}
			}
			break;
		}
	}
}