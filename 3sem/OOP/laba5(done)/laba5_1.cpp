#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <string>
using namespace std;

class Cstr
{
    char *ss;

public:
    Cstr(const char *);
    Cstr(const Cstr &h)
    {
        for (int i = 0; i < strlen(ss) + 1; i++)
        {
            ss[i] = h.ss[i];
        }
        cout << "Вызван второй конструктор (копирование)" << endl;
    };

    const char *get_ss() const { return ss; }

    void strcanc(const Cstr &h)
    {
        cout << strcat(ss, h.ss) << endl;
    };
    void count_sentence()
    {
        int count = 0;
        for (int i = 0; i < strlen(ss) + 1; i++)
        {
            if ((ss[i] == '.' || ss[i] == '?' || ss[i] == '!') && (ss[i + 1] == ' ' || ss[i + 1] == '\0'))
            {
                count++;
            }
        }
        if (count > 0)
        {
            cout << "В строке \"" << ss << "\" " << count << " предложение(ий)" << endl;
        }
        else
            cout << "Предложений не найдено..." << endl;
    };
};
Cstr::Cstr(const char *_ss)
{
    ss = new char[strlen(_ss) + 1];
    strcpy(ss, _ss);
    cout << "Вызван первый (определяющий) конструктор" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Cstr str1 = "Hello. World!";
    cout << "Строка 1: " << str1.get_ss() << endl;
    Cstr str2(str1);
    cout << "Строка 2: " << str2.get_ss() << endl;
    cout << "Слияние двух строк: ";
    str1.strcanc(str2);
    str2.count_sentence();

    return 0;
}