#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Thermometer
{
public:
	Thermometer()
	{
		date.resize(3000);
		for (int i = 0; i < 3000; i++)
		{
			date[i].resize(12);
			for (int j = 0; j < 12; j++)
			{
				date[i][j].resize(31);
				for (int k = 0; k < 31; k++)
					date[i][j][k].resize(24);
			}
		}
		for (int i = 0; i < 3000; i++)
			for (int j = 0; j < 12; j++)
				for (int k = 0; k < 31; k++)
					for (int u = 0; u < 24; u++)
						date[i][j][k][u] = -100;
	}
	~Thermometer()
	{
		date.clear();
	}
	void menu()
	{
		bool flag = 1;
		while (flag)
		{
			cout << "Choose an option:" << endl;
			cout << "1) Show date and time of the first observation" << endl;
			cout << "2) Add an observation" << endl;
			cout << "3) Show an observation (enter date and time)" << endl;
			cout << "4) Show a series of observations (enter date)" << endl;
			cout << "5) Show average temperature..." << endl;
			cout << "6) Save observation history to a file" << endl;
			cout << "7) Read observation history from a file" << endl;
			cout << "8) Exit" << endl;
			int menu;
			cin >> menu;
			switch (menu)
			{
			case 1:
				firstObs();
				break;
			case 2:
				addObs();
				break;
			case 3:
				showObs();
				break;
			case 4:
				showObsSer();
				break;
			case 5:
				showObsAvg();
				break;
			case 6:
				save();
				break;
			case 7:
				read();
				break;
			case 8:
				flag = 0;
				cout << "Exiting...";
				break;
			default:
				cout << "Wrong option number. Enter a number from 1-8:" << endl;
				break;
			}
		}
	}
	void firstObs()
	{
		bool flag = 1;
		for (int i = 0; i < 3000 && flag; i++)
			for (int j = 0; j < 12 && flag; j++)
				for (int k = 0; k < 31 && flag; k++)
					for (int u = 0; u < 24 && flag; u++)
						if (date[i][j][k][u] != -100)
						{
							cout << "First observation on: " << i << " " << j + 1 << " " << k + 1 << " " << u + 1 << " with temperature value at: " << date[i][j][k][u] << endl;
							flag = 0;
						}
	}
	void addObs()
	{
		int year, mon, day, hour, temp;
		cout << "Enter year, month, day, hour and temperature:" << endl;
		cin >> year >> mon >> day >> hour >> temp;
		date[year][mon - 1][day - 1][hour - 1] = temp;
	}
	void	showObs()
	{
		int year, mon, day, hour;
		cout << "Enter year, month, day and hour:" << endl;
		cin >> year >> mon >> day >> hour;
		if (date[year][mon - 1][day - 1][hour - 1] == -100)
			cout << "No observations recorded." << endl;
		else
			cout << "Temperature observed: " << date[year][mon - 1][day - 1][hour - 1] << endl;
	}
	void	showObsSer()
	{
		int year, mon, day;
		cout << "Enter year, month and day:" << endl;
		cin >> year >> mon >> day;
		for (int i = 0; i < 24; i++)
			if (date[year][mon - 1][day - 1][i] != -100)
				cout << "Hour " << i << ": " << date[year][mon - 1][day - 1][i] << endl;
	}
	void showObsAvg()
	{
		int menu;
		cout << "1) Show average temperature of a specific day" << endl;
		cout << "2) Show average temperature of a specific month" << endl;
		cout << "3) Show average day/night temperature of a specific month" << endl;
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			int div = 0, sum = 0, year, mon, day;
			cout << "Enter year, month and day:" << endl;
			cin >> year >> mon >> day;

			for (int i = 0; i < 24; i++)
				if (date[year][mon - 1][day - 1][i] != -100)
				{
					sum += date[year][mon - 1][day - 1][i];
					div++;
				}
			sum /= div;
			cout << "Average temperature: " << sum << endl;;
		}

		case 2:
		{
			int div = 0, sum = 0, mon;
			cout << "Enter month: " << endl;
			cin >> mon;
			for (int i = 0; i < 3000; i++)
				for (int j = 0; j < 31; j++)
					for (int k = 0; k < 24; k++)
						if (date[i][mon - 1][j][k] != -100)
						{
							sum += date[i][mon - 1][j][k];
							div++;
						}
			sum /= div;
			cout << "Average temperature: " << sum << endl;
		}
		case 3:
		{
			int divDay = 0, divNight = 0, sumDay = 0, sumNight = 0, mon;
			cout << "Enter month:" << endl;
			cin >> mon;
			for (int i = 0; i < 3000; i++)
				for (int j = 0; j < 31; j++)
					for (int k = 0; k < 24; k++)
						if (date[i][mon - 1][j][k] != -100)
						{
							if (date[i][mon - 1][j][k] >= 6 && date[i][mon - 1][j][k] < 18)
							{
								sumDay += date[i][mon - 1][j][k];
								divDay++;
							}
							else
							{
								sumNight += date[i][mon - 1][j][k];
								divNight++;
							}
						}
			sumDay /= divDay;
			sumNight /= divNight;
			cout << "Average day temperature: " << sumDay << endl;
			cout << "Average night temperature: " << sumNight << endl;
		}
		}
	}
	void save()
	{
		ofstream out;
		out.open("Output.txt");
		if (out.is_open())
			for (int i = 0; i < 3000; i++)
				for (int j = 0; j < 12; j++)
					for (int k = 0; k < 31; k++)
						for (int u = 0; u < 24; u++)
							if (date[i][j][k][u] != -100)
								out << i << " " << j + 1 << " " << k + 1 << " " << u + 1 << " " << date[i][j][k][u] << endl;
		out.close();
	}
	void read()
	{
		for (int i = 0; i < 3000; i++)
			for (int j = 0; j < 12; j++)
				for (int k = 0; k < 31; k++)
					for (int u = 0; u < 24; u++)
						date[i][j][k][u] = -100;
		string line;
		ifstream in("Output.txt");
		if (in.is_open())
		{
			while (getline(in, line))
			{
				int y = 0, year, mon, day, hour, g;
				bool flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1;
				string str;

				while (line.size() != y)
				{
					if (line[y] != ' ' && flag1)
						str.push_back(line[y]);
					else if (line[y] == ' ' && flag1)
					{
						year = atoi(str.c_str());
						str.clear();
						flag1 = 0;
					}
					else	if (line[y] != ' ' && flag2)
					{
						str.push_back(line[y]);
					}
					else	if (line[y] == ' ' && flag2)
					{
						mon = atoi(str.c_str());
						str.clear();
						flag2 = 0;
					}
					else	if (line[y] != ' ' && flag3)
					{
						str.push_back(line[y]);
					}
					else	if (line[y] == ' ' && flag3)
					{
						day = atoi(str.c_str());
						str.clear();
						flag3 = 0;
					}
					else	if (line[y] != ' ' && flag4)
					{
						str.push_back(line[y]);
					}
					else	if (line[y] == ' ' && flag4)
					{
						hour = atoi(str.c_str());
						str.clear();
						flag4 = 0;
					}
					else	if (line[y] != ' ' && !flag4)
					{
						str.push_back(line[y]);
						if (y + 1 == line.size())
						{
							g = atoi(str.c_str());
							str.clear();
						}
					}
					y++;
				}
				date[year][mon - 1][day - 1][hour - 1] = g;
			}
		}
		in.close();
	}

private:
	vector<vector<vector<vector<int> > > > date;
};

int main() 
{
	Thermometer T;
	T.menu();
	return 0;
}