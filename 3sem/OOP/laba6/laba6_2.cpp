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
    bool check = true;
    string temp, temp_min;
    char buf[] = {' ', ',', '.', '!', '?', ':', ';', '"'};
    for (int i = 0; i < a.length() + 1; i++)
    {
        for (int j = 0; j < sizeof(buf); j++)
        {
            if (a[i] == buf[j])
            {
                check = false;
                if ((temp.length() < temp_min.length() || temp_min.length() == 0) && temp.length() > 0)
                {
                    temp_min = temp;
                }
            }
        }
        if (check)
        {
            temp += a[i];
        }
        else
        {
            temp.clear();
            check = true;
        }
    }

    cout << "Самое короткое слово: " << temp_min << endl;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Str A, B, C;
    A.a = "Hello, my world!";
    B = A;
    B.show();
    ++B;
    --B;

    return 0;
}