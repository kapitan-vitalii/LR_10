#include <iostream>
#include "matr.h"
#include <iomanip>

using namespace std;
int main()
{
	srand(time(NULL));
	int m, n;
	cout << "ROZMIR: ";
	cin >> m >> n;
	int** arr = create(m, n);
	int** arr2 = create(6, 3);
	init_matr(arr, m, n);
	init_matr(arr2, 6, 3);
	cout << " Masiv 1 :" << endl;
	print_matr(arr, m, n);
	cout << " Masiv 2 :" << endl;
	print_matr(arr2, 6, 3);
	del_matr(arr, m);
	del_matr(arr2, 6);
}
