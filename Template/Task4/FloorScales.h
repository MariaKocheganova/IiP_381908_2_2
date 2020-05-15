#pragma once
#include <vector>
#include <iostream>

using namespace std;

class FloorScales {
private:
	User users;
	int count;
	//void addNewUser(string _name);

public:
	FloorScales();
	~FloorScales();
};

FloorScales::FloorScales() {
	count = 0;
}

FloorScales::~FloorScales() {

}

//void FloorScales::addNewUser(string _name) {
//	users[count].setName(_name);
//}