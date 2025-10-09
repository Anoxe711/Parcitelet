#include "Header.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <windows.h>

using namespace std;

// Определение глобального массива
vector<double> arr;

// Просеивание вниз (для построения кучи)
void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

// Пирамидальная сортировка
void heapSort() {
    int n = (int)arr.size(); // Явное преобразование для устранения предупреждения

    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

// Проверка на пустоту
bool isArrayEmpty() {
    return arr.empty();
}

// Проверка минимального размера массива
bool hasValidSize() {
    return arr.size() > 2;  // Строго больше 2
}

// Получение размера массива
size_t getArraySize() {
    return arr.size();
}

// Очистка массива
void clearArray() {
    arr.clear();
}

// Добавление элемента
void addElement(double value) {
    arr.push_back(value);
}

// Вывод массива
void displayArray() {
    if (isArrayEmpty()) {
        cout << "| Массив пуст!                          |" << endl;
        return;
    }

    cout << "| Текущий массив:                        |" << endl;

    string currentLine = "| ";
    const int maxLineLength = 38; // Максимальная длина внутри рамки

    for (size_t i = 0; i < arr.size(); i++) {
        // Форматируем число до 2 знаков после запятой
        stringstream elementStream;
        elementStream << fixed << setprecision(2) << arr[i];
        string element = elementStream.str();

        // Добавляем запятую если не последний элемент
        if (i != arr.size() - 1) {
            element += ", ";
        }

        // Если добавление элемента превысит длину строки, выводим текущую строку и начинаем новую
        if (currentLine.length() + element.length() > maxLineLength) {
            // Заполняем пробелами до конца строки
            while (currentLine.length() < 41) {
                currentLine += " ";
            }
            currentLine += "|";
            cout << currentLine << endl;
            currentLine = "| ";
        }

        currentLine += element;
    }

    // Выводим последнюю строку
    if (!currentLine.empty()) {
        while (currentLine.length() < 41) {
            currentLine += " ";
        }
        currentLine += "|";
        cout << currentLine << endl;
    }

    // Выводим размер массива
    cout << "| Размер массива: " << arr.size();
    int spaces = 25 - (int)to_string(arr.size()).length(); // Явное преобразование
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << "|" << endl;
}

// Функция для вывода горизонтальной линии
void printLine() {
    cout << "+------------------------------------------+" << endl;
}

// Функция для вывода заголовка
void printHeader(const string& title) {
    printLine();
    cout << "|";
    int padding = (40 - (int)title.length()) / 2; // Явное преобразование
    for (int i = 0; i < padding; i++) cout << " ";
    cout << title;
    for (int i = 0; i < 40 - (int)title.length() - padding; i++) cout << " ";
    cout << "|" << endl;
    printLine();
}

// Функция для отображения красивого меню
void displayMenu() {
    printHeader("ПИРАМИДАЛЬНАЯ СОРТИРОВКА");
    cout << "| 1. Добавить элементы вручную             |" << endl;
    cout << "| 2. Сгенерировать случайный массив        |" << endl;
    cout << "| 3. Отсортировать массив                  |" << endl;
    cout << "| 4. Показать массив                       |" << endl;
    cout << "| 5. Очистить массив                       |" << endl;
    cout << "| 6. Информация о сортировке               |" << endl;
    cout << "| 0. Выход                                 |" << endl;
    printLine();
    cout << "| Выберите опцию: ";
}

// Функция для ввода вещественного числа с проверкой
double getValidDoubleInput() {
    double value;
    while (true) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            return value;
        }
        else {
            cout << "| Ошибка! Введите вещественное число: ";
        }
    }
}

// Функция для ввода опции меню (0-6)
int getMenuChoice() {
    int value;
    while (true) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            if (value >= 0 && value <= 6) {
                return value;
            }
            else {
                cout << "| Ошибка! Введите число от 0 до 6: ";
            }
        }
        else {
            cout << "| Ошибка! Введите целое число: ";
        }
    }
}

// Функция для ввода размера массива (строго > 2)
int getValidArraySize() {
    int value;
    while (true) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            if (value > 2) {
                return value;
            }
            else {
                cout << "| Ошибка! Размер массива должен быть  |" << endl;
                cout << "| больше 2. Повторите ввод: ";
            }
        }
        else {
            cout << "| Ошибка! Введите целое число: ";
        }
    }
}

