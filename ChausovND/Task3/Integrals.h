#pragma once
#include <iostream>
using namespace std;

int fnum();

class Integrals
{
public:
    Integrals();
    Integrals(int a2, int b2, int q2);
    Integrals(const Integrals& s);

    double methodL(), methodR(), methodM();
    void input();

private:
    int a, b, q;
};