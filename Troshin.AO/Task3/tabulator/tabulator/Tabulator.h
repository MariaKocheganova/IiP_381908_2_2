
#include <iostream> 
#include<cmath> 
using namespace std;
class Tabulator {
private:
	float a, b, *p, *f;
	int n;
public:


	Tabulator() {
		a = b = 0; n = 0;
	}
	void interval(float a1, float b1) {
		a = a1;
		b = b1;
	}
	void num(int a1) {
		n = a1;
	}
	void interval1(float& b1, float& a1) {
		a1 = a; b1 = b;
	}
	int num1() {
		return n;
	}
	void tab() {
		p = new float[n];
		f = new float[n];
		float h;
		h = (b - a) / (n - 1);

		for (int i = 0; i < n; i++)
		{
			p[i] = a + h * i;
			f[i] = funk(p[i]);
			cout «" Òàáóëèðîâàíèå "« f[i]«endl;
		}

	}
	float funk(float x) {

		return sin(x);
	}
};