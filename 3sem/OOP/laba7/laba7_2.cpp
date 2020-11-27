#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
using namespace std;

class TransportCompany
{
};

class Airplane : public TransportCompany
{
private:
    const double speed = 800.00;
    const double price = 2.6;
    const string type = "Airplane";

public:
    double getSpeed() { return this->speed; };
    double getPrice() { return this->price; };
    string getType() { return this->type; };
};

class Train : public TransportCompany
{
private:
    const double speed = 800.00;
    const double price = 2.2;
    const string type = "Train";

public:
    double getSpeed() { return this->speed; };
    double getPrice() { return this->price; };
    string getType() { return this->type; };
};

class Car : public TransportCompany
{
private:
    const double speed = 80.00;
    const double price = 1.6;
    const string type = "Car";

public:
    double getSpeed() { return this->speed; };
    double getPrice() { return this->price; };
    string getType() { return this->type; };
};

int main()
{
    setlocale(LC_ALL, "65001");

    return 0;
}