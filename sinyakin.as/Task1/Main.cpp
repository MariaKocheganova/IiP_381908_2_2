#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	CString str1; // конструктор по умолчанию
	CString str2("Нижний Новгород"); // конструктор преобразования типа
	CString str3 (10, '*'); // конструктор инициализатор
	CString str4 (15); // конструктор инициализатор
	CString str5 (str2); // конструктор копирования

	str1.OutPut("str1");
	str2.OutPut("str2");
	str3.OutPut("str3");
	str4.OutPut("str4");
	str5.OutPut("str5");

	return 0;
}