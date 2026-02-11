#pragma once

#ifndef DATSKYI_H
#define DATSKYI_H

#include "Shevko.h"

void cost_Mater(const char* filename);
double cost_Brutto(double h, double w, double cost);
double area(double h, double w);
void count_by_Mater(const char* filename);
void sortFileByMateria(const char* filename);

//2
void cost_Mater(const char* filename)
{
    Mater mater;
    fstream file, f1;
    double h, w;
    char material[20];
    bool found = false;
    file.open(filename, ios::in | ios::binary);
    f1.open("Log.txt", ios::out | ios::app);
    cout << "Введіть назву матеріалу: ";
    cin.ignore();
    cin.getline(material, 20);

    f1 << "\n\nВведіть назву матеріалу: ";
    f1 << material;

    while (file.read((char*)&mater, sizeof(mater)))
        if (strcmp(mater.mater, material) == 0)
        {
            found = true;
            break;
        }
    if (found)
    {
        cout << "Введіть довжину розрізу: ";
        cin >> h;
        cout << "Введіть ширину розрізу: ";
        cin >> w;
        cout << "Собівартість матеріалів на один чохол: " << cost_Brutto(h, w, mater.cost) << endl;

        f1 << "\nВведіть довжину розрізу: ";
        f1 << h;
        f1 << "\nВведіть ширину розрізу: ";
        f1 << w;
        f1 << "\nСобівартість матеріалів на один чохол: " << cost_Brutto(h, w, mater.cost) << endl;
    }
    else
    {
        cout << "Не знайдено матеріал " << material << ".\n";
        f1 << "\nНе знайдено матеріал " << material << ".\n";
    }

    file.close();
    f1.close();
}

double cost_Brutto(double h, double w, double cost)
{
    double materialPrice = area(h, w) * cost;
    return materialPrice;
}

//3
void count_by_Mater(const char* filename)
{
    Mater mater;
    fstream file, f1;
    char material[20];
    bool found = false;
    double h, w;
    file.open(filename, ios::in | ios::binary);
    f1.open("Log.txt", ios::out | ios::app);

    cout << "Введіть матеріал: ";
    cin.ignore();
    cin.getline(material, 20);
    while (file.read((char*)&mater, sizeof(mater)))
        if (strcmp(mater.mater, material) == 0)
        {
            found = true;
            break;
        }

    if (found)
    {
        cout << "Введіть довжину розрізу: ";
        cin >> h;
        cout << "Введіть ширину розрізу: ";
        cin >> w;
        cout << "З матеріалу " << material << " можна зробити " << mater.count * area(mater.height, mater.width) / area(h, w) << " чохлів";

        f1 << "\n\nВведіть довжину розрізу: ";
        f1 << h;
        f1 << "\nВведіть ширину розрізу: ";
        f1 << w;
        f1 << "\nЗ матеріалу " << material << " можна зробити " << mater.count * area(mater.height, mater.width) / area(h, w) << " чохлів";
    }
    else
    {
        cout << "Не знайдено матеріал " << material << ".\n";
        f1 << "\nНе знайдено матеріал " << material << ".\n";
    }

    file.close();
    f1.close();
}

//6
void sortFileByMateria(const char* filename)
{
    int n = 0;
    fstream file, f1;
    Mater mater;
    file.open(filename, ios::in | ios::binary);
    f1.open("Log.txt", ios::out | ios::app);

    file.clear();
    file.seekg(0, ios::beg);
    while (file.read((char*)&mater, sizeof mater))
        n++;

    if (n == 0) return;

    Mater* arr = new Mater[n];

    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i < n; i++)
        file.read((char*)&arr[i], sizeof Mater);

    Mater buff;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j].mater, arr[j + 1].mater) > 0)
            {
                buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
            }

    fstream buff_file;

    buff_file.open("buff.dat", ios::out | ios::binary);
    buff_file.write((char*)arr, sizeof mater * n);
    buff_file.close();

    file.close();

    delete[] arr;

    remove("Mater.dat");
    rename("buff.dat", "Mater.dat");

    cout << "Файл відсортовано";
    f1 << "\n\nФайл відсортовано";

    f1.close();

}

#endif