#ifndef Zakharenko_H
#define Zakharenko_H
#include "Shevko.h"

using namespace std;

int Area(int a, int b);
double Cost_Brutto(int a, int b, Mater& mater);
double Count_By_Mater(Mater& mater, Chokhol& chokhol);
double Final_Cost(Mater& mater, double materialPrice);
void sortFileByMaterial(const char* fileName);

int S, a, b, kilkist;
double materialPrice;

fstream txt;

int Area(int a, int b) {

	cout << "Введіть довжину розрізу: ";
	cin >> a;
	cout << "Введіть ширину розрізу: ";
	cin >> b;

// шов
	a++;
	b++;
// площа
	S = a * b;
	cout << "Площа розрізу зі швом = " << S;
    txt.open("result.txt", ios::out);
    txt << "Площа розрізу зі швом = " << S;
    txt.close();
	return S;
}

double Cost_Brutto(int a, int b, Mater& mater) {
	materialPrice = S * mater.cost;
	cout << "Собівартість на виготовлення матеріалів = " << materialPrice;
    txt.open("result.txt", ios::out);
    txt << "Собівартість на виготовлення матеріалів = " << materialPrice;
    txt.close();
	return materialPrice;
}

double Count_By_Mater(Mater& mater, Chokhol& chokhol) {
    kilkist = mater.count / chokhol.mater;
    cout << "Кількість чехлів з вказаного матеріалу = " << kilkist;
    txt.open("result.txt", ios::out);
    txt << "Кількість чехлів з вказаного матеріалу = " << kilkist;
    txt.close();
	return kilkist;
}

double Final_Cost(Mater& mater, double materialPrice) {
	const double amortization = 13.567 / 100.0;
	const double profit = 10.0 / 100.0;        

	double costWithAmort = materialPrice * (1 + amortization);
	double finalPrice = costWithAmort * (1 + profit);

    cout << "Фінальна ціна = " << finalPrice;
    txt.open("result.txt", ios::out);
    txt << "Фінальна ціна = " << finalPrice;
    txt.close();

	return finalPrice;
}


void sortFileByMaterial(const char* fileName)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile)
    {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    inFile.seekg(0, ios::end);
    int count = inFile.tellg() / sizeof(Mater);
    inFile.seekg(0, ios::beg);

    Mater* mas = new Mater[count];

    for (int i = 0; i < count; i++)
    {
        inFile.read((char*)&mas[i], sizeof(Mater));
    }
    inFile.close();

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(mas[j].mater, mas[j + 1].mater) > 0)
            {
                Mater temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    ofstream outFile(fileName, ios::binary | ios::trunc);
    for (int i = 0; i < count; i++)
    {
        outFile.write((char*)&mas[i], sizeof(Mater));
    }
    outFile.close();

    delete[] mas;
}

#endif