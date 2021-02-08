#include <iostream>
#include <string>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int *ArreyIst1(int *massiv1)
{
	bool F1, A = false, B = false, C = false, D = false;
	int m = 0, massiv[16];

	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
		{
			for (unsigned int k = 0; k < 2; k++)
			{
				for (unsigned int n = 0; n < 2; n++)
				{
					F1 = A;
					if (F1 == true)
					{
						massiv1[m] = 1;
						m++;
					}
					else
					{
						massiv1[m] = 0;
						m++;
					}
					D = !D;
				}
				C = !C;
			}
			B = !B;
		}
		A = !A;
	}

	cout << "F1: [ ";
	for (unsigned int i = 0; i < 16; i++)
		cout << massiv1[i] << " ";
	cout << "]\n";

	return (massiv1);
}

int *ArreyIst2(int *massiv2)
{
	bool F2, A = false, B = false, C = false, D = false;
	int m = 0, massiv[16];

	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
		{
			for (unsigned int k = 0; k < 2; k++)
			{
				for (unsigned int n = 0; n < 2; n++)
				{
					F2 = !A * !B * D + A * B * !D + A * C;
					if (F2 == true)
					{
						massiv2[m] = 1;
						m++;
					}
					else
					{
						massiv2[m] = 0;
						m++;
					}
					D = !D;
				}
				C = !C;
			}
			B = !B;
		}
		A = !A;
	}

	cout << "F2: [ ";
	for (unsigned int i = 0; i < 16; i++)
		cout << massiv2[i] << " ";
	cout << "]\n";

	return (massiv2);
}

int *ArreyIst3(int *massiv3)
{
	bool F3, A = false, B = false, C = false, D = false;
	int m = 0;

	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
		{
			for (unsigned int k = 0; k < 2; k++)
			{
				for (unsigned int n = 0; n < 2; n++)
				{
					F3 = !A * !B * !C * !D + !A * !B * !C * D + !A * B * !C * !D + !A * B * C * D + A * !B * C * !D;
					if (F3 == true)
					{
						massiv3[m] = 1;
						m++;
					}
					else
					{
						massiv3[m] = 0;
						m++;
					}
					D = !D;
				}
				C = !C;
			}
			B = !B;
		}
		A = !A;
	}

	cout << "F3: [ ";
	for (unsigned int i = 0; i < 16; i++)
		cout << massiv3[i] << " ";
	cout << "]\n";

	return (massiv3);
}

int SaveNULL(int *massiv)
{
	int n = 1;

	if (massiv[0] == 1)
		n = 0;
	return (n);
}

int SaveONE(int *massiv)
{
	int n = 1;

	if (massiv[15] == 1)
		n = 1;
	else
		n *= 0;
	return (n);
}

int Mono(int *massiv)
{
	int n = 1;
	for (int i = 0; i < 15; i++)
	{
		if (massiv[i] <= massiv[i + 1])
			n *= 1;
		else
			n *= 0;
	}
	return (n);
}

int Samdv(int *massiv)
{
	int n = 1, m = 15;

	for (int i = 0; i < 8; i++)
	{
		if (massiv[i] == massiv[i + m])
		{
			m -= 2;
		}
		else
		{
			n *= 0;
			m -= 2;
		}
	}
	return n;
}

int Line(int *massiv)
{
	int n = 1, i, j = 1, Pasc[16];

	for (i = 0; i < 16; i++)
		Pasc[i] = massiv[i];

	for (j = 1; j < 16; j++)
	{
		for (i = 0; i < 16 - j; i++)
		{
			if (Pasc[i] != Pasc[i + 1])
				Pasc[i + 1] = 1;
			else
				Pasc[i + 1] = 1;
		}
	}
	for (i = 0; i < 16; i++)
	{
		if ((Pasc[i] == 1) && ((i == 0) || (i == 1) || (i == 2) || (i == 4) || (i == 8)))
			n *= 1;
		else
			n *= 0;
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "65001");
	system("chcp 65001");
	system("cls");
	bool A = false, B = false, C = false, D = false;
	int i, T0 = 1, T1 = 1, Tl = 1, Ts = 1, Tm = 1, massiv1[16], m, massiv2[16], massiv3[16], itog;

	cout << "Дана система:\n";
	cout << "F1 = A\n";
	cout << "F2 = !A*!B*D + A*B*!D + A*C\n";
	cout << "F3 = !A*!B*!C*!D + !A*!B*!C*D + !A*B*!C*!D + !A*B*C*D + A*!B*C*!D\n\n";
	cout << "Ряды истинности для функций:\n";

	ArreyIst1(massiv1);
	ArreyIst2(massiv2);
	ArreyIst3(massiv3);

	Tm *= Mono(massiv1);
	T0 *= SaveNULL(massiv1);
	T1 *= SaveONE(massiv1);
	Ts *= Samdv(massiv1);
	Tl *= Line(massiv1);

	T0 *= SaveNULL(massiv2);
	T1 *= SaveONE(massiv2);
	Tm *= Mono(massiv2);
	Ts *= Samdv(massiv2);
	Tl *= Line(massiv2);

	T1 *= SaveONE(massiv3);
	Tm *= Mono(massiv3);
	T0 *= SaveNULL(massiv3);
	Ts *= Samdv(massiv3);
	Tl *= Line(massiv3);

	cout << "\n\nПроверка теоремы Поста:\n";
	cout << "\n|    | T0 | T1 | Tm | Tl | Ts |";
	cout << "\n| F1 |  " << SaveNULL(massiv1) << " |  " << SaveONE(massiv1) << " |  " << Mono(massiv1) << " |  " << Line(massiv1) << " |  " << Samdv(massiv1) << " |";
	cout << "\n| F2 |  " << SaveNULL(massiv2) << " |  " << SaveONE(massiv2) << " |  " << Mono(massiv2) << " |  " << Line(massiv2) << " |  " << Samdv(massiv2) << " |";
	cout << "\n| F3 |  " << SaveNULL(massiv3) << " |  " << SaveONE(massiv3) << " |  " << Mono(massiv3) << " |  " << Line(massiv3) << " |  " << Samdv(massiv3) << " |";
	cout << "\n\n|Итог|  " << T0 << " |  " << T1 << " |  " << Tm << " |  " << Tl << " |  " << Ts << " |\n\n";

	itog = T0 + T1 + Tl + Tm + Ts;

	if (itog != 0)
		cout << "\n(!) Система функционатьно не полная\n\n";
	else
		cout << "\n(!) Система функционально полная\n\n";

	system("pause");
	return 0;
}