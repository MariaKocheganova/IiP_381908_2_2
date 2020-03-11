#pragma once
#include <iostream>

using namespace std;

class Vector3d {
private:
	int x;
	int y;
	int z;
public:
	
	Vector3d(int X, int Y, int Z);
	~Vector3d();
	int X();
	int Y();
	int Z();
	void operator = (const Vector3d& m);
	Vector3d operator + (const Vector3d& m) const;
	Vector3d operator - (const Vector3d& m) const;
	bool operator == (const Vector3d& m);
	bool operator != (const Vector3d& m);
	int ScalMult (const Vector3d& a);
	Vector3d operator * (int a);
	friend ostream& operator<< (ostream& cout, Vector3d& m);
	friend istream& operator>> (istream& cin, Vector3d& m);
	bool dif(Vector3d& a, Vector3d& b);
};

Vector3d::Vector3d(int X, int Y, int Z) {
	this->x = X;
	this->y = Y;
	this->z = Z;
}

Vector3d::~Vector3d() {
	this->x = NULL;
	this->y = NULL;
	this->z = NULL;
}

void Vector3d::operator = (const Vector3d& m) {
	this->x = m.x;
	this->y = m.y;
	this->z = m.z;
}

Vector3d Vector3d::operator + (const Vector3d& m) const {
	Vector3d N(0, 0, 0);
	N.x = this->x + m.x;
	N.y = this->y + m.y;
	N.z = this->z + m.z;
	return N;
}

Vector3d Vector3d::operator-(const Vector3d& m) const {
	Vector3d N(0, 0, 0);
	N.x = this->x - m.x;
	N.y = this->y - m.y;
	N.z = this->z - m.z;
	return N;
}

int Vector3d::X() {
	return this->x;
}

int Vector3d::Y() {
	return this->y;
}

int Vector3d::Z() {
	return this->z;
}

bool Vector3d::operator == (const Vector3d& m) {
	if (this->x == m.x && this->y == m.y && this->z == m.z) return true;
	else return false;
}

bool Vector3d::operator != (const Vector3d& m) {
	if (this->x == m.x && this->y == m.y && this->z == m.z) return false;
	else return true;
}

ostream& operator<<(ostream& cout, Vector3d& m) {
	std::cout << m.X() << " " << m.Y() << " " << m.Z();
	return cout;
}

istream& operator>>(istream& cin, Vector3d& m) {
	cin >> m.x;
	cin >> m.y;
	cin >> m.z;
	return cin;
}

bool Vector3d::dif(Vector3d& a, Vector3d& b) {
	if (sqrt(a.x * a.x + a.y * a.y + a.z * a.z) > sqrt(b.x * b.x + b.y * b.y + b.z * b.z))
		return true;
	else
		return false;
}

int Vector3d::ScalMult (const Vector3d& a) {
	return (this->x * a.x + this->y * a.y + this->z * a.z);
}

Vector3d Vector3d::operator * (int a) {
	this->x = this->x * a;
	this->y = this->y * a;
	this->z = this->z * a;
	return *this;
}