#pragma once
#include <iostream>
using namespace std;

class Integrals
{
public:
    Integrals();
    Integrals(int a2, int b2, int q2);
    Integrals(const Integrals& s);

    int fnum(); //выбор функции
    double methodL(), methodR(), methodM(); //left endpoint method, right endpoint method, midpoint method
    void input(); //ввод координат и количества сегментов
    void getresult(); //вывод результата

private:
    int mnum, q, f;
    double a, b, cAvg = 0;
};