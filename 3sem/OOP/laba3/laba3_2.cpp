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

template <class int_type, class date_type>
int_type days_left(T year, T month, T day)
{
    T n = 0;
    return n;
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

    cout << "¬ведите год, мес€ц и день: ";
    cin >> data1.year;
    cin >> data1.month;
    cin >> data1.day;
    cout << "ƒо конца мес€ца осталось: " << days_left(data1.year, data1.month, data1.day) << " дней" << endl;
    cout << "\n¬ведите мес€ц и день: ";
    cin >> data2.month;
    cin >> data2.day;
    cout << "ƒо конца мес€ца осталось: " << days_left(yearNow, data2.month, data2.day) << " дней" << endl;

    return 0;
}