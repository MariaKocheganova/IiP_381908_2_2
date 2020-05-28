#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Vector {
private:
	
	int* v;
	int  n;
public:
	int x, x1,n1,sum,sum1,ymn,y,y1;
	Vector(){
		
		n= x = x1 =y=y1= 0;
	}
	
	friend istream& operator>>(istream& is, Vector& s);
	friend ostream& operator<<(std::ostream& out,  Vector& s);
	int& operator[](const unsigned int index);
	  friend Vector operator+( Vector &vec, const Vector&vec1);
	  friend Vector operator*( Vector& vec, const Vector& vec1);
	  friend Vector operator*=(Vector& vec, const Vector& vec1);
	  Vector& Vector::operator=(Vector& vec);
	 void dl(int num1){
		  x = num1;
		  cout << " Длина вектора равна " << abs(sqrt(pow(v[x * 4]-v[x*4-2],2)+pow(v[x * 4-1] - v[x * 4 - 3],2)));
	  }
	   void setOp(int num1, int num2) {
		  x = num1;
		  x1 = num2;
	  }
};
