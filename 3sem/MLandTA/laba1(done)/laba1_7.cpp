#include <iostream>
#include <Windows.h>
#include <locale>
#include <cassert>
#include <cmath>
#include <cstring>
using namespace std;
//(D=>B)||A
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int A, B, D, checkInt = 0, num = 8;
    bool checkBool, checkT = true, checkF = true;
    string Hline = "-----------------------------------------------------------------------------------------";
    cout
        << "|\tA\t|\tB\t|\tD\t|\tD=>B\t|\t(D=>B)||A\t|" << endl;
    cout << Hline << endl;
    for (int i = 0; i < num; i++)
    {
        //���������� ������� ��� A
        if (i >= (num / 2))
        {
            A = 1;
        }
        else
        {
            A = 0;
        }
        //���������� ������� ��� B
        if (checkInt == 2 || checkInt == 3)
        {
            B = 1;
            checkInt++;
            if (checkInt == 4)
            {
                checkInt = 0;
            }
        }
        else
        {
            B = 0;
            checkInt++;
        }
        //���������� ������� ��� D
        if (i % 2 == 0 || i == 0)
        {
            D = 0;
        }
        else
        {
            D = 1;
        }
        //���������� ������� ��� D=>B
        if (D == 1 && B == 0)
        {
            checkBool = false;
        }
        else
        {
            checkBool = true;
        }

        cout
            << "|\t" << A << "\t|\t" << B << "\t|\t" << D << "\t|\t" << checkBool << "\t|\t" << (checkBool || A) << "\t\t|" << endl;
        cout << Hline << endl;
        if ((checkBool || A) == 1)
        {
            checkF = false;
        }
        else
        {
            checkT = false;
        }
    }

    if (checkT == false && checkF == false)
    {
        cout << "������� ���������, �� �� �������� ������������ ��������." << endl;
    }
    else if (checkT == true && checkF == false)
    {
        cout << "������� �����������, �.�. ������ ��� ����� ��������." << endl;
    }
    else if (checkF == true && checkT == false)
    {
        cout << "������� �� ��������� ��� ����� ��������." << endl;
    }
    return 0;
}