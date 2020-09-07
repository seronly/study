#include <iostream>
#include <locale>
#include <Windows.h>
#include <cassert>
#include <cstring>
using namespace std;

struct timeS
{
    int hour, minute;
};
class Airbus
{
    string destPoint;
    int number;
    string typeAirplane;
    timeS timeOut;
    string weekday;

public:
    Airbus();
    void show();
    string GetDP();
    string GetWeekday();
    timeS GetTime();
};

Airbus::Airbus() //�����������
{
    system("cls");

    cout << "������� ������ ��� �����"
         << "\n-------------------------------------------------------- " << endl;
    cout << "����� ����������: ";
    cin >> destPoint;
    cout << "����� �����: ";
    cin >> number;
    cout << "��� ��������: ";
    cin >> typeAirplane;
    cout << "����� ������\n����: ";
    cin >> timeOut.hour;
    cout << "������: ";
    cin >> timeOut.minute;
    cout << "���� ������: ";
    cin >> weekday;
}

void Airbus::show()
{
    cout << "����� ����������: " << destPoint << endl;
    cout << "����� �����: " << number << endl;
    cout << "��� ��������: " << typeAirplane << endl;
    cout << "����� ������: " << timeOut.hour << ":" << timeOut.minute << endl;
    cout << "���� ������: " << weekday << endl;
}

string Airbus::GetDP() { return destPoint; } // ������

string Airbus::GetWeekday() { return weekday; } //������

timeS Airbus::GetTime() { return timeOut; } //������

void listDP(Airbus list[], int n)
{
    cout << "\nC����� ������ ��� ��������� ������ ����������" << endl;

    int i;
    string DP;
    cout << "������� ����� ����������: ";
    cin >> DP;
    for (i = 0; i < n; i++)
    {
        if (list[i].GetDP() == DP)
        {
            cout << "==============================" << endl;
            list[i].show();
        }
    }
}

void listWD(Airbus list[], int n)
{
    int i;
    string DP;

    cout << "\nC����� ������ ��� ��������� ��� ������" << endl;

    cout << "������� ���� ������: ";
    cin >> DP;
    cout << endl
         << endl;
    for (i = 0; i < n; i++)
    {
        if (list[i].GetWeekday() == DP)
        {
            cout << "==============================" << endl;
            list[i].show();
        }
    }
}

void listTime(Airbus list[], int n)
{
    int i;
    string WD;
    timeS timeMore;

    cout << "\nC����� ������ ��� ��������� ��� ������, ����� ������ ��� ������� ������ ���������." << endl;

    cout << "������� ���� ������: ";
    cin >> WD;
    cout << "������� ����� ������\n����: ";
    cin >> timeMore.hour;
    cout << "������: ";
    cin >> timeMore.minute;
    cout << endl
         << endl;
    for (i = 0; i < n; i++)
    {
        if (list[i].GetWeekday() == WD && (list[i].GetTime().hour > timeMore.hour && list[i].GetTime().minute > timeMore.minute))
        {
            cout << "==============================" << endl;
            list[i].show();
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Airbus *list;
    int n;
    cout << "������� ���-�� ������: ";
    cin >> n;
    list = new Airbus[n];

    for (int i = 0; i < n; i++)
    {
        cout << "==============================" << endl;
        list[i].show();
    }

    listDP(list, n);
    listWD(list, n);
    listTime(list, n);
    delete[] list;

    return 0;
}