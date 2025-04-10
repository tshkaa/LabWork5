#include <iostream>

using namespace std;

// Функция для вывода массива
void printArray(const double* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int validitySizeCheck() {
    int value;
    while (true) { // Цикл для ввода пользователем составляющей
        cout << "Введите число n (размер массива): "; 
        cin >> value;
        // Обработка некорректного ввода пользователем
        if (cin.fail() || cin.peek() != '\n' || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите целое положительное число.\n\n";
            continue;
        }
        break;
    }
    cout << "\n";
    return value;
}

double validatyElementCheck(int index) {
    double value;
    while (true) { // Цикл для ввода пользователем составляющей
        cout << "Введите " << index + 1 << " элемент: "; 
        cin >> value;
        // Обработка некорректного ввода пользователем
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите вещественное число.\n\n";
            continue;
        }
        break;
    }
    return value;
}

// Функция для поиска минимального элемента массива
double findMin(const double* arr, int size) {
    double min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "\n";
    return min;
}

// Функция для нахождения индекса первого положительного элемента
int findFirstPositive(const double* arr, int size) {
    for (int i = 0; i < size; ++i)
        if (arr[i] > 0) return i;
    return -1; // Если положительных элементов нет
}

// Функция для нахождения индекса последнего положительного элемента
int findLastPositive(const double* arr, int size) {
    for (int i = size - 1; i >= 0; --i)
        if (arr[i] > 0) return i;
    return -1; // Если положительных элементов нет
}

// Функция для вычисления суммы между первым и последним положительными элементами
double sumBetweenPositives(const double* arr, int size) {
    int first = findFirstPositive(arr, size);
    int last = findLastPositive(arr, size);

    if (first == -1 || last == -1 || first == last || abs(first - last) == 1) return NAN;

    double sum = 0.0;
    int start = (first < last) ? first : last;
    int end = (first < last) ? last : first;

    for (int i = start + 1; i < end; ++i) 
        sum += arr[i];
    return sum;
}

// Функция для преобразования массива (нули в начале)
void moveZerosToFront(double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            for (int j = 0; j < i; j++)
                arr[i - j] = arr[i - (j + 1)];
            arr[0] = 0;
        }
    }
}
