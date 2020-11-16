#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
#include <sstream>
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
    Str toUp;
    toUp.a = a;
    for (int i = 0; i < a.length() + 1; i++)
    {
        toUp.a[i] = toupper(a[i]);
    }
    {
        return toUp;
    }
}

Str Str::operator--()
{
    Str k;
    string word, min_word;
    istringstream r(a);
    r >> min_word;
    while (r >> word)
        if (min_word.size() > word.size())
            min_word = word;
    k.a = min_word;
    {
        return k;
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    Str A, B, C;
    A.a = "Hello, my world!";
    B = A;
    B.show();
    C = ++B;
    cout << "Все строки в заглавные: ";
    C.show();
    C = --B;
    cout << "Самое короткое слово в строке: ";
    C.show();
    return 0;
}
