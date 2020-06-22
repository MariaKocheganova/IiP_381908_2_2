#include "Vector3D.h"

Vector3D::Vector3D()
{
    x = 0; y = 0; z = 0;
}

Vector3D::Vector3D(double xx, double yy, double zz)
{
    x = xx; y = yy; z = zz;
}

Vector3D::Vector3D(const Vector3D& vec)
{
    x = vec.x; y = vec.y; z = vec.z;
}

Vector3D Vector3D ::operator+(const Vector3D& vec) //сложение
{
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D ::operator-(const Vector3D& vec) //вычитание
{
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D ::operator*(double val) //умножение на число
{
    return Vector3D(x * val, y * val, z * val);
}

double Vector3D :: operator* (const Vector3D& vec) //скалярное произведение
{
    return x * vec.x + y * vec.y + z * vec.z;
}

Vector3D& Vector3D::operator=(const Vector3D& vec) //присваивание
{
    x = vec.x; y = vec.y; z = vec.z;
    return *this;
}

bool Vector3D ::operator== (const Vector3D& vec) //сравнение
{
    return ((vec.x == x) && (vec.y == y) && (vec.z == z));
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& vec)
{
    stream << "Result: ";
    if ((vec.x != 0) && (vec.y == 0) && (vec.z == 0))
        stream << vec.x << endl << endl;
    else 
        stream << "(" << vec.x << ";" << vec.y << ";" << vec.z << ")" << endl << endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, Vector3D& vec) 
{
    stream >> vec.x >> vec.y >> vec.z;
    return stream;
}

Vector3D::~Vector3D()
{
    x = 0; y = 0; z = 0;
}