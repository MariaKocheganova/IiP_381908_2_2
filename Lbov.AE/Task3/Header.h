#include <iostream>
#include<cmath>
using namespace std;
class Tabulator {
private:
	
	
public:
	int a, b, n;
	float* p;
	Tabulator() {
		a = b = n = 0;
	
	}
	void interval(int a1, int b1) {
		a = a1;
		b = b1;
		cout << endl;
	}
	void num(int a1) {
		n = a1;
		cout << endl;
	}
	void interval1() {
		cout << a << " " << b<<endl;
	}
	void num1() {
		cout << n<<endl;
	}
	void tab() {
		p = new float[n];
		float h;
		h = 0;
		for (int i = 0; i < n; i++)
		{
			p[i] = a + h;
			h = (b - a) / (n - 1);
			cout <<" Табуирование "<< p[i]<<endl;
			a++;
		}

	}
};