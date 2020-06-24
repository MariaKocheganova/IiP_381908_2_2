#include <iostream>
#include "Integrals.h"
using namespace std;

int main()
{
    int mnum;
    Integrals In1;
    In1.input(); cout << endl;

    cout << "Choose a method: \n";
    cout << "1) Left endpoint method" << endl;
    cout << "2) Right endpoint method" << endl;
    cout << "3) Midpoint method" << endl;
    cin >> mnum;

    switch (mnum)
    {
    case 1:
        In1.fnum();
        In1.methodL();
        In1.getresult();
        break;
    case 2:
        In1.fnum();
        In1.methodR();
        In1.getresult();
        break;
    case 3:
        In1.fnum();
        In1.methodM();
        In1.getresult();
        break;
    default:
        cout << "Wrong number" << endl;
        break;
    }
}