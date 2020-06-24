#include <iostream>
#include "Integrals.h"
using namespace std;

Integrals::Integrals()
{
    a = 0, b = 0, q = 0;
}

Integrals::Integrals(int a2, int b2, int q2)
{
    a = a2;
    b = b2;
    q = q2;
}

Integrals::Integrals(const Integrals& s)
{
    a = s.a;
    b = s.b;
    q = s.q;
}

int Integrals::fnum() //выбор функции
{
    int func;
    cout << "Choose a function: \n";
    cout << "1) y = cos(x)" << endl;
    cout << "2) y = x^3" << endl;
    cout << "3) y = sqrt(x^4 + 6x + 5)" << endl << endl;

    cin >> func;
    f = func;
    return func;
}

double func(double x, int fnum2) //вычисление функции
{
    switch (fnum2)
    {
    case 1:
        return cos(x);
        break;
    case 2:
        return pow(x, 3);
        break;
    case 3:
        return sqrt(pow(x, 4) + 6 * x + 5);
        break;
    }
}

double Integrals::methodM() //midpoint method
{
    double step = (b - a) / q, y = 0, c = 0, t = 0, x1, x2, y1, y2;

    for (double x = a + step / 2; x < b; x = x + step)
    {
        y = func(x, f);
        x1 = x - step / 2;
        x2 = x + step / 2;
        y1 = y;
        y2 = 0;
        t = abs(x1 - x2) * abs(y1 - y2);
        c = c + t;
    }
    cAvg = cAvg + c;
    return cAvg;
}

double Integrals::methodL() //left endpoint method
{
    double step = (b - a) / q, y = 0, c = 0, t = 0, x1, x2, y1, y2;

    for (double x = a; x < b; x = x + step)
    {
        y = func(x, f);
        x1 = x;
        x2 = x + step;
        y1 = y;
        y2 = 0;
        t = abs(x1 - x2) * abs(y1 - y2);
        c = c + t;
    }
    cAvg = cAvg + c;
    return cAvg;
}

double Integrals::methodR() //right endpoint method
{
    double step = (b - a) / q, y = 0, c = 0, t = 0, x1, x2, y1, y2;

    for (double x = a + step; x <= b; x = x + step)
    {
        y = func(x, f);
        x1 = x - step;
        x2 = x;
        y1 = y;
        y2 = 0;
        t = abs(x1 - x2) * abs(y1 - y2);
        c = c + t;
    }
    cAvg = cAvg + c;
    return cAvg;
}

void Integrals::input() //ввод координат и количества сегментов
{
    cout << "Enter coordinate 1\n";
    cin >> a;
    cout << "Enter coordinate 2\n";
    cin >> b;
    cout << "Enter the number of segments\n";
    cin >> q;
}

void Integrals::getresult() //вывод результата
{
    cout << "Approximate value: " << cAvg << endl;
}