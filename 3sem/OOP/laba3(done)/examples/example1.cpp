#include <iostream>
#include <math.h>
using namespace std;
//������� ��� ��������� ��� �������� ���������� � ����������� ����� � ���������� �������
struct cartesian
{
    double x, y;
};

//� � �������� ������� ���������
struct polar
{
    double r, pi;
};
//������ ��������� ������������� �������, ����������� ���������� ���� ����� ����� �������� ����������

double len(polar a, polar b)
{
    cout << "������� ���������� ����� �������� ����������" << endl;
    return sqrt(pow(a.r, 2) + pow(b.r, 2) - 2 * a.r * b.r * cos(a.pi - b.pi));
}

//� ����� ����������� ���������� ���� ����� ����� ��������� ����������
double len(cartesian x, cartesian y)
{
    cout << "������� ���������� ����� ��������� ����������" << endl;
    return sqrt(pow(y.x - x.x, 2) + pow(y.y - x.y, 2));
}

//����� �������, ��� ��� �������� ������� ���������� ���������� ��������� ���������� ���� �����
double len(double x1, double y1, double x2, double y2)
{
    cout << "������� ���������� ����� ��������� ���������� � 4-�� ����������� " << endl;
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(int argc, char *argv[])
{
    const double PI = 3.14159;
    cartesian a = {3, 0},
              b = {1, 1};
    polar c = {1.41, PI / 4},
          d = {3.1, 0.95};
    double x1 = 1.4, y1 = 2.5,

           x2 = 2.1, y2 = 3.7;

    cout << len(a, b) << endl;

    cout << len(c, d) << endl;

    cout << len(x1, y1, x2, y2) << endl;

    return 0;
}