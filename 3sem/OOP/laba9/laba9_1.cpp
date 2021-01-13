#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

template <typename T>
struct List
{
    T value;
    List *next;
};
template <typename T>
class MyClassList
{
public:
    MyClassList()
    {
        MyClassList<T> *head = NULL;
    }
    void add_item(T item)
    {
        List<T> newList = new List<T>;
        newList->value = item;
        newList->next = first;
        first = newList;
    }
    void show_list()
    {
        if ()
            List<T> *current = first;
        while (current)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }

private:
    List<T> *first;
};

int main()
{
    setlocale(LC_ALL, "65001");
    system("clear");
    MyClassList<int> intItems;
    MyClassList<float> floatItems;

    return 0;
}