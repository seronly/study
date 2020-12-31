#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class GraphicalObject
{
protected:
	int x, y;
	string type;

public:
	GraphicalObject()
	{
		x = y = 0;
		type = "";
	}
	GraphicalObject(int X, int Y)
	{
		x = X;
		y = Y;
	}
	virtual void Write()
	{
		cout << "===============" << endl;
		cout << "( " << x << " ; " << y << " )" << endl;
	}
};

class Circle : GraphicalObject
{
	int r;

public:
	Circle() : GraphicalObject()
	{
		r = 0;
		type = "Круг";
	}
	Circle(int R, int X, int Y) : GraphicalObject(X, Y)
	{
		r = R;
		type = "Круг";
	}
	void Write() override
	{
		cout << "===============================" << endl;
		cout << type << "c радиусом " << r << " с координатами центра";
		cout << "( " << x << " ; " << y << " )" << endl;
	}
};

class Rectangle : GraphicalObject
{
	int a, b;

public:
	Rectangle() : GraphicalObject()
	{
		a = b = 0;
		type = "Прямоугольник";
	}
	Rectangle(int A, int B, int X, int Y) : GraphicalObject(X, Y)
	{
		a = A;
		b = B;
		type = "Прямоугольник";
	}
	void Write() override
	{
		cout << "===============================" << endl;
		cout << type << "cо сторонами " << a << " и " << b << " с координатами левого верхнего угла";
		cout << "( " << x << " ; " << y << " )" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Circle c(10, 5, 5);
	Rectangle r(5, 2, -1, 2);
	c.Write();
	cout << endl;
	r.Write();
	cout << endl
		 << endl
		 << endl;
	return 0;
}