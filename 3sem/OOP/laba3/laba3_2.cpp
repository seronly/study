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

template <class T>
T days_left(T year, T month, T day)
{
    int n = 0;
    // определение количества дней
    switch (month)
    {
    case 1:
        n = 31;
        break;
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
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
    date data;
    int year, month, day;

    cout << "Перегрузка функции для структуры: \nВведите год: ";
    cin >> data.year;
    cout << "Месяц: ";
    cin >> data.month;
    cout << "День: ";
    cin >> data.day;
    cout << "До конца месяца осталось: " << days_left(data.year, data.month, data.day) << " дней\n"
         << endl;

    cout << "Перегрузка функции с 3 параметрами: \nВведите год: ";
    cin >> year;
    cout << "Месяц: ";
    cin >> month;
    cout << "День: ";
    cin >> day;
    cout << "До конца месяца осталось: " << days_left(year, month, day) << " дней\n"
         << endl;

    return 0;
}