// Функция для добавления элементов вручную
void manualInput() {
    if (!isArrayEmpty()) {
        printHeader("ОШИБКА");
        cout << "| Массив уже существует!                 |" << endl;
        cout << "| Сначала очистите текущий массив.       |" << endl;
        printLine();
        return;
    }

    printHeader("РУЧНОЙ ВВОД ЭЛЕМЕНТОВ");

    cout << "| Введите размер массива (> 2): ";
    int count = getValidArraySize();
    printLine();

    printHeader("ВВОД ЭЛЕМЕНТОВ");
    cout << "| Введите " << count << " вещественных элементов: |" << endl;
    printLine();

    for (int i = 0; i < count; i++) {
        cout << "| Элемент " << setw(2) << i + 1 << ": ";
        double value = getValidDoubleInput();
        addElement(value);
    }

    printHeader("УСПЕХ");
    cout << "| Элементы успешно добавлены!             |" << endl;
    printLine();
}

// Функция для генерации случайного массива
void generateRandomArray() {
    if (!isArrayEmpty()) {
        printHeader("ОШИБКА");
        cout << "| Массив уже существует!                 |" << endl;
        cout << "| Сначала очистите текущий массив.       |" << endl;
        printLine();
        return;
    }

    printHeader("ГЕНЕРАЦИЯ СЛУЧАЙНОГО МАССИВА");

    cout << "| Введите размер массива (> 2): ";
    int size = getValidArraySize();
    printLine();

    cout << "| Введите минимальное значение: ";
    double minVal = getValidDoubleInput();
    cout << "| Введите максимальное значение: ";
    double maxVal = getValidDoubleInput();
    printLine();

    if (minVal > maxVal) {
        printHeader("ОШИБКА");
        cout << "| Минимальное значение не может быть      |" << endl;
        cout << "| больше максимального!                   |" << endl;
        printLine();
        return;
    }

    srand((unsigned int)time(0)); // Явное преобразование
    for (int i = 0; i < size; i++) {
        double randomValue = minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
        addElement(randomValue);
    }

    printHeader("УСПЕХ");
    cout << "| Случайный массив из " << setw(2) << size << " элементов       |" << endl;
    cout << "| успешно создан!                          |" << endl;
    printLine();
}

// Функция для отображения информации о сортировке
void displayInfo() {
    printHeader("ИНФОРМАЦИЯ О СОРТИРОВКЕ");
    cout << "| Пирамидальная сортировка (кучей):        |" << endl;
    cout << "| Принцип работы:                          |" << endl;
    cout << "| 1. Построение max-heap из массива        |" << endl;
    cout << "| 2. Перемещение максимального элемента    |" << endl;
    cout << "|    в конец                               |" << endl;
    cout << "| 3. Восстановление свойства кучи          |" << endl;
    cout << "| 4. Повторение до полной сортировки       |" << endl;
    cout << "|                                          |" << endl;
    cout << "| Требования:                              |" << endl;
    cout << "| • Размер массива должен быть > 2         |" << endl;
    cout << "| • Поддерживает вещественные числа        |" << endl;
    printLine();
}

// Функция для отображения результата сортировки
void displaySortResult() {
    if (isArrayEmpty()) {
        printHeader("ОШИБКА");
        cout << "| Массив пуст! Сначала добавьте элементы. |" << endl;
        printLine();
        return;
    }

    if (!hasValidSize()) {
        printHeader("ОШИБКА");
        cout << "| Для сортировки требуется массив        |" << endl;
        cout << "| размером больше 2 элементов!           |" << endl;
        cout << "| Текущий размер: " << setw(2) << getArraySize() << " элементов.          |" << endl;
        printLine();
        return;
    }

    printHeader("СОРТИРОВКА МАССИВА");
    cout << "| Исходный массив:                         |" << endl;
    printLine();
    displayArray();
    printLine();

    cout << "| Выполняется сортировка...                |" << endl;
    heapSort();
    printLine();

    cout << "| Отсортированный массив:                  |" << endl;
    printLine();
    displayArray();
    printLine();
}

// Функция для отображения массива
void showArray() {
    printHeader("ТЕКУЩИЙ МАССИВ");
    displayArray();

    if (!hasValidSize() && !isArrayEmpty()) {
        printLine();
        cout << "| Предупреждение: для сортировки         |" << endl;
        cout << "| требуется массив размером > 2!         |" << endl;
        cout << "| Текущий размер: " << setw(2) << getArraySize() << " элементов.          |" << endl;
        printLine();
    }
    else {
        printLine();
    }
}