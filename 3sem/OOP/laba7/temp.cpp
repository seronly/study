#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
#include <ctime>
using namespace std;
#define MAX 100

class Ex
{
private:
    int a1[MAX];
    float a2[MAX];
    int size_a1 = 0, size_a2 = 0;

public:
    Ex(int size1, int size2);
    ~Ex();

    friend void sort(Ex &mass);
};

Ex::Ex(int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        if (i = 0)
        {
            this->a1[i] = rand();
        }
        else
        {
            this->a1[i] = rand() % (this->a1[i - 1] + 10) + this->a1[i - 1];
        }
    }
    for (int i = 0; i < size2; i++)
    {
        if (i = 0)
        {
            this->a2[i] = rand();
        }
        else
        {
            this->a2[i] = rand() % (int)(this->a2[i - 1] + 10) + (this->a2[i - 1] + 10);
        }
    }
    this->size_a1 = size1;
    this->size_a2 = size2;
};
void sort(Ex &mass)
{
    for (int i = 0; i <)
}
int main()
{
    setlocale(LC_ALL, "65001");
    srand(time(NULL));

    return 0;
}

//========================================================================================================================================================

#include <iostream>
#include <cstdlib>
#include <locale>
#include <cassert>
#include <ctime>
using namespace std;
#define MAX 100

class IntMass;
class FloatMass;

class IntMass
{
private:
    int data[MAX];
    int size;

public:
    IntMass(int msize)
    {
        cout << "Массив Int: ";
        for (int i = 0; i < msize; i++)
        {
            this->data[i] = rand() % 100;
            cout << this->data[i] << " ";
        }
        cout << endl;
        this->size = msize;
    };
    friend void sort(IntMass &massInt, FloatMass &massFloat);
};
class FloatMass
{
private:
    float data[MAX];
    int size;

public:
    FloatMass(int msize)
    {
        cout << "Массив float: ";
        for (int i = 0; i < msize; i++)
        {
            this->data[i] = (float)(rand() % 1000 + 1) / 10;
            cout << this->data[i] << " ";
        }
        cout << endl;
        this->size = msize;
    }
    friend void sort(IntMass &massInt, FloatMass &massFloat);
};

void sort(IntMass &massInt, FloatMass &massFloat)
{
    int temp;
    for (int i = 0; i < massInt.size; i++)
    {
        for (int j = 0; j < massInt.size - 1; j++)
        {
            if (massInt.data[j] > massInt.data[j + 1])
            {
                temp = massInt.data[j];
                massInt.data[j] = massInt.data[j + 1];
                massInt.data[j + 1] = temp;
            }
        }
    }
    float temp;
    for (int i = 0; i < massFloat.size; i++)
    {
        for (int j = 0; j < massFloat.size - 1; j++)
        {
            if (massFloat.data[j] > massFloat.data[j + 1])
            {
                temp = massFloat.data[j];
                massFloat.data[j] = massFloat.data[j + 1];
                massFloat.data[j + 1] = temp;
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "65001");
    srand(time(NULL));
    IntMass a(10);
    FloatMass b(8);
    sort(a, b);

    return 0;
}