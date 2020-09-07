#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cstring>
using namespace std;

//  Пункт назначения, Номер рейса, Тип самолета, Время вылета, Дни недели.

// Aeroflot: Пункт назначения, Номер рейса, Тип самолета, Время вылета, Дни недели. Создать массив объектов. Вывести:
// а) список рейсов для заданного пункта назначения; +
// б) список рейсов для заданного дня недели;
// в) список рейсов для заданного дня недели, время вылета для которых больше заданного.

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

Airbus::Airbus() //конструктор
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

void Airbus::show()
{
    cout << "Пункт назначения: " << destPoint << endl;
    cout << "Номер рейса: " << number << endl;
    cout << "Тип самолета: " << typeAirplane << endl;
    cout << "Время вылета: " << timeOut.hour << ":" << timeOut.minute << endl;
    cout << "День недели: " << weekday << endl;
}

string Airbus::GetDP() { return destPoint; } // геттер

string Airbus::GetWeekday() { return weekday; } //геттер

timeS Airbus::GetTime() { return timeOut; } //геттер

void listDP(Airbus list[], int n)
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

void listWD(Airbus list[], int n)
{
    int i;
    string DP;

    cout << "\nCписок рейсов для заданного дня недели" << endl;

    cout << "Введите день недели: ";
    cin >> DP;

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
    string DP;
    timeS timeMore;

    cout << "\nCписок рейсов для заданного дня недели, время вылета для которых больше заданного." << endl;

    cout << "Введите день недели: ";
    cin >> DP;
    cout << "Введите время вылета\nЧасы: ";
    cin >> timeMore.hour;
    cout << "Минуты: ";
    cin >> timeMore.minute;
    for (i = 0; i < n; i++)
    {
        if (list[i].GetWeekday() == DP)
        {
            cout << "==============================" << endl;
            list[i].show();
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Airbus *list;
    int n;
    string DP;
    cout << "Введите кол-во рейсов: ";
    cin >> n;
    list = new Airbus[n];

    for (int i = 0; i < n; i++)
    {
        cout << "==============================" << endl;
        list[i].show();
    }

    listDP(list, n);
    listWD(list, n);

    return 0;
}