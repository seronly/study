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
int counter = 0; //���������� ���������� - �������

int menu()
{
	system("cls");
	int enter;
	cout << "\t\t����" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. ���������� ����������" << endl;
	cout << "2. ���������� ������ ����������� �� �������" << endl;
	cout << "3. ����� ����������� �� �������" << endl;
	cout << "4. ��������� ������ � ����������" << endl;
	cout << "5. �������� ������ � ����������" << endl;
	cout << "6. ����� �� ����� ������ �����������" << endl;
	cout << "7. �����" << endl;
	cin >> enter;
	return enter;
}

void input()
{
	system("cls");
	if (counter < 100)
	{
		cout << "��������� �" << counter + 1 << endl;
		cout << "������� ������� ����������: ";
		cin >> person[counter].surname;
		cout << "������� ��� ����������: ";
		cin >> person[counter].name;
		cout << "������� �������� ����������: ";
		cin >> person[counter].patrname;
		cout << "������� ��������� ����������: ";
		cin >> person[counter].pos;
		cout << "������� ��� �������� ����������: ";
		cin >> person[counter].year;
		cout << "������� �������� ����������: ";
		cin >> person[counter].zarpl;
		counter++;
	}
	else
		cout << "��������� ������������ ���-�� �����������!" << endl;
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
	cout << "���������� ������ �������!\n";
	system("pause");
}

void find()
{
	system("cls");
	char fs[20];
	bool check = true;
	if (!counter)
	{
		cout << "������ ����!" << endl;
		system("pause");
		return;
	}
	cout << "������� ������� ����������: ";
	cin >> fs;

	for (int i = 0; i < counter; i++)
	{
		if (strcmp((*(person + i)).surname, fs) == 0)
		{
			cout << i + 1 << ". "
				 << (*(person + i)).surname << " "
				 << (*(person + i)).name << " "
				 << (*(person + i)).patrname << " "
				 << "���������: " << (*(person + i)).pos << " "
				 << (*(person + i)).year << " �. "
				 << "�/�: " << (*(person + i)).zarpl << endl;
			check = false;
		}
	}
	if (check)
	{
		cout << "������ �� �������!" << endl;
	}
	system("pause");
}

void change()
{
	system("cls");
	int num;
	int check;
	cout << "������� ����� ����������: ";
	cin >> num;
	do
	{
		system("cls");
		cout << person[num - 1].surname << " " << person[num - 1].name << " " << person[num - 1].patrname << " "
			 << "���������: " << person[num - 1].pos << " " << person[num - 1].year << "�. "
			 << "�/�: " << person[num - 1].zarpl << " ���."
			 << endl;
		cout << "-------------------------------------------" << endl;
		cout << "\t\t��������" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. ������� ����������" << endl;
		cout << "2. ��� ����������" << endl;
		cout << "3. �������� ����������" << endl;
		cout << "4. ��������� ����������" << endl;
		cout << "5. ��� �������� ����������" << endl;
		cout << "6. �������� ����������" << endl;
		cout << "7. �����" << endl;
		cin >> check;
		switch (check)
		{
		case 1:
			cout << "������� ������� ����������: ";
			cin >> person[num - 1].surname;
			break;
		case 2:
			cout << "������� ��� ����������: ";
			cin >> person[num - 1].name;
			break;
		case 3:
			cout << "������� �������� ����������: ";
			cin >> person[num - 1].patrname;
			break;
		case 4:
			cout << "������� ��������� ����������: ";
			cin >> person[num - 1].pos;
			break;
		case 5:
			cout << "������� ��� �������� ����������: ";
			cin >> person[num - 1].year;
			break;
		case 6:
			cout << "������� �������� ����������: ";
			cin >> person[num - 1].zarpl;
			break;
		case 7:
			system("pause");
			return;
		default:
			cout << "�� ������ ������.\n";
		}
	} while (true);
	system("pause");
}

void del()
{
	system("cls");
	int num;
	cout << "������� ����� ����������, ������ � ������� ����� �������: ";
	cin >> num;
	for (int i = (num - 1); i < counter; i++)
	{
		person[i] = person[i + 1];
	}
	counter--;
	cout << "������ ������� �������!\n�����������: " << counter;
}

void output()
{
	system("cls");
	if (counter == 0)
	{
		cout << "������ ����������� ����!" << endl;
		system("pause");
		return;
	}
	cout << "������ �����������: " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << i + 1 << ". "
			 << person[i].surname << " "
			 << person[i].name << " "
			 << person[i].patrname << " "
			 << "���������: " << person[i].pos << " "
			 << person[i].year << "�. "
			 << "�/�: " << person[i].zarpl << " ���." << endl;
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
			cout << "�� ������ ������.\n";
		}
	}

	return 0;
}