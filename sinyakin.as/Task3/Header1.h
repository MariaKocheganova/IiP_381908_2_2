#pragma once
#include <clocale>
#include <iostream>
#include <fstream>


using namespace std;

class Time
{
private:
	int DATA[3];
	int steps;
	int TimeBegin[2];
	int FinalTime[2];
public:
	Time();
	Time(int* _DATA, int* _TIMEBEGIN, int* _FINALTIME, int _steps);
	~Time();

	friend ostream& operator<<(std::ostream& stream, const Time& s);
	friend istream& operator>>(std::istream& stream, Time& s);

	void info();
};

class Pedometer {
private:
	Time* time;

public:
	Pedometer();
	Pedometer(int* DATA, int* TimeBegin, int* FinalTime, int steps);
	~Pedometer();

	friend ostream& operator<<(std::ostream& stream, const Pedometer& s);
	friend istream& operator>>(std::istream& stream, Pedometer& s);

	void getStartTime();
	void getStartData();
	void getData();
	void startInfo();
	void addCount();
	void getInfoEpisode();
	void middleMounth();
	void middleAll();
	void maxStepDay();
	void maxStepAll();

};