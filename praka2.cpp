#include <iostream>

void returnTheArray(int *array, int arrayEnd, int startPosition){
    for (int i = startPosition; i < (arrayEnd / 2); i++) {
        int helper = array[i];
        array[i] = array[arrayEnd - i - 1];
        array[arrayEnd - i - 1] = helper;
    }
}

int main() {
    int arraySize, shiftSize;

    std::cout << "Введите размер массива: ";
    std::cin >> arraySize;

    if (arraySize < 1) {
        std::cout << "Неправильный размер массива" << std::endl;
        return 1;
    }

    std::cout << "Введите размерность сдвига: ";
    std::cin >> shiftSize;

    if (shiftSize < 0) {
        std::cout << "Неправильный размер сдвига" << std::endl;
        return 1;
    }

    shiftSize = shiftSize % arraySize;

    int *array = new int [arraySize];

    for (int i = 0; i < arraySize; i++) {
        std::cout << "Введите " << i << " элемент массива: ";
        std::cin >> array[i];
    }

    returnTheArray(array, arraySize, 0);
    returnTheArray(array, (arraySize + shiftSize), shiftSize);
    returnTheArray(array, shiftSize, 0);

    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i];
    }

    std::cout << std::endl;
    delete[] array;
}