#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <string>
using namespace std;

class Per
{
public:
    string a;
    char b;
    Per operator!=(Per t);
    Per operator%(Per t);

    void strlen();
};
Per Per::operator!=(Per t)
{
    Per t1, t2;
    bool check = false;
    t1.a = a;
    t2.b = t.b;
    for (int i = 0; i < t1.a.length() + 1; i++)
    {
        if (t1.a[i] == t2.b)
        {
            check = true;
        }
    }
    if (check)
    {
        cout << "Данный символ есть в строке." << endl;
    }
    else
    {
        cout << "Данного символа нет в строке." << endl;
    }
};
Per Per::operator%(Per t)
{
    cout << "Код символа " << t.b << " в ASCII: " << (int)t.b << endl;
};
void Per::strlen()
{
    int count = 0, i = 0;
    for (i = 0; i < a.length() + 1; i++)
    {
        count += (int)a[i];
    }
    cout << "Сумма кодов ASCII всех символов первой строки = " << count << endl;
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Per str1, str2;
    cout << "Введите первую строку: ";
    getline(cin, str1.a);
    cout << "Введите символ для поиска в первой строке и для перевода в код ASCII: ";
    cin >> str2.b;
    cout << endl;
    str1 != str2;
    str1 % str2;
    str1.strlen();
    return 0;
}