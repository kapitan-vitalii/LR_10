#include <iostream>
#include <iomanip>
using namespace std;
//функція створення матриці
int** create(int r, int s) {
	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[s];
	return arr;
}
//Функція ітіціалізації матриці
void init_matr(int** arr, int r, int s) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			arr[i][j] = rand() % 101 - 50;
}
//Функція виведення матриці на екран
void print_matr(int** arr, int r, int s) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++)
			cout << setw(5) << arr[i][j];
		cout << endl;
	}
}
//функція вилучення матриці з ОП
void del_matr(int** arr, int r) {
	for (int i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
}
