#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
int position;

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    int i = 0, q = 1;
    string P;

    cout << "Введите слово любой длины, используя алфавит A={a,b,c,d}.\nЕсли первый и последний символ не равны, слово заменится на символы a.\nСлово: ";
    cin >> P;
    for (int j = 0; j < P.length(); j++)
    {
        if (P[j] != 'a' && P[j] != 'b' && P[j] != 'c' && P[j] != 'd')
        {
            q = 0;
            break;
        }
    }

    if (q == 0)
    {
        cout << "Вы ввели слово с недопустимыми символами!" << endl;
    }
    else
    {

        while (q != 0)
        {
            switch (q)
            {
            case 0:
                q = 0;
                break;
            case 1:
                switch (P[i])
                {
                case 'a':
                    q = 2;
                    break;
                case 'b':
                    q = 4;
                    break;
                case 'c':
                    q = 6;
                    break;
                case 'd':
                    q = 8;
                    break;
                case '\0':
                    q = 0;
                    break;
                }
                break;

            case 2:
                switch (P[i])
                {
                case 'a':
                    i++;
                    break;
                case 'b':
                    i++;
                    break;
                case 'c':
                    i++;
                    break;
                case 'd':
                    i++;
                    break;
                case '\0':
                    i--;
                    q = 3;
                    break;
                }
                break;

            case 3:
                switch (P[i])
                {
                case 'a':
                    q = 0;
                    break;
                case 'b':
                    q = 10;
                    break;
                case 'c':
                    q = 10;
                    break;
                case 'd':
                    q = 10;
                    break;
                case '\0':
                    break;
                }
                break;

            case 4:
                switch (P[i])
                {
                case 'a':
                    i++;
                    break;
                case 'b':
                    i++;
                    break;
                case 'c':
                    i++;
                    break;
                case 'd':
                    i++;
                    break;
                case '\0':
                    i--;
                    q = 5;
                    break;
                }
                break;

            case 5:
                switch (P[i])
                {
                case 'a':
                    q = 10;
                    break;
                case 'b':
                    q = 0;
                    break;
                case 'c':
                    q = 10;
                    break;
                case 'd':
                    q = 10;
                    break;
                case '\0':
                    break;
                }
                break;
            case 6:
                switch (P[i])
                {
                case 'a':
                    i++;
                    break;
                case 'b':
                    i++;
                    break;
                case 'c':
                    i++;
                    break;
                case 'd':
                    i++;
                    break;
                case '\0':
                    i--;
                    q = 7;
                    break;
                }
                break;
            case 7:
                switch (P[i])
                {
                case 'a':
                    q = 10;
                    break;
                case 'b':
                    q = 10;
                    break;
                case 'c':
                    q = 0;
                    break;
                case 'd':
                    q = 10;
                    break;
                case '\0':
                    break;
                }
                break;
            case 8:
                switch (P[i])
                {
                case 'a':
                    i++;
                    break;
                case 'b':
                    i++;
                    break;
                case 'c':
                    i++;
                    break;
                case 'd':
                    i++;
                    break;
                case '\0':
                    i--;
                    q = 9;
                    break;
                }
                break;
            case 9:
                switch (P[i])
                {
                case 'a':
                    q = 10;
                    break;
                case 'b':
                    q = 10;
                    break;
                case 'c':
                    q = 10;
                    break;
                case 'd':
                    q = 0;
                    break;
                case '\0':
                    break;
                }
                break;
            case 10:
                switch (P[i])
                {
                case 'a':
                    P[i] = 'a';
                    i--;
                    break;
                case 'b':
                    P[i] = 'a';
                    i--;
                    break;
                case 'c':
                    P[i] = 'a';
                    i--;
                    break;
                case 'd':
                    P[i] = 'a';
                    i--;
                    break;
                case '\0':
                    q = 0;
                    break;
                }
                break;
            }
        }
        cout << "Готовое слово: " << P << endl;
    }
    return 0;
}
