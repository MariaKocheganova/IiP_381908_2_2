#include "Header.h"
#include <iostream>


using namespace std;

int main()
{

	CString str1; // конструктор по умолчанию
	CString str2("Nizhny Novgorod"); // конструктор преобразования типа
	CString str3 (10, '*'); // конструктор инициализатор
	CString str4 (15); // конструктор инициализатор
	CString str5 (str2); // конструктор копирования

	str1.OutPut("str1");
	str2.OutPut("str2");
	str3.OutPut("str3");
	str4.OutPut("str4");
	str5.OutPut("str5");


	str3 = str2;
	str3.OutPut("str3");
	str2 = " - is a russian city";
	str2.OutPut("str2");
	str5 = str3 + str2;
	str5.OutPut("str5");
	str3 += str2;
	str3 = "Nizhny Novgorod";
	str3.OutPut("str3");
	str3 += " - it's the greatest city!";
	s3.outPut("s3");

	return 0;
}