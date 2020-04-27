
#include "Header.h"

using namespace std;

int main()
{
	Pedometer summary;
	int menu;
	bool end = 1;

	int DATA[3];
	int steps;
	int BeginTime[2];
	int FinalTime[2];


	cout << "ENTER ONE BY ONE - Year , Month , Day : ";
	cin >> DATA[0] >> DATA[1] >> DATA[2];
	cout << "Enter Hour and your Start Minute : ";
	cin >> BeginTime[0] >> BeginTime[1];
	cout << "Enter Hour and your Finish Minute : ";
	cin >> FinalTime[0] >> FinalTime[1];
	cout << "Number of Steps : ";
	cin >> steps;

	while (end)
	{

		cout << endl;
		cout << "Your Current Data and Time is:" << endl << DATA[0] << "." << DATA[1] << "." << DATA[2] << endl << BeginTime[0] << "." << BeginTime[1] << endl << FinalTime[0] << "." << FinalTime[1];
		cout << endl;
		cout << "What do you want?" << endl;
		cout << "1 - To knew about the Start Data and the Time Count" << endl;
		cout << "2 - Add Count" << endl;
		cout << "3 - Info Count, choosed by Data and Time Interval" << endl;
		cout << "4 - Middle Number of steps in a choosed Month or the entire Time history " << endl;
		cout << "5 - Max Number of steps by Day in a choosed Month or the entire Time history " << endl;
		cout << "6 - To Save Count History in File and Read Count History from File " << endl;
		cin >> menu;
		switch (menu)
		{
		case 0:
			end = 0;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;

		}

		return 0;
	}
}