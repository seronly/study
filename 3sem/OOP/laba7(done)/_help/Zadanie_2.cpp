#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Transport
{
protected:
	string name, type;
	float speed, rent;

public:
	Transport()
	{
		name = type = "";
		speed = rent = 0;
	}
	Transport(string n, float s, float r)
	{
		name = n;
		speed = s;
		rent = r;
	}
	// Вывод в консоль
	virtual void Write()
	{
		cout << "=======================" << endl;
		cout << type << endl;
		cout << name << endl;
		cout << "Скорость " << speed << " км/ч" << endl;
		cout << "Плата " << rent << " руб/ч" << endl;
	}
	//Возврат времени
	float Time(float distances)
	{
		float time = distances / speed;
		return int(time * 100 + 0.5) / 100.0;
	}
	// Подсчёт денег за проезд
	float MoneyForTravel(float distances)
	{
		return ceil(Time(distances)) * rent;
	}
	// Вывод денег за проезд в консоль
	virtual void operator==(float distances)
	{
		cout << "Перевозка на " << name << " на " << distances << " км." << endl;
		cout << "Займёт " << Time(distances) << " ч." << endl;
		cout << "Плата " << MoneyForTravel(distances) << " руб." << endl;
	}
};

class Car : public Transport
{
	string color, number;

public:
	Car()
	{
		color = number = "";
		type = "Машина";
	}
	Car(string c, string num, string n, float s, float r) : Transport(n, s, r)
	{
		color = c;
		number = num;
		type = "Машина";
	}
	void Write() override
	{
		cout << "=======================" << endl;
		cout << type << endl;
		cout << color << " " << name << " c номером " << number << endl;
		cout << "Скорость " << speed << " км/ч" << endl;
		cout << "Плата " << rent << " руб/ч" << endl;
	}
	void operator==(float distances) override
	{
		cout << "Перевозка на " << color << " " << name << " c номером " << number << endl;
		cout << "На " << distances << " км." << endl;
		cout << "Займёт " << Time(distances) << " ч." << endl;
		cout << "Плата " << MoneyForTravel(distances) << " руб." << endl;
	}
};

class Bicycle : public Transport
{
	string color;

public:
	Bicycle()
	{
		color = "";
		type = "Велосипед";
	}
	Bicycle(string c, string n, float s, float r) : Transport(c + " " + n, s, r)
	{
		color = c;
		type = "Велосипед";
	}
};
class Cart : public Transport
{
	string stile;

public:
	Cart()
	{
		stile = "";
		type = "Телега";
	}
	Cart(string c, string n, float s, float r) : Transport(c + " " + n, s, r)
	{
		stile = c;
		type = "Телега";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Transport *mass[6]{
		mass[0] = new Car("Синяя", "М101РК", "Mazda", 60, 1000),
		mass[1] = new Bicycle("Белый", "AGang", 25, 150),
		mass[2] = new Cart("Деревянная", "телега", 10, 100),
		mass[3] = new Car("Красная", "М051МП", "Toyta", 70, 1100),
		mass[4] = new Bicycle("Чёрный", "Altair", 30, 200),
		mass[5] = new Cart("Железная", "телега", 15, 120),
	};
	for (int i = 0; i < 6; i++)
	{
		mass[i]->Write();
		cout << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		mass[i]->operator==(200);
		cout << endl;
	}
	Transport a;
	return 0;
}