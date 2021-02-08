#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    string P;
    bool checkIn = true; // булевая переменная для проверки символов
    cout << "A = {f, h, p}" << endl;
    cout << "Введите P слово: ";
    cin >> P;
    //transform(P.begin(), P.end(), P.begin(), std::tolower);
    cout
        << endl;
    // проверка символов
    for (int i = 0; i < P.length(); i++)
    {
        if (!(P[i] == 'f' || P[i] == 'h' || P[i] == 'p'))
        {
            cerr << "Введены неверные символы!" << endl;
            checkIn = false;
            break;
        }
    }

    if (checkIn)
    {
        cout << P << endl;

        P = "*" + P;
        cout << P << endl;

        while (true)
        {
            if (P[P.find("*") + 1] == 'p' && P[P.find("*") + 2] == 'h')
            {
                P.replace(P.find("*"), 3, "f**");
                cout << P << endl;
            }

            if (P[P.find("*") + 1] == '*' && P[P.find("*") + 2] == 'f')
            {
                P.replace(P.find("*"), 3, "f**");
                cout << P << endl;
            }
            if (P[P.find("*") + 1] == '*' && P[P.find("*") + 2] == 'h')
            {
                P.replace(P.find("*"), 3, "h**");
                cout << P << endl;
            }
            if (P[P.find("*") + 1] == '*' && P[P.find("*") + 2] == 'p')
            {
                P.replace(P.find("*"), 3, "p**");
                cout << P << endl;
            }

            if (P[P.find("*") + 1] == 'p')
            {
                P.replace(P.find("*"), 2, "p*");
                cout << P << endl;
            }
            if (P[P.find("*") + 1] == 'f')
            {
                P.replace(P.find("*"), 2, "f*");
                cout << P << endl;
            }
            if (P[P.find("*") + 1] == 'h')
            {
                P.replace(P.find("*"), 2, "h*");
                cout << P << endl;
            }

            if (P[P.find("*") + 1] == '*' && P[P.find("*") + 2] == '\0')
            {
                P.replace(P.find("*"), 2, "");
                cout << P << endl;
                break;
            }

            if (P[P.find("*") + 1] == '\0')
            {
                P.replace(P.find("*"), 1, "");
                break;
            }
        }
        cout << "Резульат работы НАМ: " << P << endl;
    }
    else
    {
        cout << "Проверьте введенное слово: " << P << endl;
    }

    return 0;
}