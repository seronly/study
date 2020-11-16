#include <iostream>
#include <locale>
#include <cassert>
using namespace std;

class Str
{
public:
    string a;
    void operator++(); // в заглавные
    void operator--(); // самое короткое слово в строке
    void show()
    {
        cout << a << endl;
    };
    ~Str()
    {
        cout << "Был вызван деструктор!" << endl;
    }
};
void Str::operator++()
{
    char *toUp = new char[a.length() + 1];
    for (int i = 0; i < a.length() + 1; i++)
    {
        toUp[i] = toupper(a[i]);
    }
    cout << "Все символы в заглавные: " << toUp << endl;
};

void Str::operator--()
{
    cout << "Началосбь нахождение..." << endl;
    bool check = true;
    char *temp = new char[a.length()], *temp_min = new char[a.length()];
    char buf[] = {' ', ',', '.', '!', '?', ':', ';', '"'};
    for (int i = 0; i < a.length() + 1; i++)
    {
        for (int j = 0; j < sizeof(buf); j++)
        {
            if (a[i] == buf[j])
            {
                check = false;
                if ((sizeof(temp) < sizeof(temp_min) || sizeof(temp_min) == 0) && sizeof(temp) > 0)
                {
                    temp_min = temp;
                    cout << "В temp_min было записано " << temp << endl;
                }
            }
        }
        if (check)
        {
            temp += a[i];
            cout << "Временная переменная: " << temp << endl;
        }
        else
        {
            temp = 0;
            check = true;
        }
    }

    cout << "Самое короткое слово: " << temp_min << endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Str A, B, C;
    A.a = "Hello, my world!";
    B = A;
    B.show();
    ++B;
    C = A;
    --C;

    return 0;
}
