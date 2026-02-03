#pragma once

int* create_arr(int n);
int* negatives_arr(int* arr, int n, int& negCount);
int* negatives_arr(int* arr, int n, int& negCount);

int max_arr(int* arr, int n);
int min_arr(int* arr, int n);

double* create_double_arr(int n);
double* avr_neg_cols(int** matr, int rows, int cols);

double avr_arr(int* arr, int n);

void init_arr(int* arr, int n);
void print_arr(int* arr, int n, const char* title);
void print_double_arr(double* arr, int n, const char* title);
void max_min_indecies(int* arr, int n, int*& indexMin, int& minCount, int*& indexMax, int& maxCount);
void del_double_arr(double*& arr);
void del_arr(int*& arr);