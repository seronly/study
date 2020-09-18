#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cmath>
#include <cstring>
using namespace std;
//(D=>B)||A
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int A, B, checkInt;
    bool checkBool;
    int *result = new int[10];
    string Hline = "------------------------------------------------";
    cout
        << "A\tB\tD\tD=>B\t(D=>B)||A" << endl;
    cout << Hline << endl;

    return 0;
}