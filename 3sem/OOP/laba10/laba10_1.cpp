#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

void show(double *a, double *b, double *c, int *size)
{
    cout.setf(ios::fixed);
    for (int i = 0; true; i++)
    {
        try
        {
            if (size[0] - 1 < i || size[1] - 1 < i || size[2] - 1 < i)
            {
                throw "Выход за пределы индексов";
            }
            cout << setprecision(2) << left << setw(10) << a[i] << "|" << setw(10) << b[i] << setw(5) << "|" << c[i] << endl;
        }
        catch (const char *ex)
        {
            cout << ex << endl;
            break;
        }
    }
}

double f_a(float x)
{
    try
    {
        if (x < 0 || x > 4.01)
        {
            throw "Выход за пределы границ";
        }
        if (x * x - 1 <= 0)
        {
            throw "Основание меньше или равно 0";
        }
        else
        {
            return log(x * x - 1);
        }
    }
    catch (const char *e)
    {
        cerr << e << '\n';
        return 0;
    }
}

double f_c(double *a, double *b, int i, int *n)
{

    try
    {
        if (b[i] == 0)
            throw "Zero Divide";
        if (n[0] < i || n[1] < i)
            throw 0;
        return a[i] - (1 / b[i]);
    }
    catch (int ex)
    {
        return ex;
    }
    catch (const char *excep)
    {
        cout << excep << endl;
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    system("clear");
    srand(time(NULL));

    int i, size;

    int *n = new int[3];
    n[0] = 25;
    n[1] = 25;
    n[2] = 25;

    double *a = new double[n[0]];
    double *b = new double[n[1]];
    double *c = new double[n[2]];

    float x = 0.0;

    for (i = 0; i < n[0]; i++)
    {
        a[i] = f_a(x);
        x += 0.2;
    }
    for (i = 0; i < n[1]; i++)
    {
        b[i] = rand() % 20 + (-10);
    }

    for (i = 0; i < n[2]; i++)
    {
        c[i] = f_c(a, b, i, n);
    }

    show(a, b, c, n);
    return 0;
}