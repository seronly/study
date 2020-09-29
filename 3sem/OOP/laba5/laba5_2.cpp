#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
using namespace std;

class Cstr
{
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    return 0;
}