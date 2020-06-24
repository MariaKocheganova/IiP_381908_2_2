#pragma once
#include <iostream>
using namespace std;


class Integrals
{
public:
    Integrals();
    Integrals(int a2, int b2, int q2);
    Integrals(const Integrals& s);

    int fnum();
    double methodL(), methodR(), methodM();
    void input();
    void getresult();

private:
    int mnum, q, f;
    double a, b, cAvg = 0;
};