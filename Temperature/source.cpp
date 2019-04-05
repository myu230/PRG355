#include <iostream>
#include <iomanip>

using namespace std;

class Weather
{
private:
	int day;
	int month;
	float temperature;
	static float totalTemp;

public:
	Weather();
	Weather(int dummy)
	{}
	static void displayTemp(Weather wData[], int size);
	static void avgTemp(int size);
};

float Weather::totalTemp = 0;

Weather::Weather()
{
	cout << "Enter day, month, temperature ==> ";
	cin >> day >> month >> temperature;

	totalTemp += temperature;
}

void Weather::displayTemp(Weather wData[], int size)
{
	Weather highest(1);
	Weather lowest(1);
	
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			highest = wData[i];
			lowest = wData[i];
		}
		else if (wData[i].temperature > highest.temperature)
		{
			highest = wData[i];
		}
		else if (wData[i].temperature < lowest.temperature)
		{
			lowest = wData[i];
		}
	}

	cout << endl << "Highest temperature = " << highest.temperature << ", Day: ";
	cout << highest.day << "/" << highest.month;
	cout << endl << "Lowest temperature = " << lowest.temperature << ", Day: ";
	cout << lowest.day << "/" << lowest.month;
}

void Weather::avgTemp(int size)
{
	float avgTemp = totalTemp / size;
	
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << endl << "Average temperature = " << avgTemp << endl << endl;
}


int main(void)
{
	int size;

	cout << "How many days? ==>  ";
	cin >> size;
	cout << endl;

	Weather *wData= new Weather[size];

	if (wData == 0)
	{
		cout << "Memory Error";
		exit(1);
	}

	Weather::displayTemp(wData, size);
	Weather::avgTemp(size);

	system("pause");

	delete[] wData;

	return(0);
}
