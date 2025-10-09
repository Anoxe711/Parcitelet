#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ќбъ€вление глобального массива
extern vector<double> arr;

// ќбъ€влени€ функций
void heapify(int n, int i);
void heapSort();
bool isArrayEmpty();
bool hasValidSize();
size_t getArraySize();
void clearArray();
void addElement(double value);
void displayArray();
void printLine();
void printHeader(const string& title);
void displayMenu();
double getValidDoubleInput();
int getMenuChoice();
int getValidArraySize();
void manualInput();
void generateRandomArray();
void displayInfo();
void displaySortResult();
void showArray();

#endif