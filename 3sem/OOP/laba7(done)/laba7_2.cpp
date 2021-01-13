#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
using namespace std;

class TransportCompany
{
protected:
    double speed, price, distance;
    string type, city1, city2;

public:
    TransportCompany()
    {
        speed = price = 0;
        type = "";
    }
    virtual void Write()
    {
        cout << "=======================" << endl;
        cout << type << endl;
        cout << "Скорость " << speed << " км/ч" << endl;
        cout << "Плата " << price << " руб/ч" << endl;
    }
    float Time()
    {
        float time = distance / speed;
        return int(time * 100 + 0.5) / 100.0;
    }
    float Cost()
    {
        return Time() * price;
    };

    virtual void CheckCount()
    {
        cout << "=======================" << endl;
        cout << type << endl;
        cout << "Скорость " << speed << " км/ч" << endl;
        cout << "Плата " << price << " руб/ч" << endl;
        cout << "Из города " << city1 << " в город " << city2 << endl;
        cout << "Путь " << distance << " км." << endl;
        cout << "Займёт времени " << Time() << " ч." << endl;
        cout << "Стоимость " << Cost() << " руб." << endl;
    }
};

class Airplane : public TransportCompany
{

public:
    Airplane()
    {
        speed = 800.00;
        price = 2800;
        type = "Airplane";
    }
    Airplane(string c1, string c2, double d)
    {
        speed = 800.00;
        price = 2800;
        type = "Airplane";
        city1 = c1;
        city2 = c2;
        distance = d;
    }
};

class Train : public TransportCompany
{
public:
    Train()
    {
        speed = 220.00;
        price = 1700;
        type = "Train";
    }
    Train(string c1, string c2, double d)
    {
        speed = 220.00;
        price = 1700;
        type = "Train";
        city1 = c1;
        city2 = c2;
        distance = d;
    }
};

class Car : public TransportCompany
{
public:
    Car()
    {
        speed = 80.00;
        price = 960;
        type = "Car";
    }
    Car(string c1, string c2, double d)
    {
        speed = 80.00;
        price = 960;
        type = "Car";
        city1 = c1;
        city2 = c2;
        distance = d;
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    TransportCompany *arr[3]{
        arr[0] = new Airplane("Москва", "Париж", 2487),
        arr[1] = new Train("Москва", "Париж", 2509),
        arr[2] = new Car("Москва", "Париж", 2827)};
    for (int i = 0; i < 3; i++)
    {
        arr[i]->CheckCount();
        cout << endl;
    }

    return 0;
}