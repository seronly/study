#include <iostream>
using namespace std;

/*
* односвязный список
* реализация
*/

template <typename T>
class List
{
public:
	List();
	~List();
	// удаление первого элемента в списке
	void Delete_front();
	// добавление элемента в конец списка
	List<T> &operator+(T data);
	// очистить список
	void Clear();
	// получить количество елементов в списке
	int GetSize() { return Size; }
	// перегруженный оператор []
	T &operator[](const int index);
	// добавление элемента в начало списка
	void New_front(T data);
	// добавление элемента в список по указанному индексу
	void Insert(T data, int index);
	// удаление элемента в списке по указанному индексу
	void RemoveAt(int index);
	// удаление последнего элемента в списке
	void Delete_back();
	// печать списка
	// только для стандартных типов!!!
	void Print();
	// заменяет первое вхождение списка l1(если такое есть) на список l2
	// только для стандартных типов!!!
	void Swap(List<T> &l1, List<T> &l2);

private:
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
void List<T>::Swap(List<T> &l1, List<T> &l2)
{
	if (l1.GetSize() == 0)
		return;
	bool temp1 = false, temp2 = true;
	for (int i = 0; i < GetSize() && temp2; i++)
	{
		if (operator[](i) == l1[0])
		{
			temp1 = true;
			for (int j = 1; j < l1.GetSize() && temp1; j++)
				if (operator[](i + j) != l1[j])
					temp1 = false;
			if (temp1)
			{
				for (int j = 0; j < l1.GetSize(); j++)
					RemoveAt(i);
				for (int j = 0; j < l2.GetSize(); j++)
					Insert(l2[j], i + j);
				temp2 = false;
			}
		}
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");
	List<int> L, L1, L2;
	L + 4 + 5 + 4 + 1 + 7 + 5 + 4;
	L1 + 5 + 4;
	L2 + 6 + 6 + 6;
	L.Print();
	cout << "Замена строки '5, 4' на строку  '6, 6, 6'" << endl;
	L.Swap(L1, L2);
	L.Print();
	return 0;
}
