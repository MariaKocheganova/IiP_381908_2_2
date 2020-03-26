/*# include <iostream>
#include <cmath>
using namespace std;

class Money //класс
{
private:
    int rub;
    int kop;
    int kop1;
    int rub1;
    double menu1;
    int menu;
    int prom;
    int rub2;
    int kop2;

public:
    Money(int Rub, int Kop, int Menu, int Rub1, int Kop1, double Menu1, int Prom, int Rub2, int Kop2) //эти параметры мы передадим при создании объекта в main
    {
        rub = Rub;
        kop = Kop;
        rub1 = Rub1;
        kop1 = Kop1;
        menu = Menu;
        menu1 = Menu1;
        prom = Prom;
        rub2 = Rub2;
        kop2 = Kop2;

    }

    void Schet() {                  //Функция преобразовывания копейки(>=100) в рубли
        if ((kop % 100 == 0) && (kop > 0)) {
            kop = kop / 100;
            rub = rub + kop;
            kop = 0;
        }
        if (kop > 100)
        {
            kop1 = kop % 100;
            kop = (kop - kop1) / 100;
            rub = rub + kop;
            kop = kop1;
        }
    }
    void Konvert() {
        kop = kop % 100;
        rub1 = rub1 - kop;
        rub = rub1 / 100;

    }

    void setMoney()
    {
        cout << "Введите количество рублей ";
        cin >> rub;
        cout << "Введите количество копеек ";
        cin >> kop;
        Schet();
        rub2 = rub;
        kop2 = kop;
    }

    void Menu() {
        cout << "1.Внести или снять сумму со счёта" << endl << "2.Умножить или разделить сумму" << endl << "3.Сравнить суммы" << endl << "4.Завершить обслуживание" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "1.Внести сумму" << endl << "2.Снять сумму" << endl;
            cin >> menu;
            if (menu == 1) {
                cout << "Количество рублей ";
                cin >> menu;
                cout << "Количество копеек ";
                cin >> menu1;
                rub = rub + menu; kop = kop + menu1;
            }
            else {
                cout << "Количество рублей ";
                cin >> menu;
                cout << "Количество копеек ";
                cin >> menu1;
                rub = rub - menu; kop = kop - menu1;
            }
            Schet();
            cout << "Ваш баланс " << rub << " рублей и " << kop << " копеек" << endl;
            break;

        case 2:
            prom = (rub * 100) + kop;
            cout << "1.Умножить сумму" << endl << "2.Разделить сумму" << endl;
            cin >> menu;
            if (menu == 1) {
                cout << "Во сколько раз увеличить сумму?" << endl << "В "; cin >> menu1;
                rub1 = prom * menu1;
                kop = rub1;
                Konvert();

            }
            else {
                cout << "Во сколько раз уменьшить сумму?"; cin >> menu1;
                rub1 = prom / menu1;
                kop = rub1;
                Konvert();

            }

            cout << "Ваш баланс " << rub << " рублей и " << kop << " копеек" << endl;
            break;

        case 3:
            if (rub2 > rub)
                cout << "Первоначальный басанс больше текущего на " << rub2 - rub << " рублей" << " и " << abs(kop2 - kop) << "копеек" << endl;
            else if (rub2 == rub) {
                if (kop2 > kop)
                    cout << "Первоначальный басанс больше текущего на " << kop2 - kop << " копеек" << endl;
                else if (kop2 == kop)
                    cout << "Баланс не был изменён" << endl;
                else
                    cout << "Первоначальный басанс меньше текущего на " << abs(kop - kop2) << " копеек" << endl;
            }
            if (rub2 < rub)
                cout << "Первоначальный басанс меньше текущего на " << abs(rub - rub2) << " рублей" << " и " << abs(kop - kop2) << "копеек" << endl;
            break;


        case 4:
            exit(0);
            break;

        }



        return Menu();
    }

    void getMoney()
    {
        cout << "\n" << "Ваш баланс " << rub << " рублей и " << kop << " копеек" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    Money obj1(0, 0, 0, 0, 0, 0, 0, 0, 0);  //передаем конструктору параметры

    obj1.setMoney();   //присвоим новые значения переменным
    obj1.getMoney();  //и выведем их на экран
    obj1.Menu();

}*/