#include"Fun.h"
using namespace std;
LongLong::LongLong()// Конструктор по умолчанию
{
	cel = 0; ost = 0;
}
LongLong::LongLong(const LongLong &c)// Конструктор копирования
{
	ost = c.ost; cel = c.cel;
}
LongLong::LongLong(int _cel, unsigned int _ost)// Конструктор инициализации
{
	cel = _cel; ost = _ost;
}
LongLong::LongLong(int _ost)// Конструктор преобразования типа
{
	ost = _ost;
}
LongLong::~LongLong()// Деструктор
{
	cel = 0; ost = 0;
}
bool LongLong::operator == (const LongLong& c)
{
	if (ost == c.ost && cel == c.cel)
	{
		return true;
	}
	else
	{
		return false;
	}
}
