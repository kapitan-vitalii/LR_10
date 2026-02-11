#pragma once 

#ifndef SHEVKO_H
#define SHEVKO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <Windows.h>

using namespace std;

struct Mater {
    int id;
    char mater[20];
    double cost;
    double width;
    double height;
    int count;
};

int menu();
void create_file(const char* filename);
void app_record(const char* filename);
void create_record(fstream& file);
void print_header();
void createf1_txt();
void print_record(Mater mater);
void read_file(const char* filename);

int menu()
{
    int k;
    cout << "\n1 - створенн€ б≥нарний файл структур\n";
    cout << "2 - прочитати дан≥ з файлу на екран\n";
    cout << "3 - розкр≥й пр€мокутника\n";
    cout << "4 - соб≥варт≥сть матер≥ал≥в\n";
    cout << "5 - к≥льк≥сть чехл≥в з вказаного матер≥алу\n";
    cout << "6 - соб≥варт≥сть чехла\n";
    cout << "7 - м≥с€чний дох≥д\n";
    cout << "8 - сортувати за матер≥алом\n";
    cout << "9 - дозапис у файл\n";

    cout << "0 - вих≥д\n";
    cout << "«јƒј…“≈ –≈∆»ћ –ќЅќ“»: "; cin >> k;

    fstream f1("Log.txt", ios::app);
    f1 << "\n1 - створенн€ б≥нарний файл структур\n";
    f1 << "2 - прочитати дан≥ з файлу на екран\n";
    f1 << "3 - розкр≥й пр€мокутника\n";
    f1 << "4 - соб≥варт≥сть матер≥ал≥в\n";
    f1 << "5 - к≥льк≥сть чехл≥в з вказаного матер≥алу\n";
    f1 << "6 - соб≥варт≥сть чехла\n";
    f1 << "7 - м≥с€чний дох≥д\n";
    f1 << "8 - сортувати за матер≥алом\n";
    f1 << "9 - дозапис у файл\n";
    f1 << "0 - вих≥д\n";
    f1 << "«јƒј…“≈ –≈∆»ћ –ќЅќ“»: ";
    f1 << k;
    f1.close();

    return k;
}

void create_file(const char* filename)
{
    fstream file, f1;
    int n;
    cout << "¬вед≥ть ск≥льки запис≥в потр≥бно створити:";
    cin >> n;
    file.open(filename, ios::out | ios::binary);
    f1.open("Log.txt", ios::out | ios::app);

    f1 << "\n\n¬вед≥ть ск≥льки запис≥в потр≥бно створити:";
    f1 << n;
    for (int i = 0; i < n; i++)
        create_record(file);
    f1.close();
    file.close();
    cout << "‘айл створено.";
}

void app_record(const char* filename)
{
    fstream file, f1;
    int n;
    file.open(filename, ios::out | ios::binary | ios::app);
    f1.open("Log.txt", ios::out | ios::app);
    cout << "¬вед≥ть ск≥льки запис≥в потр≥бно створити:";
    cin >> n;

    f1 << "\n¬вед≥ть ск≥льки запис≥в потр≥бно створити:";
    f1 << n;

    for (int i = 0; i < n; i++)
        create_record(file);
    file.close();
}

void create_record(fstream& file)
{
    Mater mater;

    cout << "¬вед≥ть ID:";
    cin >> mater.id;
    cin.ignore();
    cout << "¬вед≥ть матер≥ал: ";
    cin.getline(mater.mater, 20);
    cout << "¬вед≥ть ц≥ну за м2: ";
    cin >> mater.cost;
    cout << "¬вед≥ть ширину: ";
    cin >> mater.width;
    cout << "¬вед≥ть довжину: ";
    cin >> mater.height;
    cout << "¬вед≥ть к≥льк≥сть: ";
    cin >> mater.count;

    file.write((char*)&mater, sizeof mater);

    fstream f1("Log.txt", ios::app);
    f1 << "\n¬вед≥ть ID:";
    f1 << mater.id;
    f1 << "\n¬вед≥ть матер≥ал: ";
    f1 << mater.mater;
    f1 << "\n¬вед≥ть ц≥ну за м2: ";
    f1 << mater.cost;
    f1 << "\n¬вед≥ть ширину: ";
    f1 << mater.width;
    f1 << "\n¬вед≥ть довжину: ";
    f1 << mater.height;
    f1 << "\n¬вед≥ть к≥льк≥сть: ";
    f1 << mater.count;
    f1 << "\n‘айл створено.";
    f1.close();
}

void read_file(const char* filename)
{
    fstream file;
    Mater mater;
    file.open(filename, ios::in | ios::binary);
    int k = 0;
    while (file.read((char*)&mater, sizeof(Mater)))
    {
        k++;
        if (k == 1)
            print_header();
        print_record(mater);
    }
    file.close();
}

void print_header()
{
    cout << left << setw(5) << "\nID";
    cout << left << setw(10) << "Mater";
    cout << left << setw(10) << "Cost";
    cout << left << setw(10) << "Width";
    cout << left << setw(10) << "Height";
    cout << left << "Count";
    cout << endl;


    fstream f1("Log.txt", ios::app);
    f1 << left << setw(5) << "\n\nID";
    f1 << left << setw(10) << "Mater";
    f1 << left << setw(10) << "Cost";
    f1 << left << setw(10) << "Width";
    f1 << left << setw(10) << "Height";
    f1 << left << "Count";
    f1 << endl;
    f1.close();
}

void print_record(Mater mater)
{
    cout << left << setw(5) << mater.id;
    cout << setw(10) << mater.mater;
    cout << setw(10) << mater.cost;
    cout << setw(10) << mater.width;
    cout << setw(10) << mater.height;
    cout << setw(10) << mater.count;
    cout << endl;

    fstream f1("Log.txt", ios::app);
    f1 << left << setw(5) << mater.id;
    f1 << setw(10) << mater.mater;
    f1 << setw(10) << mater.cost;
    f1 << setw(10) << mater.width;
    f1 << setw(10) << mater.height;
    f1 << setw(10) << mater.count;
    f1 << endl;
    f1.close();
}

void createf1_txt()
{
    fstream f1("Log.txt", ios::out);
    f1 << "Result of testing";
    f1.close();
}

#endif