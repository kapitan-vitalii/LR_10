#pragma once

#ifndef ZAKHARENKO_H
#define ZAKHARENKO_H

#include "Shevko.h"
#include "Datskyi.h"

double area(double h, double w);
void cutting();
double final_Cost(double h, double w, double cost);
void cost_Chokhol(const char* filename);
void month_Income(const char* filename);

//1
double area(double a, double b)
{
    a += 0.01;
    b += 0.01;

    return a * b;
}

void cutting()
{
    double h, w;
    fstream f1;
    f1.open("Log.txt", ios::out | ios::app);

    cout << "\nВведіть довжину розрізу: ";
    cin >> h;
    cout << "Введіть ширину розрізу: ";
    cin >> w;
    cout << "Площа розкрою " << area(h, w) << " (м^2)\n";
    cout << endl;


    f1 << "\n\nВведіть довжину розрізу: ";
    f1 << h;
    f1 << "\nВведіть ширину розрізу: ";
    f1 << w;
    f1 << "\nПлоща розкрою " << area(h, w) << " (м^2)\n";
    f1 << endl;

    f1.close();
}

//4
void cost_Chokhol(const char* filename)
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
        cout << "Ціна чохла на продаж: " << final_Cost(h, w, mater.cost) << endl;

        f1 << "\nВведіть довжину розрізу: ";
        f1 << h;
        f1 << "\nВведіть ширину розрізу: ";
        f1 << w;
        f1 << "\nЦіна чохла на продаж: " << final_Cost(h, w, mater.cost) << endl;
    }
    else
    {
        cout << "Не знайдено матеріал " << material << ".\n";
        f1 << "Не знайдено матеріал " << material << ".\n";
    }

    file.close();
    f1.close();
}

double final_Cost(double h, double w, double cost)
{
    double amortization = .13567;
    double profit = .10;

    double costWithAmort = cost_Brutto(h, w, cost) * (1.0 + amortization);
    double finalPrice = costWithAmort * (1.0 + profit);

    return finalPrice;
}

//5
void month_Income(const char* filename)
{
    Mater mater;
    fstream file, f1;
    char material[20];
    bool found = false;
    double sum, h, w;
    int k;

    file.open(filename, ios::in | ios::binary);
    f1.open("Log.txt", ios::out | ios::app);

    cout << "Введіть матеріал: ";
    cin.ignore();
    cin.getline(material, 20);
    f1 << "\n\nВведіть матеріал: ";
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
        cout << "Введіть к-ть чохлів: ";
        cin >> k;

        f1 << "\nВведіть довжину розрізу: ";
        f1 << h;
        f1 << "\nВведіть ширину розрізу: ";
        f1 << w;
        f1 << "\nВведіть к-ть чохлів: ";
        f1 << k;

        file.clear();
        file.seekg(0, ios::beg);

        sum = mater.count * area(mater.width, mater.height) - area(h, w) * k;

        if (sum < 0)
        {
            cout << "Не вистачає" << -sum << " (м^2) матеріалу";
            f1 << "\nНе вистачає" << -sum << " (м^2) матеріалу";
        }
        else
        {
            cout << "Місячний дохід: " << fixed << setprecision(2) << final_Cost(h, w, mater.cost) * k;
            f1 << "\nМісячний дохід: " << fixed << setprecision(2) << final_Cost(h, w, mater.cost) * k;
        }
    }
    else
    {
        cout << "Не знайдено матеріал " << material << ".\n";
        f1 << "\nНе знайдено матеріал " << material << ".\n";
    }

    file.close();
    f1.close();
}

#endif