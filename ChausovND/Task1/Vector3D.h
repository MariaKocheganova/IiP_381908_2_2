#pragma once
#include<iostream>
using namespace std;

class Vector3D
{
private:
    double x, y, z;
public:
    Vector3D();
    Vector3D(double xx, double yy, double zz = 0);
    Vector3D(const Vector3D& vec);
    Vector3D operator+(const Vector3D& vec); //сложение
    Vector3D operator-(const Vector3D& vec); //вычитание
    Vector3D operator*(double val); //умножение на число
    double operator* (const Vector3D& vec); //скалярное произведение
    Vector3D& operator=(const Vector3D& vec); //присваивание
    bool operator==(const Vector3D& vec); //сравнение
    friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vec);
    friend std::istream& operator>>(std::istream& stream, Vector3D& vec);
    ~Vector3D();
};