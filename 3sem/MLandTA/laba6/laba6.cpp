#include <iostream>
#include <string>
#include <locale.h>
#include <stdlib.h>

using namespace std;

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

	if (massiv[16] == 1)
		n = 1;
	return (n);
}

int *GetF1(int *massiv1)
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
	return (massiv1);
}

int *GetF2(int *massiv2)
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
	return (massiv2);
}

int *GetF3(int *massiv3)
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
					F3 = !A * !B * !C * !D + !A * !B * !C * D + !A * B * !C * !D + !A * B * C * D + A + !B + C + !D;
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
	return (massiv3);
}

int Mono(int *massiv)
{
	int n = 1;
	for (int i = 0; i < 15; i++)
	{
		if (massiv[i + 1] < massiv[i])
		{
			n *= 0;
		}
	}
	return (n);
}

int Samdv(int *massiv)
{
	int n = 1, m = 15;

	for (int i = 0; i < 8; i++)
	{
		if (massiv[i] != massiv[i + m])
		{
			m -= 2;
		}
		else
		{
			n = n * 0;
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
				Pasc[i + 1] = 0;
		}
	}
	for (i = 0; i < 16; i++)
	{
		if ((Pasc[i] == 1) && ((i == 0) || (i == 1) || (i == 2) || (i == 4) || (i == 8)))
			n *= 1;
		else
		{
			if (Pasc[i] == 1)
			{
				n *= 0;
			}
		}
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "65001");
	system("chcp 65001");
	system("cls");
	bool F1, F2, F3, A = false, B = false, C = false, D = false, Post = true;
	int i, massiv1[16], massiv2[16], massiv3[16];
	int check1[5], check2[5], check3[5];

	F1 = A * B * C * !D + !A * B * C * D + A * D;
	F2 = !A * !B * D + A * B * !D + A * C;
	F3 = (0, 1, 4, 7, 10);

	GetF1(massiv1);
	GetF2(massiv2);
	GetF3(massiv3);

	check1[0] = Mono(massiv1);
	check2[0] = Mono(massiv2);
	check3[0] = Mono(massiv3);

	check1[1] = SaveNULL(massiv1);
	check2[1] = SaveNULL(massiv2);
	check3[1] = SaveNULL(massiv3);

	check1[2] = SaveONE(massiv1);
	check2[2] = SaveONE(massiv2);
	check3[2] = SaveONE(massiv3);

	check1[3] = Samdv(massiv1);
	check2[3] = Samdv(massiv2);
	check3[3] = Samdv(massiv3);

	check1[4] = Line(massiv1);
	check2[4] = Line(massiv2);
	check3[4] = Line(massiv3);

	// n1 += Mono(massiv1) + SaveNULL(massiv1) + SaveONE(massiv1) + Samdv(massiv1);
	// n2 += Mono(massiv2) + SaveNULL(massiv2) + SaveONE(massiv2) + Samdv(massiv2);
	// n3 += Mono(massiv3) + SaveNULL(massiv3) + SaveONE(massiv3) + Samdv(massiv3);

	// if (n1 <= 1)
	// {
	// 	check1[4] = 1;
	// }
	// else
	// {
	// 	check1[4] = 0;
	// }
	// if (n2 <= 1)
	// {
	// 	check2[4] = 1;
	// }
	// else
	// {
	// 	check2[4] = 0;
	// }
	// if (n3 <= 1)
	// {
	// 	check3[4] = 1;
	// }
	// else
	// {
	// 	check3[4] = 0;
	// }

	cout << "Таблицы истинности для функций:" << endl;
	for (i = 0; i < 16; i++)
	{
		if (i == 0)
			cout
				<< "F1: ";
		cout << massiv1[i] << " ";
	}
	cout << "\n";
	for (i = 0; i < 16; i++)
	{
		if (i == 0)
			cout
				<< "F2: ";
		cout << massiv2[i] << " ";
	}
	cout << "\n";
	for (i = 0; i < 16; i++)
	{
		if (i == 0)
			cout
				<< "F3: ";
		cout << massiv3[i] << " ";
	}
	cout << "\n"
		 << endl;
	cout << "\tM\tT0\tT1\tS\tL\n";
	cout << "F1\t" << check1[0] << "\t" << check1[1] << "\t" << check1[2] << "\t" << check1[3] << "\t" << check1[4] << endl;
	cout << "F2\t" << check2[0] << "\t" << check2[1] << "\t" << check2[2] << "\t" << check2[3] << "\t" << check2[4] << endl;
	cout << "F3\t" << check3[0] << "\t" << check3[1] << "\t" << check3[2] << "\t" << check3[3] << "\t" << check3[4] << endl;

	for (i = 0; i < 5; i++)
	{
		if (check1[i] && check2[i] && check3[i])
		{
			Post *= 0;
		}
		else
		{
			Post *= 1;
		}
	}

	if (Post)
	{
		cout << "\nНабор функций полон." << endl;
	}
	else
	{
		cout << "\nНабор функций не полон." << endl;
	}

	system("pause");
	return 0;
}
