#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

template <typename T>
class Node
{
public:
    Node *pNext;
    T data;
    Node(T data = T(), Node *pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

template <typename T>
class List
{
public:
    List();
    ~List();

    void Delete_front();

    List<T> &operator+(T data);

    void Clear();

    int GetSize() { return Size; }

    T &operator[](const int index);

    void New_front(T data);

    void Insert(T data, int index);

    void RemoveAt(int index);

    void Delete_back();

    void Print();

    void DelE(List<T> &l, T item);

private:
    int Size;
    Node<T> *head;
};

template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
    Clear();
}

template <typename T>
void List<T>::Delete_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template <typename T>
void List<T>::Delete_back()
{
    RemoveAt(Size - 1);
}

template <typename T>
void List<T>::RemoveAt(int index)
{
    if (index == 0)
        Delete_front();
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->pNext;
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template <typename T>
List<T> &List<T>::operator+(T data)
{
    if (head == nullptr)
        head = new Node<T>(data);
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = new Node<T>(data);
    }
    Size++;
    return *this;
}

template <typename T>
void List<T>::New_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void List<T>::Insert(T data, int index)
{
    if (index == 0)
        New_front(data);
    else
    {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; i++)
            previous = previous->pNext;
        Node<T> *newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template <typename T>
void List<T>::Clear()
{
    while (Size)
        Delete_front();
}

template <typename T>
T &List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
            return current->data;
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::Print()
{
    for (int i = 0; i < GetSize(); i++)
        cout << operator[](i) << " ";
    cout << endl;
}

template <typename T>
void List<T>::DelE(List<T> &l, T item)
{
    if (GetSize() == 0)
        return;

    for (int i = 0; i < GetSize(); i++)
    {
        if (l[i] == item && l[i + 1] && l[i + 1] != item)
        {
            RemoveAt(i + 1);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    system("chcp 65001");
    system("cls");
    List<int> L;
    L + 2 + 6 + 9 + 1 + 3 + 2 + 6;
    L.Print();
    L.DelE(L, 1);
    L.Print();

    return 0;
}