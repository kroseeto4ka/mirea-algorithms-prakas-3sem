#include <iostream>

void updateArray(int** array, int height, int width, int step){
    int newHeight = height - ((height - step) / 10);
    int **newArray = new int *[newHeight];
    int ct = 0;
    for (int i = 0; i < height; i++){
        if ((i - step) % 10 != 0) {
            newArray[ct] = array[i];
            for (int j = 0; j < width; j++){
                std::cout << newArray[ct][j] << " ";
            }
            std::cout << std::endl;
        }
        ct++;
    }

    delete[] newArray;
}

int main() {
    int height, width, step;

    std::cout << "Введите высоту матрицы: ";
    std::cin >> height;

    if (height < 1) {
        std::cout << "неверный размер массива" << std::endl;
        return 1;
    }

    std::cout << "Введите ширину матрицы: ";
    std::cin >> width;

    if (width < 1) {
        std::cout << "неверный размер массива" << std::endl;
        return 1;
    }

    std::cout << "Введите период строк: ";
    std::cin >> step;

    if (step < 0 or step > 9) {
        std::cout << "неверный порядок строк" << std::endl;
        return 1;
    }

    std::cout << "массив: " << std::endl;
    int **matrix = new int*[height];
    
    std::cout << "Изначальная матрица:" << std::endl;

    for (int i = 0; i < height; i++) {
        matrix[i] = new int[width];
        for (int j = 0; j < width; j++) {
            matrix[i][j] = i;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Преобразованная матрица:" << std::endl;

    updateArray(matrix, height, width, step);

    for (int i = 0; i < height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
