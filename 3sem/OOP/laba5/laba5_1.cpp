#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <string>
using namespace std;

class Cstr
{
    string one;
    string two;

public:
    Cstr()
    {
        cout << "¬ведите первую строку: ";
        Cstr first = new Cstr &;
        getline(cin, first);
        cout << "¬ведите втору строку: ";
        getline(cin, two)
    }
    Cstr(const Cstr &, Cstr one)
    {
        Cstr three = one;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    return 0;
}