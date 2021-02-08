#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdlib>

using namespace std;

struct Date
{
	int Year;
	int Month;
	int Day;
};
// ------------------------------------------------------------
void func(Date Today)
{
	int temp;
	if ((Today.Month == 3) || (Today.Month == 5) || (Today.Month == 7) || (Today.Month == 8) || (Today.Month == 10) || (Today.Month == 12))
		temp = 1;
	if ((Today.Month == 6) || (Today.Month == 9) || (Today.Month == 11))
		temp = 4;

	cout << "\nВыбрана дата: " << Today.Day << "." << Today.Month << "." << Today.Year << endl;

	switch (temp)
	{
	case 1:
		cout << "Дней до конца месяца: " << 31 - Today.Day;
		break;
	case 2:
		cout << "Дней до конца месяца: " << 28 - Today.Day;
		break;
	case 4:
		cout << "Дней до конца месяца: " << 30 - Today.Day;
		break;
	}
}
// ------------------------------------------------------------
void func(int D, int M)
{
	struct Date Today;

	Today.Year = 2019;
	Today.Day = D;
	Today.Month = M;

	if ((Today.Month == 3) || (Today.Month == 5) || (Today.Month == 7) || (Today.Month == 8) || (Today.Month == 10) || (Today.Month == 12))
		M = 1;
	if ((Today.Month == 6) || (Today.Month == 9) || (Today.Month == 11))
		M = 4;

	cout << "\nВыбрана дата: " << Today.Day << "." << Today.Month << "." << Today.Year << endl;

	switch (M)
	{
	case 1:
		cout << "Дней до конца месяца: " << 31 - D;
		break;
	case 2:
		cout << "Дней до конца месяца: " << 28 - D;
		break;
	case 4:
		cout << "Дней до конца месяца: " << 30 - D;
		break;
	}
}

void func(int D, int M, int Y)
{
	struct Date Today;

	Today.Year = Y;
	Today.Day = D;
	Today.Month = M;

	if ((Today.Month == 3) || (Today.Month == 5) || (Today.Month == 7) || (Today.Month == 8) || (Today.Month == 10) || (Today.Month == 12))
		M = 1;
	if ((Today.Month == 6) || (Today.Month == 9) || (Today.Month == 11))
		M = 4;

	cout << "\nВыбрана дата: " << Today.Day << "." << Today.Month << "." << Today.Year << endl;

	switch (M)
	{
	case 1:
		cout << "Дней до конца месяца: " << 31 - D;
		break;
	case 2:
		if (Y % 4 == 0)
			cout << "Дней до конца месяца: " << 29 - D;
		else
			cout << "Дней до конца месяца: " << 28 - D;
		break;
	case 4:
		cout << "Дней до конца месяца: " << 30 - D << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	// ------------------------------------------------------------
	Date data;
	data.Day = 25;
	data.Month = 8;
	data.Year = 2001;
	func(data);
	// ------------------------------------------------------------

	int N, D, M, Y;

menu:
	cout << "(!) Выберите нобор данных для обработки...\n1. День.Месяц.Год\n2. День.Месяц\n3. Выход\n";
	N = _getch();
	if (N == 51)
		exit(0);
	if ((N != 49) && (N != 50) && (N != 51))
	{
		system("cls");
		cout << "(!!) Некоректный ввод (!!)\n\n";
		goto menu;
	}
	system("cls");
	cout << "Введите данные..\n"
		 << "Число: ";
	cin >> D;
	cout << "Выберите месяц:\n1.  Январь\n2.  Февраль\n3.  Март\n4.  Апрель\n5.  Май\n6.  Июнь\n7.  Июль\n8.  Август\n9.  Сентябрь\n10. Октябрь\n11. Ноябрь\n12. Декабрь\nВаш выбор >>> ";
	cin >> M;

	switch (N)
	{
	case 49:
	{
		cout << "\nГод: ";
		cin >> Y;
		func(D, M, Y);
	}
	break;
	case 50:
		func(D, M);
		break;
	}
	_getch();
	system("cls");
	goto menu;

	system("pause");

	return 0;
}
