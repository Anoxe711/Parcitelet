#include "Header.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int choice;

    // Установка русской локализации
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    do {
        displayMenu();
        choice = getMenuChoice();
        printLine();

        switch (choice) {
        case 1:
            manualInput();
            break;

        case 2:
            generateRandomArray();
            break;

        case 3:
            displaySortResult();
            break;

        case 4:
            showArray();
            break;

        case 5:
            clearArray();
            printHeader("УСПЕХ");
            cout << "| Массив очищен!                          |" << endl;
            printLine();
            break;

        case 6:
            displayInfo();
            break;

        case 0:
            printHeader("ЗАВЕРШЕНИЕ РАБОТЫ");
            cout << "| До свидания!                            |" << endl;
            printLine();
            break;
        }

        if (choice != 0) {
            cout << "| Нажмите Enter для продолжения...         |" << endl;
            printLine();
            cin.get();
            system("cls");
        }

    } while (choice != 0);

    return 0;
}