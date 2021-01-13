#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Point
{
protected:
    int x, y;
    string type;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    virtual void setX(int a) { x = a; }
    virtual void setY(int b) { y = b; }
    virtual int getX() { return x; }
    virtual int getY() { return y; }
    virtual string getType() { return type; }

    virtual void changePoint(int a, int b)
    {
        x = a;
        y = b;
    }
    virtual void changeCharc() = 0;
    virtual void output() = 0;
};

class ColoredPoint : public Point
{
protected:
    string color;

public:
    ColoredPoint() : Point()
    {
        type = "Цветная точка";
        color = "Нет цвета";
    }
    ColoredPoint(int a, int b, string c) : Point(a, b)
    {
        type = "Цветная точка";
        color = c;
    }
    string getPointColor() { return color; }

    void setColor(string c) { color = c; }
    virtual void setCharacter(int a, int b, string c)
    {
        this->changePoint(a, b);
        color = c;
    }

    void output() override
    {
        cout << endl
             << type << endl;
        cout << "Х = " << x << "; Y = " << y << ";";
        cout << "\nЦвет: " << color << endl;
    }
    void changeCharc() override
    {
        cout << "X = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;
        cout << "Цвет: ";
        cin >> color;
    }
};

class Line : public Point
{
protected:
    int endx, endy;

public:
    Line()
    {
        x = y = endx = endy = 0;
        type = "Линия";
    }
    Line(int x1, int y1, int x2, int y2)
    {
        x = x1;
        y = y1;
        endx = x2;
        endy = y2;
        type = "Линия";
    }
    int getEndX()
    {
        return endx;
    }
    int getEndY()
    {
        return endy;
    }

    void setLine(int x1, int y1, int x2, int y2)
    {
        x = x1;
        y = y1;
        endx = x2;
        endy = y2;
    }
    void output() override
    {
        cout << endl
             << type << endl;
        cout << "Первая точка: " << endl;
        cout << "Х = " << x << "; Y = " << y << ";";
        cout << endl;
        cout << "Вторая точка: " << endl;
        cout << "Х = " << endx << "; Y = " << endy << ";\n";
    }
    void output(int i)
    {
        cout << endl
             << type << " " << i << endl;
        cout << "Первая точка: " << endl;
        cout << "Х = " << x << "; Y = " << y << ";";
        cout << endl;
        cout << "Вторая точка: " << endl;
        cout << "Х = " << endx << "; Y = " << endy << ";\n";
    }
    void changeCharc() override
    {
        cout << "Первая точка: " << endl;
        cout << "Х = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;
        cout << endl;
        cout << "Вторая точка: " << endl;
        cout << "Х = ";
        cin >> endx;
        cout << "Y = ";
        cin >> endy;
    }
};

class ColoredLine : public Line
{
protected:
    string color;

public:
    ColoredLine() : Line()
    {
        type = "Цветная линия";
        color = "Нет цвета";
    }
    ColoredLine(int x1, int y1, int x2, int y2, string c) : Line(x1, y1, x2, y2)
    {
        type = "Цветная линия";
        color = c;
    }
    void setColoredLine(int x1, int y1, int x2, int y2, string c)
    {
        setLine(x1, y1, x2, y2);
        color = c;
    }

    void setColor(string c) { color = c; }
    string getLineColor() { return color; }

    void output() override
    {
        Line::output();
        cout << "Цвет: " << color << endl;
    }
    void changeCharc() override
    {
        cout << "Первая точка: " << endl;
        cout << "Х = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;
        cout << endl;
        cout << "Вторая точка: " << endl;
        cout << "Х = ";
        cin >> endx;
        cout << "Y = ";
        cin >> endy;
        cout << "Цвет: ";
        cin >> color;
    }
};
class PolyLine : public Line
{
protected:
    Line *l[100];
    int sizePoly;

public:
    PolyLine()
    {
        type = "Многоугольник";

        l[0] = new Line(1, 1, 4, 2);
        l[1] = new Line(4, 2, 3, 8);
        l[2] = new Line(3, 8, 2, 1);
        l[3] = new Line(2, 1, 4, 6);
        l[4] = new Line(4, 6, 1, 1);

        sizePoly = 5;
    }
    PolyLine(int sizeN)
    {
        sizePoly = sizeN;
        type = "\nМногоугольник";
        changeCharc();
    }
    void changeCharc()
    {
        int tempX1, tempY1, tempX2, tempY2;
        cout << "Введите точки для многоугольника: " << endl;
        for (int i = 0; i < sizePoly; i++)
        {
            if (i == 0)
            {
                cout << "X(" << i + 1 << ") = ";
                cin >> tempX1;
                cout << "Y(" << i + 1 << ") = ";
                cin >> tempY1;
            }
            else
            {
                tempX1 = tempX2;
                tempY1 = tempY2;
            }

            if (i == sizePoly - 1)
            {
                tempX1 = l[i - 1]->getEndX();
                tempY1 = l[i - 1]->getEndY();
                tempX2 = l[0]->getX();
                tempY2 = l[0]->getY();
            }
            else
            {
                cout << "X(" << i + 2 << ") = ";
                cin >> tempX2;
                cout << "Y(" << i + 2 << ") = ";
                cin >> tempY2;
            }
            l[i] = new Line(tempX1, tempY1, tempX2, tempY2);
        }
    }
    void output() override
    {
        cout << type << " с точками:" << endl;
        for (int i = 0; i < sizePoly; i++)
        {
            l[i]->output(i + 1);
        }
    }
};

class Picture
{
    int n;
    Point *arr[4];

public:
    Picture()
    {
        n = 4;
        arr[0] = new ColoredPoint(1, 1, "green");
        arr[1] = new Line(1, 3, 8, 7);
        arr[2] = new ColoredLine(4, 1, 6, 8, "black");
        arr[3] = new PolyLine(5);
        cout << "Инициализация прошла успешно!" << endl;
    }
    void PictureInfo()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i]->output();
        }
    }
    void ChangeCharc()
    {
        int i;
        cout << "\n\n0 - Цветная точка\n1 - Линия\n2 - Цветная линия\n3 - Многоугольник\n";
        cout << "Введите номер элемента, который вы хотите изменить: ";
        cin >> i;
        arr[i]->changeCharc();
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");

    Picture p;
    cout << "Данные о фотографии:" << endl;
    p.PictureInfo();
    p.ChangeCharc();
    p.PictureInfo();

    return 0;
}