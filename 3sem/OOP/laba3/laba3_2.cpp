#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <Windows.h>
#include <locale>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

struct date
{
    int year, month, day;
};

template <class T>
T days_left(T year, T month, T day)
{
    return n;
}
// T days_left(T year, T month, T day)
// {
//     return n;
// }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    date data1, data2;

    cout << "������� ���, ����� � ����: ";
    cin >> data1.year;
    cin >> data1.month;
    cin >> data1.day;
    cout << "�� ����� ������ ��������: " << days_left(data1.year, data1.month, data1.day) << " ����" << endl;
    cout << "\n������� ����� � ����: ";
    cin >> data2.month;
    cin >> data2.day;
    cout << "�� ����� ������ ��������: " << days_left(2020, data2.month, data2.day) << " ����" << endl;

    return 0;
}