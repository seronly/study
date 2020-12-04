#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

class perem3
{
    int a, b, c, i, j;
    int table[4][8];

public:
    perem3()
    {
        a = 4;
        b = 8;
        c = 0;
        for (i = 0; i < b; i++)
            for (j = 0; j < a; j++)
                table[j][i] = 0;
    }
    void A()
    {
        for (i = 0; i < b; i++)
        {
            if (i < a / 2)
                table[0][i] = 0;
            else
                table[0][i] = 1;
        }
    }
    void B()
    {
        for (i = 0; i < b; i++)
        {
            if (c < 2)
                table[1][i] = 0;
            else
                table[1][i] = 1;
        }
    }
    void C()
    {
        for (i = 0; i < b; i++)
        {
            if (i % 2 == 0)
                table[2][i] = 0;
            else
                table[2][i] = 1;
        }
    }
    void insover(const int x, const int y, int new_ins)
    {
        table[x][y];
    }
    int getvalue(const int x, const int y)
    {
        return table[x][i];
    }
    int getb()
    {
        return b;
    }
    int geta()
    {
        return a;
    }
};
class perem4
{
    int m, n, k = 0, i, j;
    int table[5][16];

public:
    perem4()
    {
        m = 5;
        n = 16;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                table[j][i] = 0;
    }
    void A()
    {
        for (i = 0; i < n; i++)
        {
            if (i < m / 2)
                table[0][i] = 0;
            else
                table[0][i] = 1;
        }
    }
    void B()
    {
        for (i = 0; i < n; i++)
        {
            if (m < 2)
                table[1][i] = 0;
            else
                table[1][i] = 1;
            k++;
            if (k >= 4)
                k = 0;
        }
    }
    void C()
    {
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                table[2][i] = 0;
            else
                table[2][i] = 1;
            k++;
            if (k >= 4)
                k = 0;
        }
    }
    void d()
    {
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                table[3][i] = 0;
            else
                table[3][i] = 1;
        }
    }
    void insover(const int x, const int y, int new_ins)
    {
        table[x][y];
    }
    int getvalue(const int x, const int y)
    {
        return table[x][i];
    }
    int getm()
    {
        return m;
    }
    int getn()
    {
        return n;
    }
};
bool lines_3, mon_3 = 1, doubleness_3 = 1, check_1_3 = 1, check_0_3;
void show_line_3(perem3 main_table, int number)
{
    cout << endl;
    int s = main_table.getb(), p = 1;
    int temp_mas[MAX][MAX];
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
            if (i == 0)
                temp_mas[i][j] = main_table.getvalue(3, j);
            else
                temp_mas[i][j] = -1;
    }
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s - p; j++)
        {
            if (temp_mas[p - 1][j] != temp_mas[p - 1][j + 1])
                temp_mas[p][j] = 1;
            else
                temp_mas[p][j] = 0;
        }
        p++;
    }

    p = 0;
    //треугольник паскаля
    cout << endl
         << "f" << number << ":" << endl;
    for (int i = 0; i < s; i++)
    {
        cout << main_table.getvalue(3, i) << " -";
        for (int h = 0; h < p; h++)
            cout << " ";
        for (int j = 0; j < s; j++)
        {
            if (temp_mas[i][j] != -1)
                cout << " " << temp_mas[i][j];
        }
        p++;
        cout << endl;
    }
    int max = 0, g;
    for (int i = 0; i < s; i++)
    {
        if (main_table.getvalue(0, i) == 1 && temp_mas[i][0] == 1)
        {
            g = main_table.getvalue(0, i) + main_table.getvalue(1, i) + main_table.getvalue(2, i);
            if (g > max)
                max = g;
        }
        cout << "f" << number << " - " << max << endl;
        if (g <= 1)
        {
            cout << "f" << number << "lineina" << endl;
            lines_3 = 1;
        }
        else
        {
            cout << "f" << number << "ne lineina" << endl;
        }
        for (int i = 0; i < s - 1; i++)
        {

            if (temp_mas[i][0] >= temp_mas[i + 1][0])
                mon_3 = 0;
        }
        if (mon_3)
            cout << "f" << number << " " << endl;
        else
            cout << "f" << number << " " << endl;

        for (int i = 0; i < s; i++)
        {
            if (temp_mas[i][0] == temp_mas[s - i][0])
                doubleness_3 = 0;
        }
        if (doubleness_3)
            cout << "f" << number << "samodvoisvennost`" << endl;

        else
            cout << "f" << number << "ne samodvoisvennost`" << endl;

        if (main_table.getvalue(3, 0) != 0)
            check_0_3 = 0;
        if (main_table.getvalue(3, s - 1) != 1)
            check_1_3 = 0;
        cout << "f" << number << " ";
        if (check_0_3)
            cout << "save 0";
        else
            cout << "not case 0";
        if (check_1_3)
            cout << "save 1";
        else
            cout << "not case 1";
        cout << endl;
    }
}
bool lines_4 = 1, mon_4 = 1, doubleness_4 = 1, check_1_4 = 1, check_0_4 = 1;
void show_line_4(perem4 main_table, int number)
{
    cout << endl;
    int s = main_table.getn(), p = 1;
    int temp_mas[MAX][MAX];

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i == 0)
                temp_mas[i][j] = main_table.getvalue(4, j);
            else
                temp_mas[i][j] = -1;
        }
    }

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s - p; j++)
        {
            if (temp_mas[p - 1][j] != temp_mas[p - 1][j + 1])
                temp_mas[p][j] = 1;
            else
                temp_mas[p][j] = 0;
        }
        p++;
    }

    p = 0;

    cout << endl
         << "Треугольник Паскаля для функции" << number << ":" << endl;

    for (int i = 0; i < s; i++)
    {
        cout << main_table.getvalue(4, i) << " -";
        for (int l = 0; l < p; l++)
            cout << " ";
        for (int j = 0; j < s; j++)
        {
            if (temp_mas[i][j] != -1)
                cout << " " << temp_mas[i][j];
        }
        p++;
        cout << endl;
    }
    int max = 0, g;
    for (int i = 0; i < s; i++)
        if (main_table.getvalue(4, i) == 1 && temp_mas[i][0] == 1)
        {
            g = main_table.getvalue(0, i) + main_table.getvalue(i, i) + main_table.getvalue(2, i) + main_table.getvalue(3, i);
            if (g > max)
                max = g;
        }
    cout << "Степень функции f" << number << " - " << max << endl;
    if (g <= 1)
    {
        cout << "Функция f" << number << " линейна." << endl;
        lines_4 = 1;
    }
    else
    {
        cout << "Функция f" << number << " нелинейна." << endl;
        lines_4 = 0;
    }
    for (int i = 0; i < s - 1; i++)
    {
        if (temp_mas[i][0] >= temp_mas[i + 1][0])
            mon_4 = 0;
    }
    if (mon_4)
        cout << "Функция f" << number << " монотонна." << endl;
    else
        cout << "Функция f" << number << " не монотонна." << endl;

    for (int i = 0; i < s; i++)
    {
        if (temp_mas[i][0] == temp_mas[s - i][0])
            doubleness_4 = 0;
    }
    if (doubleness_4)
        cout << "Функция f" << number << " самодвойственна." << endl;
    else
        cout << "Функция f" << number << " не самодвойстенна." << endl;
    if (main_table.getvalue(4, 0) != 0)
        check_0_4 = 0;
    if (main_table.getvalue(4, s - 1) != 1)
        check_1_4 = 0;

    cout << "Функция f" << number << " ";
    if (check_0_4)
        cout << " сохраняет нули,";
    else
        cout << " не сохраняет нули,";
    if (check_1_4)
        cout << " сохраняет единицы." << endl;
    else
        cout << " не сохраняет единицы." << endl;
}

int main(void)
{
    system("chcp 65001");
    system("cls");
    perem4 first;
    first.A();
    first.B();
    first.C();
    first.d();

    show_line_4(first, 5);

    return 0;
}
