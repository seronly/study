#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cstring>
using namespace std;

int counter = 100;
//  ����� ����������, ����� �����, ��� ��������, ����� ������, ��� ������.
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
    int menu();
    Airbus();
    void show();
    string getDP();
    string getWeekday();
};
Airbus::Airbus()
{
    cout << "������� ������: " << endl;
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
string Airbus::getDP() { return destPoint; }
string Airbus::getWeekday() { return weekday; }
void listDP(Airbus list[], int n)
{
    int i;
    string DP;
    cout << "������� ����� ����������: ";
    cin >> DP;
    for (i = 0; i < n; i++)
    {
        if (list[i].getDP() == DP)
        {
            list[i].show();
        }
    }
}
int Airbus::menu()
{
    system("cls");
    int enter;
    cout << "1. ���������� �����" << endl;
    cout << "2. ���������� ������ ����������� �� �������" << endl;
    cout << "3. ����� ����������� �� �������" << endl;
    cout << "4. ��������� ������ � ����������" << endl;
    cout << "5. �������� ������ � ����������" << endl;
    cout << "6. ����� �� ����� ������ �����������" << endl;
    cout << "7. �����" << endl;
    cin >> enter;
    return enter;
}

void input()
{
    system("cls");
    if (counter < 100)
    {
    }
    else
        cout << "��������� ������������ ���-�� ������!" << endl;
    system("pause");
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Airbus *list;
    int n;
    string DP;
    cout << "������� ���-�� ������: ";
    cin >> n;
    list = new Airbus[n];

    for (int i = 0; i < n; i++)
    {
        cout << "==============================" << endl;
        list[i].show();
    }

    listDP(list, n);

    return 0;
}