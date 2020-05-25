#include <iostream>
#include "Integrals.h"
using namespace std;

int main()
{
    int fnum(), mnum;
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
        In1.methodL();
        break;
    case 2:
        In1.methodR();
        break;
    case 3:
        In1.methodM();
        break;
    default:
        cout << "Wrong number" << endl;
    }
}