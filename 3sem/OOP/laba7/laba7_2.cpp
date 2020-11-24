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
public:
};

class Train : public TransportCompany
{
};

class Car : public TransportCompany
{
};

int main()
{
    setlocale(LC_ALL, "65001");

    return 0;
}