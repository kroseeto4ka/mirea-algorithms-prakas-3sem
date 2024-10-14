#include <iostream>

void removeNthRows(int** matrix, int& rows, int cols, int n) {
    int newRows = 0; // Количество строк после удаления

    // Перебираем строки исходной матрицы
    for (int i = 0; i < rows; ++i) {
        // Проверяем, является ли индекс строки кратным n (1-based index)
        if ((i + 1) % n != 0) {
            for (int j = 0; j < cols; ++j) {
                matrix[newRows][j] = matrix[i][j]; // Копируем строку
            }
            newRows++; // Увеличиваем счетчик строк
        }
    }

    rows = newRows; // Обновляем количество строк
}

int main() {
    int rows = 6; // Исходное количество строк
    int cols = 3; // Количество столбцов
    int n = 2; // Удаляем каждую вторую строку

    // Динамическое выделение памяти для двумерного массива
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Инициализация матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i;
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    removeNthRows(matrix, rows, cols, n);

    std::cout << "\nМатрица после удаления:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
