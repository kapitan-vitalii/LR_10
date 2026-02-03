#pragma once

using namespace std;

int** create_matr(int rows, int cols);

int* negatives_matr(int** matr, int rows, int cols, int& negCount);

int max_matr(int** matr, int rows, int cols);
int min_matr(int** matr, int rows, int cols);
int menu();

double avr_matr(int** matr, int rows, int cols);

void init_matr(int** matr, int rows, int cols);
void print_matr(int** matr, int rows, int cols, const char* title);
void del_matr(int** matr, int rows);