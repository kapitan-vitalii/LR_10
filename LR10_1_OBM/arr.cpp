#include <iostream>
#include <iomanip>

using namespace std;

int* create_arr(int n)
{
	int* arr = new int[n];
	return arr;
}

void del_arr(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void init_arr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 201 - 100;
}

double* create_double_arr(int n)
{
	double* arr = new double[n];
	return arr;
}

void del_double_arr(double*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void print_arr(int* arr, int n, const char* title)
{
	cout << title << ":\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void print_double_arr(double* arr, int n, const char* title)
{
	cout << title << ":\n";
	for (int i = 0; i < n; i++)
		cout << fixed << setprecision(1) << setw(5) << arr[i] << " ";
	cout << endl;
}

int max_arr(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

int min_arr(int* arr, int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

void max_min_indecies(int* arr, int n, int*& indexMin, int& minCount, int*& indexMax, int& maxCount)
{
	int maxNum = max_arr(arr, n), minNum = min_arr(arr, n), mi = 0, ma = 0;
	minCount = 0, maxCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == maxNum)
			maxCount++;
		if (arr[i] == minNum)
			minCount++;
	}

	indexMax = create_arr(maxCount);
	indexMin = create_arr(minCount);

	for (int i = 0; i < n; i++) {
		if (arr[i] == maxNum)
			indexMax[ma++] = i + 1;
		if (arr[i] == minNum)
			indexMin[mi++] = i + 1;
	}
}

int* negatives_arr(int* arr, int n, int& negCount)
{
	int* neg, ng = 0;
	negCount = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			negCount++;

	neg = create_arr(negCount);

	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			neg[ng++] = arr[i];

	return neg;
}

double avr_arr(int* arr, int n)
{
	double avr = 0;

	for (int i = 0; i < n; i++)
		avr += arr[i];
	avr /= n;

	return avr;
}

double* avr_neg_cols(int** matr, int rows, int cols)
{
	double* avr_cols;
	int col_neg_count = 0;
	avr_cols = create_double_arr(cols);
	for (int i = 0; i < cols; i++) {
		avr_cols[i] = 0;
		for (int j = 0; j < rows; j++)
			if (matr[j][i] < 0)
			{
				col_neg_count++;
				avr_cols[i] += matr[j][i];
			}
		if (col_neg_count > 0)
			avr_cols[i] /= col_neg_count;

		col_neg_count = 0;
	}

	return avr_cols;
}