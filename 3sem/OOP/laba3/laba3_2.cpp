#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <Windows.h>
#include <locale>
#include <string>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

struct date
{
    int year, month, day;
};

template <class int_type>
int_type days_left(int_type year, int_type month, int_type day)
{
    int n = 0;
    switch (month)
    {
    case 1:
        n = 31;
        break;
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // високосный год или нет
            n = 29;
        else
            n = 28;
        break;
    case 3:
        n = 31;
        break;
    case 4:
        n = 30;
        break;
    case 5:
        n = 31;
        break;
    case 6:
        n = 30;
        break;
    case 7:
        n = 31;
        break;
    case 8:
        n = 31;
        break;
    case 9:
        n = 30;
        break;
    case 10:
        n = 31;
        break;
    case 11:
        n = 30;
        break;
    case 12:
        n = 31;
        break;
    default:
        break;
    }

    return (n - day);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    date data1, data2;

    time_t t;
    struct tm *timeN;
    time(&t);
    timeN = localtime(&t);
    int yearNow = timeN->tm_year + 1900;

    cout << "¬ведите день: ";
    cin >> data1.day;
    cout << "ћес€ц: ";
    cin >> data1.month;
    cout << "√од: ";
    cin >> data1.year;

    cout << "ƒо конца мес€ца осталось: " << days_left(data1.year, data1.month, data1.day) << " дней" << endl;
    cout << "\n¬ведите день: ";
    cin >> data2.day;
    cout << "ћес€ц: ";
    cin >> data2.month;
    cout << "ƒо конца мес€ца осталось: " << days_left(yearNow, data2.month, data2.day) << " дней" << endl;

    return 0;
}
