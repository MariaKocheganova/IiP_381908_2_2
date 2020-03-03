#include "Classy.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
		setlocale(LC_CTYPE, "Russian");
		Cstring s1; 
		Cstring s3(10, '*'); 
		Cstring s4(15); 
		Cstring s2("Яблоко"); 
		Cstring s5(s2); 
		s3.outPut("s3");
		s4.outPut("s4");
		s2.outPut("s2");
		s5.outPut("s5");
		s3 = s2;
		s3.outPut("s3");
		s2 = " - фрукт";
		s2.outPut("s2");
		s5 = s3 + s2;
		s5.outPut("s5");
		s3 += s2;
		s3 = "Яблоки";
		s3.outPut("s3");
		s3 += " - полезны для здоровья";
		s3.outPut("s3");	
		s1 = "Кря";
		s2 = "второе кря";
		ofstream os; 
		os.open("myfile.txt"); 
		os << s1 << s2 << endl;
		os.close();
		ifstream is; 
		is.open("myfile.txt"); 
		is >> s3;
		is >> s4;
		cout << "s3: " << s3;
		cout << "s4: " << s4;

		s4.outPut("s4"); 
		is.close();
		return 0;
}

