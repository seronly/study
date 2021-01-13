#include <iostream>
using namespace std;

class curve
{
protected:
public:
    int x;
    long y;
    curve(){};
    curve(int a)
    {
        x = a;
    }
    virtual void foo() = 0;
    int getx()
    {
        return x;
    }
    /*void show()
	{
		cout << y << endl;
	}
	*/
};
/*void curve::foo()
{
	y = sqrt(10 ^ 2 - (x - 5) ^ 2) + 4;
	cout << "Кривая =" << y << endl;
}*/

class line : public curve
{
public:
    line(int a) : curve(a)
    {
    }

    void show()
    {
        cout << y << endl;
    }

    void foo()
    {
        y = 2 * x + 3;
        cout << y << endl;
    }
};

class elli : public curve
{
public:
    elli(int a) : curve(a) {}

    void show()
    {
        cout << y << endl;
    }

    void foo()
    {
        double a = 1, b = 1;
        y = (1 - getx() / a) * b;
        cout << "Эллипс =" << y << endl;
    }
};

class gyper : public curve
{
public:
    gyper(int a) : curve(a) {}
    void show()
    {
        cout << y << endl;
    }

    void foo()
    {
        y = 1 / getx();
        cout << "Гипербола =" << y << endl;
    }
};

int main()
{
    // setlocale(LC_ALL, "rus");
    setlocale(LC_ALL, "65001");
    double c, i, k;
    cout << "Введите х " << endl;
    cin >> c;
    line liner(c);
    liner.show();
    cout << "Введите х " << endl;
    cin >> i;
    elli ellis(i);
    ellis.show();
    cout << "Введите х " << endl;
    cin >> k;
    gyper gypper(k);
    gypper.show();
    /*curve* f[3]
	{
	f[0] = &liner,
	f[1] = &ellis,
	f[2] = &gypper
	};
	for (int i = 0; i < 3; i++)
	{
		f[i]->show();

	}*/

    return 0;
}
