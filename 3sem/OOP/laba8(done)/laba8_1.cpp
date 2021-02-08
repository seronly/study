#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Train
{
protected:
    string type;
    long weight;
    int number;

public:
    Train()
    {
        type = "";
        weight = 0;
        number = 0;
    }
    Train(int w, int n)
    {
        weight = w;
        number = n;
    }
    virtual void show()
    {
        cout << "------------------------" << endl
             << type << endl
             << "Вес: " << weight << endl
             << "Кол-во единиц товара: " << number << endl
             << "------------------------" << endl;
    }
};

class CarTrain : public Train
{
public:
    CarTrain() : Train()
    {
        type = "Вагон для перевозки автомобилей";
        weight = 3000000;
        number = 0;
    }
    CarTrain(long w, int n) : Train(w, n)
    {
        type = "Вагон для перевозки автомобилей";
    }
    void show() override
    {
        cout << "------------------------" << endl
             << type << endl
             << "Вес с автомобилями: " << weight << endl
             << "Кол-во автомобилей: " << number << endl
             << "------------------------" << endl;
    }
};

class TankerTrain : public Train
{
public:
    TankerTrain() : Train()
    {
        type = "Вагон - цистерна";
        weight = 800000;
        number = 0;
    }
    TankerTrain(long w, int n) : Train(w, n)
    {
        type = "Вагон - цистерна";
    }
    void show() override
    {
        cout << "------------------------" << endl
             << type << endl
             << "Вес с содержимым: " << weight << endl
             << "Объем: " << number << " л." << endl
             << "------------------------" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    Train *n1 = new CarTrain(5000000, 3);
    Train *n2 = new TankerTrain(2500000, 12);
    n1->show();
    n2->show();

    return 0;
}