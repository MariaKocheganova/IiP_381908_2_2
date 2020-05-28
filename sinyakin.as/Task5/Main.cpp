#include"TaylorRow.h"
#include<stdlib.h>
#include <cassert>

using namespace std;



void main() 
{
	Taylor f;
	Taylor f1;
	cin >> f;
	f.koeficienti();
	
	f.OnTheScreen();

	getchar();
	getchar();
}