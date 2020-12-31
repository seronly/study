#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string P;
    bool checkIn = true; // булевая переменная для проверки символов
    cout << "A = {a, b, c}" << endl;
    cout << "Введите P слово: ";
    cin >> P;
    cout << endl;
    // проверка символов
    for (int i = 0; i < P.length(); i++)
    {
        if (!(P[i] == 'a' || P[i] == 'b' || P[i] == 'c'))
        {
            cerr << "Введены неверные символы!" << endl; // cerr - тоже самое, что и cout, но для ошибок
            checkIn = false;                             // если находим неверный символ - присваиваем false
            break;
        }
    }

    if (checkIn) // проверяем, были ли в нашем слове лишние символы
    {
        cout << P << endl;
        // если нет, то прибавляем в начале звездочку
        P = "*" + P;
        cout << P << endl;

        while (true) // запускаем бесконечный цикл для проверки символа после *
        {
            if (P[P.find("*") + 1] == 'a')
            {
                // P.find() - возвращает позицию, 2 - сколько символов заменить, "a*" - на что заменить
                P.replace(P.find("*"), 2, "a*"); // заменяем 2 символа ( * и символ после нее)
                cout << P << endl;               // эти cout'ы можешь удалить, они нам нужны были для проверки, но можешь и оставить для наглядности
            }

            if (P[P.find("*") + 1] == 'b')
            {
                P.replace(P.find("*"), 2, "a*");
                cout << P << endl;
            }

            if (P[P.find("*") + 1] == 'c')
            {
                P.replace(P.find("*"), 2, "a*");
                cout << P << endl;
            }
            // проверка конца слова
            if (P[P.find("*") + 1] == '\0')
            {
                P.replace(P.find("*"), 1, ""); // просто заменяем на пустоту
                break;
            }
        }

        cout << "Итог работы НАМ: " << P << endl;
    }
    else
    {
        // если нашли ненужные символы, то выводим на перепроверку (можно этот else удалить - необязателен)
        cout << "Проверьте введенное слово: " << P << endl;
    }

    return 0;
}