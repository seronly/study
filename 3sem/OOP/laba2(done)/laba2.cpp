#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <Windows.h>
#include <locale>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
struct Staffs
{
	char surname[20], name[20], patrname[20];
	char pos[20];
	int year;
	float zarpl;
} sf;
struct Staffs person[100];
struct Staffs temp;
int counter = 0; //глобальная переменная - счетчик

int menu()
{
	system("cls");
	int enter;
	cout << "\t\tМеню" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Добавление сотрудника" << endl;
	cout << "2. Сортировка списка сотрудников по фамилии" << endl;
	cout << "3. Поиск сотрудников по фамилии" << endl;
	cout << "4. Изменение данных о сотруднике" << endl;
	cout << "5. Удаление данных о сотруднике" << endl;
	cout << "6. Вывод на экран список сотрудников" << endl;
	cout << "7. Выход" << endl;
	cin >> enter;
	return enter;
}

void input()
{
	system("cls");
	if (counter < 100)
	{
		cout << "Сотрудник №" << counter + 1 << endl;
		cout << "Введите фамилию сотрудника: ";
		cin >> person[counter].surname;
		cout << "Введите имя сотрудника: ";
		cin >> person[counter].name;
		cout << "Введите отчество сотрудника: ";
		cin >> person[counter].patrname;
		cout << "Введите должность сотрудника: ";
		cin >> person[counter].pos;
		cout << "Введите год рождения сотрудника: ";
		cin >> person[counter].year;
		cout << "Введите зарплату сотрудника: ";
		cin >> person[counter].zarpl;
		counter++;
	}
	else
		cout << "Добавлено максимальное кол-во сотрудников!" << endl;
	system("pause");
}

void sort()
{
	system("cls");
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = i + 1; j < counter; j++)
		{
			if (strcmp(person[i].surname, person[j].surname) > 0)
			{
				temp = person[i];
				person[i] = person[j];
				person[j] = temp;
			}
		}
	}
	cout << "Сортировка прошла успешно!\n";
	system("pause");
}

void find()
{
	system("cls");
	char fs[20];
	bool check = true;
	if (!counter)
	{
		cout << "Список пуст!" << endl;
		system("pause");
		return;
	}
	cout << "Введите фамилию сотрудника: ";
	cin >> fs;

	for (int i = 0; i < counter; i++)
	{
		if (strcmp((*(person + i)).surname, fs) == 0)
		{
			cout << i + 1 << ". "
				 << (*(person + i)).surname << " "
				 << (*(person + i)).name << " "
				 << (*(person + i)).patrname << " "
				 << "Должность: " << (*(person + i)).pos << " "
				 << (*(person + i)).year << " г. "
				 << "З/п: " << (*(person + i)).zarpl << endl;
			check = false;
		}
	}
	if (check)
	{
		cout << "Ничего не найдено!" << endl;
	}
	system("pause");
}

void change()
{
	system("cls");
	int num;
	int check;
	cout << "Введите номер сотрудника: ";
	cin >> num;
	do
	{
		system("cls");
		cout << person[num - 1].surname << " " << person[num - 1].name << " " << person[num - 1].patrname << " "
			 << "Должность: " << person[num - 1].pos << " " << person[num - 1].year << "г. "
			 << "З/п: " << person[num - 1].zarpl << " руб."
			 << endl;
		cout << "-------------------------------------------" << endl;
		cout << "\t\tИзменить" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Фамилию сотрудника" << endl;
		cout << "2. Имя сотрудника" << endl;
		cout << "3. Отчество сотрудника" << endl;
		cout << "4. Должность сотрудника" << endl;
		cout << "5. Год рождения сотрудника" << endl;
		cout << "6. Зарплату сотрудника" << endl;
		cout << "7. Выход" << endl;
		cin >> check;
		switch (check)
		{
		case 1:
			cout << "Введите фамилию сотрудника: ";
			cin >> person[num - 1].surname;
			break;
		case 2:
			cout << "Введите имя сотрудника: ";
			cin >> person[num - 1].name;
			break;
		case 3:
			cout << "Введите отчество сотрудника: ";
			cin >> person[num - 1].patrname;
			break;
		case 4:
			cout << "Введите должность сотрудника: ";
			cin >> person[num - 1].pos;
			break;
		case 5:
			cout << "Введите год рождения сотрудника: ";
			cin >> person[num - 1].year;
			break;
		case 6:
			cout << "Введите зарплату сотрудника: ";
			cin >> person[num - 1].zarpl;
			break;
		case 7:
			system("pause");
			return;
		default:
			cout << "Не верный запрос.\n";
		}
	} while (true);
	system("pause");
}

void del()
{
	system("cls");
	int num;
	cout << "Введите номер сотрудника, данные о котором нужно удалить: ";
	cin >> num;
	for (int i = (num - 1); i < counter; i++)
	{
		person[i] = person[i + 1];
	}
	counter--;
	cout << "Данные успешно удалены!\nСотрудников: " << counter;
}

void output()
{
	system("cls");
	if (counter == 0)
	{
		cout << "Список сотрудников пуст!" << endl;
		system("pause");
		return;
	}
	cout << "Список сотрудников: " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << i + 1 << ". "
			 << person[i].surname << " "
			 << person[i].name << " "
			 << person[i].patrname << " "
			 << "Должность: " << person[i].pos << " "
			 << person[i].year << "г. "
			 << "З/п: " << person[i].zarpl << " руб." << endl;
	}
	system("pause");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		switch (menu())
		{
		case 1:
			input();
			break;
		case 2:
			sort();
			break;
		case 3:
			find();
			break;
		case 4:
			change();
			break;
		case 5:
			del();
			break;
		case 6:
			output();
			break;
		case 7:
			return 0;
		default:
			cout << "Не верный запрос.\n";
		}
	}

	return 0;
}