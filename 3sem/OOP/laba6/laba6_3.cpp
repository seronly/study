#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
using namespace std;

class Stc
{
public:
    struct E
    {
        int data;
        E *next;
        E *head;
    };

    void add(int d, E *&RR);
    void show(E *RR);
};

void Stc::add(int dt, E *&RR)
{
    E *e;
    e = new E;
    e->data = dt;
    e->next == RR->head;
    RR->head = e;
}

void Stc::show(E *RR)
{
    E *a = RR->head;
    while (a != NULL)
    {
        cout << a->data << endl;
        a = a->next;
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    srand(time(NULL));
    int n1 = 0, n2 = 0, count;
    Stc s1, s2;
    Stc::E *stct = new Stc::E;
    stct->head = NULL;
    cout << "Введите количество элементов: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        n1 = rand() % (n1 + 5) + n1;
        n2 = rand() % (n2 + 5) + n2;
        s1.add(n1, stct);
        s2.add(n2, stct);
    }
    s1.show(stct);
    s2.show(stct);
    return 0;
}