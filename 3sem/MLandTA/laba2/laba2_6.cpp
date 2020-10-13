#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cmath>
#include <cstring>
using namespace std;
//A + BCD + !B!C
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int A, B, C, D, F, F1, F2, checkInt = 0, num = 16;
    bool checkBool, checkFirst = false;
    string Hline = "-----------------------------------------------------------------------------------------------------------------";
    cout << "F = A + BCD + !B!C\n"
         << endl;
    cout << Hline << endl;
    cout
        << "|\tA\t|\tB\t|\tC\t|\tD\t|\tBCD\t|\t!B!C\t|\tF\t|" << endl;
    cout << Hline << endl;
    for (A = 0; A < 2; A++)
    {
        for (B = 0; B < 2; B++)
        {
            for (C = 0; C < 2; C++)
            {
                for (D = 0; D < 2; D++)
                {
                    F1 = B * C * D;
                    F2 = !B * !C;
                    checkBool = A + F1 + F2;
                    cout
                        << "|\t" << A << "\t|\t" << B << "\t|\t" << C << "\t|\t" << D << "\t|\t" << F1 << "\t|\t" << F2 << "\t|\t" << checkBool << "\t|" << endl;
                    cout << Hline << endl;
                }
            }
        }
    }

    cout << "\n\nÑÄÍÔ: " << endl;
    checkFirst = false;
    for (A = 0; A < 2; A++)
    {
        for (B = 0; B < 2; B++)
        {
            for (C = 0; C < 2; C++)
            {
                for (D = 0; D < 2; D++)
                {
                    F1 = B * C * D;
                    F2 = !B * !C;
                    checkBool = A + F1 + F2;
                    if (!checkFirst && checkBool)
                    {
                        checkFirst = true;
                        if (A == 0)
                        {
                            cout << "!A";
                        }
                        else
                        {
                            cout << "A";
                        }
                        if (B == 0)
                        {
                            cout << "!B";
                        }
                        else
                        {
                            cout << "B";
                        }
                        if (C == 0)
                        {
                            cout << "!C";
                        }
                        else
                        {
                            cout << "C";
                        }
                        if (D == 0)
                        {
                            cout << "!D";
                        }
                        else
                        {
                            cout << "D";
                        }
                    }
                    else if (checkBool && checkFirst)
                    {
                        checkFirst = true;
                        if (A == 0)
                        {
                            cout << " + !A";
                        }
                        else
                        {
                            cout << " + A";
                        }
                        if (B == 0)
                        {
                            cout << "!B";
                        }
                        else
                        {
                            cout << "B";
                        }
                        if (C == 0)
                        {
                            cout << "!C";
                        }
                        else
                        {
                            cout << "C";
                        }
                        if (D == 0)
                        {
                            cout << "!D";
                        }
                        else
                        {
                            cout << "D";
                        }
                    }
                }
            }
        }
    }

    cout << "\n\nÑÊÍÔ: " << endl;
    checkFirst = false;
    for (A = 0; A < 2; A++)
    {
        for (B = 0; B < 2; B++)
        {
            for (C = 0; C < 2; C++)
            {
                for (D = 0; D < 2; D++)
                {
                    F1 = B * C * D;
                    F2 = !B * !C;
                    checkBool = A + F1 + F2;
                    if (!checkFirst && !checkBool)
                    {
                        checkFirst = true;
                        if (A == 1)
                        {
                            cout << "(!A";
                        }
                        else
                        {
                            cout << "(A";
                        }
                        if (B == 1)
                        {
                            cout << " + !B";
                        }
                        else
                        {
                            cout << " + B";
                        }
                        if (C == 1)
                        {
                            cout << " + !C";
                        }
                        else
                        {
                            cout << " + C";
                        }
                        if (D == 1)
                        {
                            cout << " + !D)";
                        }
                        else
                        {
                            cout << " + D)";
                        }
                    }
                    else if (!checkBool && checkFirst)
                    {
                        checkFirst = true;
                        if (A == 1)
                        {
                            cout << "(!A";
                        }
                        else
                        {
                            cout << "(A";
                        }
                        if (B == 1)
                        {
                            cout << " + !B";
                        }
                        else
                        {
                            cout << " + B";
                        }
                        if (C == 1)
                        {
                            cout << " + !C";
                        }
                        else
                        {
                            cout << " + C";
                        }
                        if (D == 1)
                        {
                            cout << " + !D)";
                        }
                        else
                        {
                            cout << " + D)";
                        }
                    }
                }
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
