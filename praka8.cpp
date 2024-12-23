#include <iostream>
#include <string>

void inputMatrix(int** matrix, int height, int width){
    std::cout << "Введите элементы целочисленной матрицы: " << std::endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void inputMatrix(std::string** matrix, int height, int width){
    std::cout << "Введите элементы строковой матрицы: " << std::endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void bubbleSortMatrix(std::string** matrix, int height, int width){
    for (int i = 0; i < height - 1; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            if (matrix[j][width - 1] > matrix[j + 1][width - 1]) {
                std::string* temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    }
}

void bubbleSortMatrix(int** matrix, int height, int width){
    for (int i = 0; i < height - 1; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            if (matrix[j][width - 1] > matrix[j + 1][width - 1]) {
                int* temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    }
}

void outputMatrix(int** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void outputMatrix(std::string** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int height) {
    for (int i = 0; i < height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deleteMatrix(std::string** matrix, int height) {
    for (int i = 0; i < height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int height, width, type;

    std::cout << "Введите высоту матрицы: ";
    std::cin >> height;

    if (height < 1) {
        std::cout << "Неверный размер массива" << std::endl;
        return 1;
    }

    std::cout << "Введите ширину матрицы: ";
    std::cin >> width;

    if (width < 1) {
        std::cout << "Неверный размер массива" << std::endl;
        return 1;
    }

    std::cout << "Введите тип матрицы: " << std::endl
    << "1 - целочисленная матрица" << std::endl
    << "2 - текстовая матрица" << std::endl;
    std::cin >> type;

    switch (type){
        case 1:{
            int** matrix = new int*[height];
            for (int i = 0; i < height; i++) {
                matrix[i] = new int[width];
            }

            inputMatrix(matrix, height, width);
            std::cout << "Несортированная матрица: " << std::endl;
            outputMatrix(matrix, height, width);
            std::cout << "Сортированная матрица: " << std::endl;
            bubbleSortMatrix(matrix, height, width);
            outputMatrix(matrix, height, width);
            deleteMatrix(matrix, height);
            break;
        }
        case 2:{
            std::string** matrix = new std::string*[height];
            for (int i = 0; i < height; i++) {
                matrix[i] = new std::string[width];
            }

            inputMatrix(matrix, height, width);
            std::cout << "Несортированная матрица: " << std::endl;
            outputMatrix(matrix, height, width);
            std::cout << "Сортированная матрица: " << std::endl;
            bubbleSortMatrix(matrix, height, width);
            outputMatrix(matrix, height, width);
            deleteMatrix(matrix, height);
            break;
        }
        default:
            std::cout << "Неверное название операции." << std::endl;
            return 1;
    }
}
