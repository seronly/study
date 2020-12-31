#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    system("cls");
    string P;
    cout << "A = {a, b, c}" << endl;
    cout << "Введите P слово: ";
    cin >> P;
    cout << endl;
    bool probel = true;
    int sch = 0;
    P = "*" + P;

    while (P.length() - 1 > 0)
    {
        if (P[P.find("*") + 1] == 'a')
        {
            // P.erase(P.find("a"));
            P.replace(P.find("*"), 2, "*");
            cout << P << endl;
        }

        if (P[P.find("*") + 1] == 'b')
        {
            //P.erase(P.find("b"));
            P.replace(P.find("*"), 2, "*");
            cout << P << endl;
        }

        if (P[P.find("*") + 1] == 'c')
        {
            // P.erase(P.find("c"));
            P.replace(P.find("*"), 2, "*");
            cout << P << endl;
        }

        if (P[P.find("*") + 1] == '\0')
        {
            //P.erase(P.find("*"), 1);
            P.replace(P.find("*"), 1, "");
            P = P + "a";
            probel = false;
        }
    }

    cout << "Итог работы НАМ: " << P << endl;

    return 0;
}