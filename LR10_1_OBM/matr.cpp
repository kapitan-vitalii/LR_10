#include <iostream>
#include <iomanip>
#include "arr.h"

using namespace std;

int menu()
{
	int k;
	cout << "\n1 - Заповнити масив знову\n";
	cout << "2 - Вивести масив\n";
	cout << "3 - Максимальне значення\n";
	cout << "4 - Мінімальне значення\n";
	cout << "5 - Середнє арифм. значення\n";
	cout << "6 - Середні значення стовпців\n";
	cout << "7 - Від'ємні значення\n";
	cout << "0 - Вихiд\n";
	cout << "Введiть вибiр:"; cin >> k;
	cout << endl;
	return k;
}

int* negatives_matr(int** matr, int rows, int cols, int& negCount)
{
	int* neg, ng = 0;
	negCount = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matr[i][j] < 0)
				negCount++;

	neg = create_arr(negCount);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matr[i][j] < 0)
				neg[ng++] = matr[i][j];

	return neg;
}

int** create_matr(int rows, int cols)
{
	int** matr = new int* [rows];
	for (int i = 0; i < rows; i++)
		matr[i] = new int[cols];
	return matr;
}

void del_matr(int** matr, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matr[i];
	delete[] matr;
	matr = nullptr;
}

void init_matr(int** matr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matr[i][j] = rand() % 201 - 100;
}

void print_matr(int** matr, int rows, int cols, const char* title)
{
	cout << title << ":\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << setw(5) << matr[i][j] << " ";
		cout << endl;
	}
}

int max_matr(int** matr, int rows, int cols)
{
	int max = matr[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (max < matr[i][j])
				max = matr[i][j];
	return max;
}

int min_matr(int** matr, int rows, int cols)
{
	int min = matr[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (min > matr[i][j])
				min = matr[i][j];
	return min;
}

double avr_matr(int** matr, int rows, int cols)
{
	double avr = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			avr += matr[i][j];
	avr /= (rows * cols);

	return avr;
}

