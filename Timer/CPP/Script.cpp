#include <iostream>
#include <thread>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите количество секунд." << '\n';
	int Initial_Count_Of_Seconds;
	cin >> Initial_Count_Of_Seconds;
	while (Initial_Count_Of_Seconds <= 0)
	{
		cout << "Введите количество секунд." << '\n';
		cin >> Initial_Count_Of_Seconds;
	}
	while (Initial_Count_Of_Seconds != 0)
	{
		system("cls");
		int Count_Of_Hours = 0;
		int Count_Of_Minutes = 0;
		int Operation_Count_Of_Seconds = Initial_Count_Of_Seconds;
		while (Operation_Count_Of_Seconds >= 3600)
		{
			Count_Of_Hours += 1;
			Operation_Count_Of_Seconds -= 3600;
		}
		while (Operation_Count_Of_Seconds >= 60)
		{
			Count_Of_Minutes += 1;
			Operation_Count_Of_Seconds -= 60;
		}
		if (Count_Of_Hours < 10)
		{
			cout << "0" << Count_Of_Hours;
		}
		else
		{
			cout << Count_Of_Hours;
		}
		cout << ":";
		if (Count_Of_Minutes < 10)
		{
			cout << "0" << Count_Of_Minutes;
		}
		else
		{
			cout << Count_Of_Minutes;
		}
		cout << ":";
		if (Operation_Count_Of_Seconds < 10)
		{
			cout << "0" << Operation_Count_Of_Seconds;
		}
		else
		{
			cout << Operation_Count_Of_Seconds;
		}
		Initial_Count_Of_Seconds -= 1;
		this_thread::sleep_for(chrono::seconds(1));
	}
	system("cls");
	cout << "00:00:00" << '\n';
	system("pause");
	return 0;
}