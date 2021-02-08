#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

float z1(float x)
{

    if (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9) == 0)
    {
        throw "Деление на ноль в фукнции z1";
    }
    if (x * x - 9 < 0)
    {
        throw "Корень из отрицательного числа в функции z1";
    }
    return (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));
}

float z2(float x)
{

    if (x - 3 == 0)
    {
        throw "Деление на ноль в функции z2";
    }
    if ((x + 3) / (x - 3) < 0)
    {
        throw "Корень из отрицательного числа в функции z2";
    }
    return sqrt((x + 3) / (x - 3));
}

int main()
{
    setlocale(LC_ALL, "65001");
    system("65001");
    system("cls");

    cout.precision(5);

    float x, result;

    cout << "Введите Х: ";
    cin >> x;

    try
    {
        result = z1(x);
        cout << "Значение функции z1 = " << result << endl;
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }
    try
    {
        result = z2(x);
        cout << "Значение функции z2 = " << result << endl;
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }

    return 0;
}