#include "ProcCenter.h"
#include "Depozit.h"



int main()
{
	setlocale(LC_ALL, "Rus");
	ProcCenter c1("Name", "Middle", "Last", "1234", 700000, 1234);
	ProcCenterVec c2(c1);
	Depozit A;
	A.Start(c2);


}