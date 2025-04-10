// LabWork5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Выполнил: Ижболдин Г.А., студент группы М411

#include <iostream>
#include "LabWork5Lib.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int n = validitySizeCheck();

    // Динамическое выделение памяти
    double* arr = new double[n];

    // Ввод элементов массива
    cout << "Введите " << n << " вещественных чисел (дробные числа должны быть написаны через точку):\n\n";
    for (int i = 0; i < n; ++i) {
        arr[i] = validatyElementCheck(i);
    }

    cout << "\nИсходный массив: ";
    printArray(arr, n);

    // 1. Поиск минимального элемента
    double min = findMin(arr, n);
    cout << "Минимальный элемент: " << min << endl;

    // 2. Сумма между первым и последним положительными элементами
    double sum = sumBetweenPositives(arr, n);
    std::cout << "Сумма между первым и последним положительными элементами: " << sum << std::endl;

    // Преобразование массива
    moveZerosToFront(arr, n);
    std::cout << "Преобразованный массив (нули в начале): ";
    printArray(arr, n);

    // Освобождение памяти
    delete[] arr;
 
    return 0;
}