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
    void show_B1() { cout << "B1 = " << a << endl; }
};
class B2
{
private:
    int b;

public:
    B2() { b = 0; }
    B2(int x) { b = x; }
    void show_B2() { cout << "B2 = " << b << endl; }
};
class D1 : private B1, public B2
{
private:
    int c;

public:
    D1() { c = 0; }
    D1(int x, int y, int z) : B1(y), B2(z) { c = x; }
    void show_D1()
    {
        cout << "D1 = " << c << endl;
        show_B1();
        show_B2();
    }
};

class D2 : public D1
{
private:
    int d;

public:
    D2() { d = 0; }
    D2(int x, int y, int z, int i) : D1(y, z, i) { d = x; }
    void show_D2()
    {
        cout << "D2 = " << d << endl;
        show_D1();
    }
};

class D3 : public D1
{
private:
    int d;

public:
    D3() { d = 0; }
    D3(int x, int y, int z, int i) : D1(y, z, i) { d = x; }
    void show_D3()
    {
        cout << "D3 = " << d << endl;
        show_D1();
    }
};

main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    D2 temp1(1, 2, 3, 4);
    D3 temp2(100, 200, 300, 400);
    cout << "D3 temp1(1, 2, 3, 4);\nD3 temp2(100, 200, 300, 400);\n";
    cout << "Следуя иерархии класса D2: \n";
    temp1.show_D2();
    cout << "Следуя иерархии класса D3: \n";
    temp2.show_D3();

    return 0;
}