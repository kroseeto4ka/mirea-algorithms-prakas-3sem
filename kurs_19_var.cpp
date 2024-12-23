#include <iostream>
#include <fstream>

int setBit(int number, int position, bool newValue) {
    int mask = 1 << position;

    if (newValue) {
        return number | mask;
    } else {
        return number & ~mask;
    }
}

int* readFromFile(std::string filename, int* rows, int* cols) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: невозможно прочтитать файл " << filename << "\n";
        return nullptr;
    }

    file >> *rows >> *cols;

    int* table = new int [*rows];
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            int a = 0;
            file >> a;
            table[i] = setBit(table[i], *cols - j - 1, a);
        }
    } 

    file.close();
    std::cout << "Данные успешно записаны" << std::endl;
    return table;
}

int getBit(int number, int position) {
    int mask = 1 << position;
    return (number & mask) >> position;
}

void printInfo(int* array, int rows, int cols){
    for (int i = 0; i < rows; i++){
        std::string number;
        for (int position = 0; position < cols; position++){
           number = std::to_string(getBit(array[i], position)) + number;
        }
        std::cout << number << std::endl;
    }
}

void printYesNoAmount(int* array, int rows, int col){
    int yes = 0, no = 0;
    for (int row = 0; row < rows; row++) {
        if (getBit(array[row], col) == 1) {
            yes++;
        } else {
            no++;
        }
    }

    std::cout << "Количество положительных ответов: " << yes << std::endl;
    std::cout << "Количество отрицательных ответов: " << no << std::endl;
}

void findYesQuestions(int* array, int rows, int cols){
    std::cout << "Номера вопросов, которые имеют больше положительных ответов:" << std::endl;
    for (int i = 0; i < cols; i++){
        int yes = 0;
        int no = 0;
        for (int j = 0; j < rows; j++){
            if (getBit(array[j], i) == 1) {
                yes++;
            } else {
                no++;
            }
        }
        if (yes > no) {
            std::cout << cols - i << std::endl;
        }
    }
}

void findNoRespondents(int* array, int rows, int cols){
    std::cout << "Номера респондентов, которые ответили на все вопросы «нет»:" << std::endl;
    for (int i = 0; i < rows; i++){
        if (array[i] == 0) {
            std::cout << i + 1 << std::endl;
        }
    }
}

void findYesRespondents(int* array, int rows, int cols){
    std::cout << "Номера респондентов, которые ответили на все вопросы «нет»:" << std::endl;
    for (int i = 0; i < rows; i++){
        if (array[i] == pow(2, cols) - 1) {
            std::cout << i + 1 << std::endl;
        }
    }
}

int main() {
    int rows, cols;
    int* array;
    std::string filename = "survey.txt";
    while (true) {
        int option;

		std::cout << "*============================*\n";
		std::cout << "|| 1. Чтение файла\n";
		std::cout << "|| 2. Вывод ответов всех респондентов\n";
		std::cout << "|| 3. Подсчет ответов «да» и «нет» на j-вопрос\n";
		std::cout << "|| 4. Поиск вопросов, по которым большинство ответили «да»\n";
        std::cout << "|| 5. Поиск респондентов, которые на все вопросы ответили «нет»\n";
        std::cout << "|| 6. Поиск респондентов, которые на все вопросы ответили «да»\n";
		std::cout << "|| Иное число. Выход\n";
		std::cout << "*============================*\n";
		
		std::cout << ">>> ";
		std::cin >> option;
		switch (option) {
            case 1:
                array = readFromFile(filename, &rows, &cols);
                break;
            case 2:
                printInfo(array, rows, cols);
                break;
            case 3:
                int que;
                std::cout << "Введите номер вопроса\n" << ">>> ";
                std::cin >> que;
                que = cols - que;
                if ((que > cols) || (que < 0)) {
                    std::cout << "Неверный номер вопроса" << std::endl;
                } else {
                    printYesNoAmount(array, rows, que);
                }
                break;
            case 4:
                findYesQuestions(array, rows, cols);
                break;
            case 5: 
                findNoRespondents(array, rows, cols);
                break;
            case 6:
                findYesRespondents(array, rows, cols);
                break;
            default:
                std::cout << "Завершение работы программы..." << std::endl;
                return 0;
        }
    }
    return 0;
}
