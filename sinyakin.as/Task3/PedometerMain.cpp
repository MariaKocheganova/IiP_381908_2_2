#include "PedometerHeader.h"

using namespace std;

int main()
{
	int* h_s = new int[2];
	h_s[0] = 0;
	h_s[1] = 0;
	int* h_e = new int[2];
	h_e[0] = 0;
	h_e[1] = 0;
	int* data = new int[3];
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	int st = 0;
	Date d(h_s, h_e, data, st);
	Date d1;

}