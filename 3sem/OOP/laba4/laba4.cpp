#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cstring>
using namespace std;

int counter = 100;
//  Пункт назначения, Номер рейса, Тип самолета, Время вылета, Дни недели.
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
    cout << "Введите данные: " << endl;
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
string Airbus::getDP() { return destPoint; }
string Airbus::getWeekday() { return weekday; }
void listDP(Airbus list[], int n)
{
    int i;
    string DP;
    cout << "Введите пункт назначения: ";
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
    cout << "1. Добавление рейса" << endl;
    cout << "2. Сортировка списка сотрудников по фамилии" << endl;
    cout << "3. Поиск сотрудников по фамилии" << endl;
    cout << "4. Изменение данных о сотруднике" << endl;
    cout << "5. Удаление данных о сотруднике" << endl;
    cout << "6. Вывод на экран список сотрудников" << endl;
    cout << "7. Выход" << endl;
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
        cout << "Добавлено максимальное кол-во рейсов!" << endl;
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
    cout << "Введите кол-во рейсов: ";
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