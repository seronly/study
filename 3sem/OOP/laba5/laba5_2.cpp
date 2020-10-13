#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
using namespace std;

class Calc
{
public:
    float a, b;
    void Plus()
    {
        cout << "a + b = " << (a + b) << endl;
    }
    void DelPr()
    {
        cout << "a /= b = " << (a /= b) << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Calc obj;
    obj.a = 15;
    obj.b = 12;
    obj.Plus();
    obj.DelPr();

    return 0;
}