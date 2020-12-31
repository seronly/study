#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class B
{	int a;
public:
	B() { a = 0; };
	B(int x) { a = x; }
	void show_B() { cout << "B= " << a << "\n"; }
};
class D1 : public B
{	int b;
public:
	D1(int x, int y) : B(y) { b = x; };
	void show_D1() { cout << "D1= " << b << "\n"; show_B(); }
};
class D2 : private B
{	int d;
public:
	D2(int x, int y) : B(y) { d = x; };
	void show_D2() { cout << "D2= " << d << "\n"; show_B(); }
};
class D3 : private D1, public D2
{	int e;
public:
	D3(int x, int y, int z, int i, int j) : D1(y, z), D2(i, j) { e = x; }
	void show_D3() { cout << "D3= " << e << "\n"; show_D1(); show_D2(); }
};
int main()
{
	setlocale(LC_ALL, "Russian");
	D3 temp(100, 200, 300, 400, 500);
	cout << "D3 temp(100,200,300,400,500);\n";
	cout << "\n—леду€ иерархии класса D3: \n";
	temp.show_D3();
	system("pause");
	return 0;
}