#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#define PI 3.14159265
using namespace std;

class Figure
{
public:
    virtual void Write() = 0;
};

class Parallepiped : public Figure
{
    float a, b, c;

public:
    Parallepiped()
    {
        a = 125;
        b = 5;
        c = 17;
    }
    void Write() override
    {
        cout << "Объем параллепипеда со сторонами " << a << "; " << b << "; " << c << "; =  " << a * b * c << endl;
    }
};

class Piramida : public Figure
{
    float S, H;

public:
    Piramida()
    {
        S = 13;
        H = 25;
    }
    void Write() override
    {
        cout << "Объем пирамиды с площадью основания = " << S << " и высотой " << H << " =  " << (S * H) / 3 << endl;
    }
};

class Tetraedr : public Figure
{
private:
    float a;

public:
    Tetraedr() { a = 34; }
    void Write() override
    {
        cout << "Объем тетраэдра с длиной ребра " << a << " =  " << (a * a * a * sqrt(2)) / 12 << endl;
    }
};

class Shar : public Figure
{
private:
    float r;

public:
    Shar()
    {
        r = 23;
    }
    void Write() override
    {
        cout << "Объем шара с радиусом " << r << " = " << (4 * PI * r * r * r) / 3 << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("clear");
    Parallepiped parallepiped;
    Piramida piramida;
    Tetraedr tetraedr;
    Shar shar;

    Figure *f[4]{
        f[0] = &parallepiped,
        f[1] = &piramida,
        f[2] = &tetraedr,
        f[3] = &shar};

    for (int i = 0; i < 4; i++)
    {
        f[i]->Write();
    }

    return 0;
}