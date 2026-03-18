#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;
struct Order
{
	string Payers_Checking_Account;
	string Recipients_Checking_Account;
	int Transfer_Amount;
};
void New_Order(Order& New_Order)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите платёжный счёт плательщика." << '\n';
	cin >> New_Order.Payers_Checking_Account;
	cout << "Введите платёжный счёт получателя." << '\n';
	cin >> New_Order.Recipients_Checking_Account;
	cout << "Введите перечисляемую сумму в рублях." << '\n';
	cin >> New_Order.Transfer_Amount;
}
void Creating_New_Order(Order Array_Orders[], int Size, Order New_Order_1)
{
	system("cls");
	for (int Counter = 0; Counter < 8; Counter++)
	{
		New_Order(New_Order_1);
		Array_Orders[Counter] = New_Order_1;
		system("cls");
	}
	system("pause");
	system("cls");
}
void Sorting_Orders(Order Array_Orders[], int Size)
{
	system("cls");
	sort(Array_Orders, Array_Orders + Size, [](const Order& Address_1, const Order& Address_2)
		{
			return Address_1.Payers_Checking_Account < Address_2.Payers_Checking_Account;
		}
	);
	system("pause");
	system("cls");
}
void Printing_Orders(Order Array_Orders[], int Size)
{
	system("cls");
	for (int Counter = 0; Counter < 8; Counter++)
	{
		cout << "Элемент массива № " << Counter + 1 << '\n' << Array_Orders[Counter].Payers_Checking_Account << '\t' << Array_Orders[Counter].Recipients_Checking_Account << '\t' << Array_Orders[Counter].Transfer_Amount << '\n';
	}
	system("pause");
	system("cls");
}
void Search(Order Array_Orders[], int Size)
{
	system("cls");
	string Payer_Checking_Account;
	int Index_Search = -1;
	cout << "Введите платёжный счёт плательщика.";
	cin >> Payer_Checking_Account;
	for (int Counter = 0; Counter < 8; Counter++)
	{
		if (Payer_Checking_Account == Array_Orders[Counter].Payers_Checking_Account)
		{
			Index_Search = Counter;
		}
	}
	system("cls");
	if (Index_Search != -1)
	{
		cout << Array_Orders[Index_Search].Payers_Checking_Account << '\t' << Array_Orders[Index_Search].Recipients_Checking_Account << '\t' << Array_Orders[Index_Search].Transfer_Amount << '\n';
	}
	else
	{
		cout << "Платёжный счёт плательщика не найден.\n";
	}
	system("pause");
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int Size = 8;
	Order Array_Orders[Size];
	Order New_Order_1;
	bool Exit_Switcher = false;
	int Choise = 0;
	while (!Exit_Switcher)
	{
		cout << "1. Создание элементов массива структур.\n2. Сортировка элементов массива структур.\n3. Вывод на экран массива структур.\n4. Поиск информации по платёжному счёту плательщика.\n5. Выход из программы.\n";
		cin >> Choise;
		if (Choise == 1)
		{
			Creating_New_Order(Array_Orders, Size, New_Order_1);
		}
		if (Choise == 2)
		{
			Sorting_Orders(Array_Orders, Size);
		}
		if (Choise == 3)
		{
			Printing_Orders(Array_Orders, Size);
		}
		if (Choise == 4)
		{
			Search(Array_Orders, Size);
		}
		if (Choise == 5)
		{
			Exit_Switcher = true;
		}
	}
	system("pause");
	return 0;
}