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
    Parallepiped(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
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
    Piramida(float s, float h)
    {
        S = s;
        H = h;
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
    Tetraedr(float x) { a = x; }
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
    Shar() { r = 23; }
    Shar(float R) { r = R; }
    void Write() override
    {
        cout << "Объем шара с радиусом " << r << " = " << (4 * PI * r * r * r) / 3 << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    Parallepiped parallepiped(13, 15, 17);
    Piramida piramida(12, 21);
    Tetraedr tetraedr(10);
    Shar shar(8);

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