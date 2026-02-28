#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    const int Size = 10;
    int Main_Ray[Size][Size];
    cout << "Начальный двухмерный массив" << '\n';
	for (int Counter_1 = 0; Counter_1 < Size; Counter_1++)
	{
	    for (int Counter_2 = 0; Counter_2 < Size; Counter_2++)
	    {
	        Main_Ray[Counter_1][Counter_2] = 1 + rand() % 199;
	        cout << Main_Ray[Counter_1][Counter_2] << '\t';
	    }
	    cout << '\n';
	}
	cout << "Отсортированный двухмерный массив" << '\n';
	for (int Counter_1 = 0; Counter_1 < Size * Size; Counter_1++)
	{
	    int Minimal_Value_Of_Element_Of_Ray = 200;
	    int Sorted_Element_Of_Ray;
	    int Index_Sort_1;
	    int Index_Sort_2;
	    int Now_Counter_1 = 0;
	    int Now_Counter_2 = Counter_1 % 10;
	    int Counter_0 = Counter_1;
	    while (Counter_0 > 9)
	    {
	        Counter_0 -= 10;
	        Now_Counter_1 += 1;
	    }
	    for (int Counter_2 = Now_Counter_1; Counter_2 < Size; Counter_2++)
	    {
	        if (Counter_2 == Now_Counter_1)
	        {
	            for (int Counter_3 = Now_Counter_2; Counter_3 < Size; Counter_3++)
	            {
	                if (Main_Ray[Counter_2][Counter_3] < Minimal_Value_Of_Element_Of_Ray)
	                {
	                    Index_Sort_1 = Counter_2;
	                    Index_Sort_2 = Counter_3;
	                    Minimal_Value_Of_Element_Of_Ray = Main_Ray[Counter_2][Counter_3];
	                    Sorted_Element_Of_Ray = Main_Ray[Counter_2][Counter_3];
	                }
	            }
	        }
	        else
	        {
	            for (int Counter_3 = 0; Counter_3 < Size; Counter_3++)
	            {
	                if (Main_Ray[Counter_2][Counter_3] < Minimal_Value_Of_Element_Of_Ray)
	                {
	                    Index_Sort_1 = Counter_2;
	                    Index_Sort_2 = Counter_3;
	                    Minimal_Value_Of_Element_Of_Ray = Main_Ray[Counter_2][Counter_3];
	                    Sorted_Element_Of_Ray = Main_Ray[Counter_2][Counter_3];
	                }
	            }
	        }
	    }
	    Main_Ray[Index_Sort_1][Index_Sort_2] = Main_Ray[Now_Counter_1][Now_Counter_2];
	    Main_Ray[Now_Counter_1][Now_Counter_2] = Sorted_Element_Of_Ray;
	}
	for (int Counter_1 = 0; Counter_1 < Size; Counter_1++)
	{
	    for (int Counter_2 = 0; Counter_2 < Size; Counter_2++)
	    {
	        cout << Main_Ray[Counter_1][Counter_2] << '\t';
	    }
	    cout << '\n';
	}
	return 0;
}
