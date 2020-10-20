#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
using namespace std;

class Str
{
public:
    string a;
    Str operator++(); // в заглавные
    Str operator--(); // самое короткое слово в строке
    void show()
    {
        cout << a << endl;
    };
};
Str Str::operator++()
{
    char *toUp = new char[a.length() + 1];
    for (int i = 0; i < a.length() + 1; i++)
    {
        toUp[i] = toupper(a[i]);
    }
    cout << toUp << endl;
};
Str Str::operator--()
{
    cout << "Оператор --" << endl;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Str A, B, C;
    A.a = "Hello, world!";
    B = A;
    B.show();
    ++B;
    --B;

    return 0;
}