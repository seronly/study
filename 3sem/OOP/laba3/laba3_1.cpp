#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
#include <locale>
#include <string>
#include <ctime>
using namespace std;

struct date
{
    int year, month, day;
};

int days_left(date data)
{
    int n = 0;
    switch (data.month)
    {
    case 1:
        n = 31;
        break;
    case 2:
        if (data.year % 4 == 0 && data.year % 100 != 0 || data.year % 400 == 0) // ���������� ��� ��� ���
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

    return (n - data.day);
}

int days_left(int year, int month, int day)
{
    int n = 0;
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

int days_left(int month, int day)
{
    time_t t;
    struct tm *timeN;
    time(&t);
    timeN = localtime(&t);
    int yearNow = timeN->tm_year + 1900;

    int n = 0;
    switch (month)
    {
    case 1:
        n = 31;
        break;
    case 2:
        if (yearNow % 4 == 0 && yearNow % 100 != 0 || yearNow % 400 == 0)
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

    cout << "���������� ������� ��� ���������: \n������� ���: ";
    cin >> data.year;
    cout << "�����: ";
    cin >> data.month;
    cout << "����: ";
    cin >> data.day;
    cout << "�� ����� ������ ��������: " << days_left(data) << " ����\n"
         << endl;

    cout << "���������� ������� � 3 �����������: \n������� ���: ";
    cin >> year;
    cout << "�����: ";
    cin >> month;
    cout << "����: ";
    cin >> day;
    cout << "�� ����� ������ ��������: " << days_left(year, month, day) << " ����\n"
         << endl;

    cout << "���������� ������� � 2 �����������: \n������� �����: ";
    cin >> month;
    cout << "����: ";
    cin >> day;
    cout << "�� ����� ������ ��������: " << days_left(month, day) << " ����" << endl;

    return 0;
}