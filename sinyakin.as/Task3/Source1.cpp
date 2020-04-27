#include "Header.h"


Time::Time() // default
{
	for (int i = 0; i < 3; i++)
	{
		DATA[i] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		TimeBegin[i] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		FinalTime[i] = 0;
	}
	steps = 0;
}

Time::Time(int* _data, int* _tSt, int* _tFn, int _steps)  // copy
{
	for (int i = 0; i < 3; i++)
	{
		DATA[i] = _data[i];
	}
	for (int i = 0; i < 2; i++)
	{
		TimeBegin[i] = _tSt[i];
	}
	for (int i = 0; i < 2; i++)
	{
		FinalTime[i] = _tFn[i];
	}
	steps = _steps;
}

Time::~Time() // destruct
{
	for (int i = 0; i < 3; i++)
	{
		DATA[i] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		TimeBegin[i] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		FinalTime[i] = 0;
	}
	steps = 0;
}

Pedometer::Pedometer() // default 
{
	time = new Time();
}

Pedometer::Pedometer(int* DATA, int* BeginTime, int* FinalTime, int steps) //copy
{
	Time time(int* DATA, int* BeginTime, int* FinalTime, int steps);
}

Pedometer::~Pedometer() //destruct
{
	time-> ~Time();
}

//std::ostream& operator<<(std::ostream& stream, const Pedometer& s) 
//{
//
//}

//std::istream& operator>>(std::istream& stream, Time& s) {
//
//	Time* time = new Time();
//
//	cout << "ENTER ONE BY ONE - Year , Month , Day : ";
//	cin >> s.DATA[0] >> s.DATA[1] >> s.DATA[2];
//	cout << "Enter Hour and your Start Minute : ";
//	cin >> s.TimeBegin[0] >> s.TimeBegin[1];
//	cout << "Enter Hour and your Finish Minute : ";
//	cin >> s.FinalTime[0] >> s.FinalTime[1];
//	cout << "Number of Steps : ";
//	cin >> s.steps;
//
//	string path = "expect.txt";
//
//	ofstream fout;
//	fout.open(path, ofstream::app);
//
//	if (!fout.is_open()) {
//		cout << "Error!" << endl;
//	}
//	else {
//		cout << "File open.." << endl;
//		fout.write((char*)& time, sizeof(Time));
//	}
//
//	fout.close();
//}