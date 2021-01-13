#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
using namespace std;
#define MAX 100

class Stc
{
private:
    int data[MAX];

public:
    int n;
    Stc()
    {
        n = 0;
    }
    ~Stc() {}
    int get_top()
    {
        if (n == 0)
        {
            cerr << "Стек пуст!" << endl;
            return 0;
        }
        return data[n - 1];
    }
    void push(int item)
    {
        if (n < MAX)
        {
            data[n++] = item;
        }
        else
        {
            cerr << "Стек переполнен!" << endl;
        }
    }
    void del()
    {
        if (n == 0)
        {
            cerr << "Стек пуст!" << endl;
        }
        else
        {
            n--;
        }
    }
    int size()
    {
        return n;
    }
    void show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    srand(time(NULL));

    Stc s1, s2, s3;
    int k1, k2, n1 = 0, n2 = 0;
    cout << "Введите размер первого стека: ";
    cin >> k1;
    cout << "Введите размер второго стека: ";
    cin >> k2;
    for (int i = 0; i < k1; i++)
    {
        n1 = rand() % (n1 + 5) + n1;
        s1.push(n1);
    }
    for (int i = 0; i < k1; i++)
    {
        n2 = rand() % (n2 + 5) + n2;
        s2.push(n2);
    }
    cout << "Первый стек:" << endl;
    s1.show();
    cout << "Второй стек:" << endl;
    s2.show();
    while ((s1.size() > 0) || (s2.size() > 0))
    {
        if ((s1.size() > 0) && (s2.size() > 0))
        {
            if (s1.get_top() > s2.get_top())
            {
                s3.push(s1.get_top());
                s1.del();
            }
            else
            {
                s3.push(s2.get_top());
                s2.del();
            }
        }
        else if (s1.size() > 0)
        {
            s3.push(s1.get_top());
            s1.del();
        }
        else
        {
            s3.push(s2.get_top());
            s2.del();
        }
    }
    cout << "Размер 3 стека: " << s3.size() << endl;
    cout << "Третий стек с объединением: " << endl;
    while (s3.size())
    {
        cout << s3.get_top() << " ";
        s3.del();
    }
    return 0;
}
