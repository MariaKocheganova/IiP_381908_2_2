#pragma once
#include <iostream>

using namespace std;

class Vector {
private:
	int size;
	int* arr;
public:
	Vector();
	Vector(int s);
	~Vector();
	int getSize();
	int* getArr();
	int& operator[] (const int& i);
	friend ostream& operator<< (ostream& out, Vector& m) {
		out << m.size;
		return out;
	}
	//friend istream& operator>>(istream& cin, const Vector& m);
};

Vector::Vector() {
	size = 0;
	arr = NULL;
}

Vector::Vector(int s) {
	size = s;
	arr = new int(size);
}

Vector::~Vector() {
	size = 0;
	delete[] arr;
}

int Vector::getSize() {
	return this->size;
}

int* Vector::getArr() {
	return this->arr;
}

int& Vector::operator[](const int& i) {
	return this->arr[i];
}
