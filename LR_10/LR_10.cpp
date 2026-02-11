#include "Datskyi.h"
#include "Shevko.h"
#include "Zakharenko.h"

int main()
{
    setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(CP_UTF8);

    fstream file;
    char filename[20] = "Mater.dat";
    int b = 1;

    while (b)
        switch (menu())
        {
        case 0:
            b = 0;
            break;
        case 1:
            createf1_txt();
            create_file(filename);
            break;
        case 2:
            read_file(filename);
            break;
        case 3:
            cutting();
            break;
        case 4:
            cost_Mater(filename);
            break;
        case 5:
            cost_Chokhol(filename);
            break;
        case 6:
            count_by_Mater(filename);
            break;
        case 7:
            month_Income(filename);
            break;
        case 8:
            sortFileByMateria(filename);
            break;
        case 9:
            app_record(filename);
            break;
        }
}