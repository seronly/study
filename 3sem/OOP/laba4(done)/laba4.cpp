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
class Aeroflot
{
    string destPoint;
    int number;
    string typeAirplane;
    timeS timeOut;
    string weekday;

public:
    Aeroflot();
    void show();
    string GetDP();
    string GetWeekday();
    timeS GetTime();
};

Aeroflot::Aeroflot() //конструктор
{
    system("cls");

    cout << "Введите данные для рейса"
         << "\n-------------------------------------------------------- " << endl;
    cout << "Пункт назначения: ";
    cin >> destPoint;
    cout << "Номер рейса: ";
    cin >> number;
    cout << "Тип самолета: ";
    cin >> typeAirplane;
    cout << "Время вылета\nЧасы: ";
    cin >> timeOut.hour;
    cout << "Минуты: ";
    cin >> timeOut.minute;
    cout << "День недели: ";
    cin >> weekday;
}

void Aeroflot::show()
{
    cout << "Пункт назначения: " << destPoint << endl;
    cout << "Номер рейса: " << number << endl;
    cout << "Тип самолета: " << typeAirplane << endl;
    cout << "Время вылета: " << timeOut.hour << ":" << timeOut.minute << endl;
    cout << "День недели: " << weekday << endl;
}

string Aeroflot::GetDP() { return destPoint; } // геттер

string Aeroflot::GetWeekday() { return weekday; } //геттер

timeS Aeroflot::GetTime() { return timeOut; } //геттер

void listDP(Aeroflot list[], int n)
{
    cout << "\nCписок рейсов для заданного пункта назначения" << endl;

    int i;
    string DP;
    cout << "Введите пункт назначения: ";
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

void listWD(Aeroflot list[], int n)
{
    int i;
    string DP;

    cout << "\nCписок рейсов для заданного дня недели" << endl;

    cout << "Введите день недели: ";
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

void listTime(Aeroflot list[], int n)
{
    int i;
    string WD;
    timeS timeMore;

    cout << "\nCписок рейсов для заданного дня недели, время вылета для которых больше заданного." << endl;

    cout << "Введите день недели: ";
    cin >> WD;
    cout << "Введите время вылета\nЧасы: ";
    cin >> timeMore.hour;
    cout << "Минуты: ";
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

    Aeroflot *list;
    int n;
    cout << "Введите кол-во рейсов: ";
    cin >> n;
    list = new Aeroflot[n];

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