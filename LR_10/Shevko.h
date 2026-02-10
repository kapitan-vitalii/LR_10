#ifndef Shevko_H
#define Shevko_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

void create_bin();
void readFile(fstream& file);
void save_txt(fstream& file);



struct Mater {
    int id[3];
    char mater[20];
    int cost[6];
    int width[6];
    int height[6];
    int count[10];
};

void create_bin() {
    ofstream file("Mater.dat", ios::binary);
    if (!file) {
        cout << "Помилка створення файлу!" << endl;
        return;
    }

    file.close();
}

void readFile(fstream& file) {
    ifstream file("Mater.dat", ios::binary);
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    file.close();
}
void save_txt(fstream& file) {
    ifstream file("Mater.dat", ios::binary);
    ofstream tfile("Mater.txt");


}

#endif