#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// из 3 в 14

int _3to10(string item)
{
    int sizeN = item.length();
    int N = sizeN;
    int temp, dec = 0;
    try
    {
        for (int i = 0; i < sizeN; i++)
        {
            temp = (int)item[i] - 48;
            if (temp < 0 || temp > 2)
            {
                throw "Число не в троичной системе счисления!";
            }
            dec += temp * pow(3, N - 1);
            N--;
        }
        return dec;
    }
    catch (const char *e)
    {
        cout << e << '\n';
        return 0;
    }
}

void _10to14(string input)
{
    string _14, temp;
    int item = _3to10(input);
    try
    {
        if (item == 0)
            throw 0;
        while (item > 0)
        {
            temp += to_string(item % 14);
            item /= 14;
        }
        for (int i = temp.length() - 1; i >= 0; i--)
        {
            _14 += temp[i];
        }
        cout << "Число " << input << " из 3 системы счисления в 14: " << _14 << endl;
    }
    catch (int e)
    {
        cerr << "Число не может быть преобразовано в 14 систему счисления!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    string input;
    cout << "Введите число в троичной системе счисления: ";
    cin >> input;
    _10to14(input);

    return 0;
}