#include "Menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

void coutMenu() { 
    SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x5D);
    cout << "\x1B[32m __   __  ______   _   _   _    _ \033[0m" << endl;
    cout << "\x1B[32m|  \\/  | |  ____| | \\ | | | |  | | \033[0m" << endl;
    cout << "\x1B[32m| \\  / | | |__    |  \\| | | |  | | \033[0m" << endl;
    cout << "\x1B[32m| |\\/| | |  __|   | . ` | | |  | | \033[0m" << endl;
    cout << "\x1B[32m| |  | | | |____  | |\\  | | |__| | \033[0m" << endl;
    cout << "\x1B[32m|_|  |_| |______| |_| \\_|  \\____/ \033[0m" << endl;
   
    Sleep(3000);
    system("cls");
}


Menu::Menu() {};
Menu::Menu(int pun, string* name) {
    setlocale(LC_ALL, "rus");
    coutMenu();

strt:
    bool exit = false;
    int ch;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { 0, 0 };
    

    for ( int i = 0; i <pun; i++)
    {
        cout << char(16) << i + 1 << "." << " " << name[i] << endl;
    }
    cout << endl;
    cout << "Навигация:" << endl << "Пробел - выбрать пункт" << endl << "Esc - Выход" << endl << "Стрелки - навигация" << endl << "Таб - вернуться в главное меню" << endl;
    SetConsoleCursorPosition(hConsole, position);
    while (!exit)
    {
        ch = _getch();
        switch (ch)
        {
        case 224:
        {
            switch (_getch())
            {

            case 72:
            {
                if (position.Y)
                {
                    cout << " ";
                    position.Y--;
                    SetConsoleCursorPosition(hConsole, position);
                    cout << (char)16;
                    SetConsoleCursorPosition(hConsole, position);
                }
                break;
            }
            case 80:
            {
                if (position.Y < pun-1)
                {
                    cout << " ";
                    position.Y++;
                    SetConsoleCursorPosition(hConsole, position);
                    cout << (char)16;
                    SetConsoleCursorPosition(hConsole, position);
                }
                break;
            }


            default:
                break;
            }
            break;
        }
        case 32:
        {
            system("cls");
            cout << "Выбран пункт:" << position.Y + 1 << endl;
            int esc = _getch();
            if (esc == '\t') {
                system("cls");
                goto strt;
            }
            break;
        }

        case 27:
        {
            exit = true;
            break;
        }
        default:
            break;
        }
    }

};
Menu::Menu(string file) {
    int pun = 0;
    ifstream in(file, ios::in);
    string line;
    while (getline(in, line))
    {
        pun++;
    }
    string* name = new string[pun];
    
    for (int i = 0; i < pun; i++) {
        
        getline(in, line);
        name[i] = line;
        
        
    }
    in.close();
    setlocale(LC_ALL, "rus");
    coutMenu();

strt:
    bool exit = false;
    int ch;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { 0, 0 };


    for (int i = 0; i < pun; i++)
    {
        cout << char(16) << i + 1 << "." << " " << name[i] << endl;
    }
    cout << endl;
    cout << "Навигация:" << endl << "Пробел - выбрать пункт" << endl << "Esc - Выход" << endl << "Стрелки - навигация" << endl << "Таб - вернуться в главное меню" << endl;
    SetConsoleCursorPosition(hConsole, position);
    while (!exit)
    {
        ch = _getch();
        switch (ch)
        {
        case 224:
        {
            switch (_getch())
            {

            case 72:
            {
                if (position.Y)
                {
                    cout << " ";
                    position.Y--;
                    SetConsoleCursorPosition(hConsole, position);
                    cout << (char)16;
                    SetConsoleCursorPosition(hConsole, position);
                }
                break;
            }
            case 80:
            {
                if (position.Y < pun - 1)
                {
                    cout << " ";
                    position.Y++;
                    SetConsoleCursorPosition(hConsole, position);
                    cout << (char)16;
                    SetConsoleCursorPosition(hConsole, position);
                }
                break;
            }


            default:
                break;
            }
            break;
        }
        case 32:
        {
            system("cls");
            cout << "Выбран пункт:" << position.Y + 1 << endl;
            int esc = _getch();
            if (esc == '\t') {
                system("cls");
                goto strt;
            }
            break;
        }

        case 27:
        {
            exit = true;
            break;
        }
        default:
            break;
        }
    }
};