#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
using namespace std;

class B1
{
private:
    int a;

public:
    B1() { a = 0; }
    B1(int x) { a = x; }
    void show_B1() { cout << "B1 = " << a << "\n"; }
};
class B2
{
private:
    int b;

public:
    B2() { b = 0; }
    B2(int x) { b = x; }
    void show_B2() { cout << "B2 = " << b << "\n"; }
};
class D1 : private B1, public B2
{
private:
    int c;

public:
};
main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    return 0;
}