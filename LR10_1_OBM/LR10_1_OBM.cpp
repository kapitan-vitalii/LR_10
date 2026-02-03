#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include "matr.h"
#include "arr.h"

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int rows = 0, cols = 0, negCount, b = 1,
		* neg,
		** matr;
	double* avrCols;

	while (rows < 1 || cols < 1)
	{
		cout << "Введіть розмір (рядки стовпці):\n";
		cin >> rows >> cols;
	}

	matr = create_matr(rows, cols);
	init_matr(matr, rows, cols);

	while (b)
		switch (menu())
		{
		case 0:
			b = 0;
			break;
		case 1:
			init_matr(matr, rows, cols);
			break;
		case 2:
			print_matr(matr, rows, cols, "Матриця");
			break;
		case 3:
			cout << "Максимум:\n" << max_matr(matr, rows, cols);
			break;
		case 4:
			cout << "Мінімум:\n" << min_matr(matr, rows, cols);
			break;
		case 5:
			cout << "Середнє значення:\n" << avr_matr(matr, rows, cols);
			break;
		case 6:
			avrCols = avr_neg_cols(matr, rows, cols);
			print_double_arr(avrCols, cols, "Середнє по стовпцях");
			del_double_arr(avrCols);
			break;
		case 7:
			neg = negatives_matr(matr, rows, cols, negCount);
			print_arr(neg, negCount, "Від'ємні");
			del_arr(neg);
			break;
		default:
			cout << "Некоректне значення!\n";
			break;
		}

	del_matr(matr, rows);
}