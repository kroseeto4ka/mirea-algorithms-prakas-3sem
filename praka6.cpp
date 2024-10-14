#include <iostream>

void inputArray(int* array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        std::cout << "A[" << i << "] = ";
        std::cin >> array[i];
    }
}

void outputArray(int* array, int arraySize) {
    std::cout << "Массив: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void negativesMultiplication(int* array, int arraySize) {
    int nm = 1;
    int amount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] < 0) {
            nm *= array[i];
            amount += 1;
        }
    }
    if (amount > 0) {
        std::cout << "Произведение отрицательных членов: " << nm << std::endl;
    } else {
        std::cout << "Нет отрицательных членов" << std::endl;
    }
}

int arrayMax(int* array, int arraySize) {
    int maxValue = array[0];

    for (int i = 1; i < arraySize; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    return maxValue;
}

int maxElementsAmount(int* array, int arraySize) {
    int maxElementsAmount = 0;
    int maxValue = arrayMax(array, arraySize);
    for (int i = 1; i < arraySize; i++) {
        if (array[i] == maxValue) {
            maxElementsAmount++;
        }
    }
    return maxElementsAmount;
}

int changeArraySize(int* array, int arraySize) {
    return arraySize - maxElementsAmount(array, arraySize);
}

int* deleteMaxElements(int* array, int* arraySize) {
    int newArraySize = changeArraySize(array, *arraySize);
    int* newArray = new int[newArraySize];
    int ct = 0;

    for (int i = 0; i < *arraySize; i++) {
        if (array[i] != arrayMax(array, *arraySize)) {
            newArray[ct++] = array[i];
        }
    }

    delete[] array;
    *arraySize = newArraySize;

    return newArray;
}

int main() {
    int arraySize, algNumber;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> arraySize;

    if (arraySize > 100 || arraySize < 0) {
        std::cout << "Неверный размер массива" << std::endl;
        return 1;
    }

    int* array = new int[arraySize];

    bool running = true;

    std::cout << "Доступные операции: " << std::endl
        << "1 — Ввод массива" << std::endl
        << "2 — Вывод массива" << std::endl
        << "3 — Вывод произведения отрицательных элементов массива" << std::endl
        << "4 - Удаление максимального элемента массива" << std::endl
        << "5 - Завершение программы" << std::endl;

    while(running) {
        std::cout << "Введите номер операции: " << std::endl;
        std::cin >> algNumber;

        switch (algNumber) {
        case 1:
            inputArray(array, arraySize);
            break;
        case 2:
            outputArray(array, arraySize);
            break;
        case 3:
            negativesMultiplication(array, arraySize);
            break;
        case 4:
            if ((maxElementsAmount(array, arraySize) == arraySize) || (arraySize == 1)) {
                std::cout << "Невозможно выполнить условие" << std::endl;
            }

            array = deleteMaxElements(array, &arraySize);

            std::cout << "Операция проведена." << std::endl;

            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "Неверный номер операции." << std::endl;
            break;
        }
    }
    return 0;
}
