#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

template <typename T>
class MyClassList
{
private:
    struct List
    {
        T value;
        List *next;
    };
    List *head, *first;

public:
    MyClassList()
    {
        head->next = NULL;
    }
    void add_to_start(T item)
    {
        List *newList = new List;
        newList->value = item;
        newList->next = first;
        first = newList;
    }
    void add_item(T item)
    {
        List *newList = new List;
        newList->value = item;
    }
    void remove_start()
    {
        List *newList = new List;
        newList = first->next;
        free(first);
    }

    void show_list()
    {
        List *current = first;
        while (current->next != NULL)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    MyClassList<int> intItems;
    MyClassList<float> floatItems;
    intItems.add_item(1);
    intItems.add_item(3);
    floatItems.add_item(2.5);
    cout << "Список Int: \n";
    intItems.show_list();
    cout << "Список Float: \n";
    floatItems.show_list();

    return 0;
}