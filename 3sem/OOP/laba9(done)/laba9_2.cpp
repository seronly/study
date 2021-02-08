#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

template <typename T>
class Vector
{
    int n;
    T *arr;

public:
    Vector()
    {
        n = 1;
        arr = new T[n];
    }
    Vector(int sizeN)
    {
        n = sizeN;
        arr = new T[n];
    }
    void SetVector()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Введите " << i << "-й элемент вектора: ";
            cin >> arr[i];
        }
    }
    T CountABS()
    {
        T Vabs = 0;
        for (int i = 0; i < n; i++)
        {
            Vabs += arr[i] * arr[i];
        }
        return sqrt(Vabs);
    }
    Vector operator=(Vector &v)
    {
        if (this == &v)
            return *this;
        n = v.n;
        for (int i = 0; i < n; i++)
            arr[i] = v.arr[i];
        return *this;
    }
    Vector operator+(Vector &v)
    {
        for (int i = 0; i < n; i++)
            arr[i] += v.arr[i];
        return *this;
    }
    Vector operator-(Vector &v)
    {
        for (int i = 0; i < n; i++)
            arr[i] -= v.arr[i];
        return *this;
    }
    Vector operator*(T item)
    {
        for (int i = 0; i < n; i++)
            arr[i] = arr[i] * item;
        return *this;
    }
    Vector operator*(Vector &v)
    {
        T scal;
        for (int i = 0; i < n; i++)
        {
            scal += arr[i] * v.arr[i];
        }
        return scal;
    }
    void Show()
    {
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << *(arr + i);
            if (i < n - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    Vector<int> v1(5);
    v1.SetVector();
    v1.Show();
    cout << "\nМодуль вектора: " << v1.CountABS() << endl;

    Vector<int> v2(3);
    v2.SetVector();
    Vector<int> v3;
    v3 = v2;

    cout << "\nСумма вектора v2 и v3 =  ";
    v2 + v3;
    v2.Show();

    cout << endl;
    v3.Show();
    cout << " умноженный на 5: ";
    v3 * 5;
    v3.Show();

    cout << "\nИз ";
    v3.Show();
    cout << " вычесть ";
    v2.Show();

    v3 - v2;
    cout << " = ";
    v3.Show();

    cout << "\nСкалярное произведение ";
    v2.Show();
    cout << "и ";
    v3.Show();
    v2 *v3;
    cout << " = ";
    v2.Show();
    return 0;
}