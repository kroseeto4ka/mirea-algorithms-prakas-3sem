#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct Route {
    int number;
    std::string destination;
    int duration;
    std::string startDate;

    bool operator<(const Route& other) const {
        return number < other.number;
    }

    bool operator>(const Route& other) const {
        return number > other.number;
    }
};

Route* readFromFile(std::string filename, int* count) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        *count = 0;
        return nullptr;
    }

    *count = 0;
    std::string line;
    while (std::getline(file, line)) {
        (*count)++;
    }

    Route* routes = new Route[*count];

    int i = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    while (file >> routes[i].number 
    >> routes[i].destination 
    >> routes[i].duration 
    >> routes[i].startDate) {
        i++;
    }   

    file.close();
    return routes;
}

void printRoute(Route route){
    std::cout << "Номер маршрута: " << route.number
        << "; Город назначения: " << route.destination
        << "; Продолжительность: " << route.duration
        << "; Дата: " << route.startDate
        << std::endl;
}

void printRoutes(Route* routes, int size){
    for (int i = 0; i < size; i++) {
        printRoute(routes[i]);
    }
}

void bubbleSortMatrix(Route* routes, int size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (routes[j] > routes[j + 1]) {
                Route temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
            }
        }
    }
}

void binarySearch(Route* routes, int size, int target){
    int bottom = 0;
    int top = size - 1;

    while (bottom <= top) {
        int mid = bottom + (top - bottom) / 2;

        if (routes[mid].number == target) {
            printRoute(routes[mid]);
            return;
        } else if (routes[mid].number < target) {
            bottom = mid + 1; 
        } else {
            top = mid - 1;  
        }
    }
    std::cout << "Такого элемента нет в списке" << std::endl;
    return;
}

int main(void) {
    std::string inputFile = "route.txt";
    std::string outputFile = "sorted_routes.txt";
    Route* routes = nullptr;
    int routeCount;

	while (true) {
        int option;

		std::cout << "*============================*\n";
		std::cout << "|| 1. Вывод всех маршрутов\n";
		std::cout << "|| 2. Сортировка и вывод маршрутов\n";
		std::cout << "|| 3. Поиск маршрута по номеру\n";
		std::cout << "|| 4. Сохранение сортированных маршрутов\n";
        std::cout << "|| 5. Чтение сортированных маршрутов\n";
		std::cout << "|| 6. Выход\n";
		std::cout << "*============================*\n";
		
		std::cout << ">>> ";
		std::cin >> option;
		switch (option) {
		case 1:{
            routes = readFromFile(inputFile, &routeCount);

            if (routes == nullptr || routeCount == 0) {
                std::cerr << "Файл не найден\n";
                return 1;
            }

            printRoutes(routes, routeCount);

			break;
        }
		case 2:{
            bubbleSortMatrix(routes, routeCount);
            printRoutes(routes, routeCount);
			break;
        }
		case 3:{
            int target;

            std::cout << "Введите номер маршрута для поиска: \n" << ">>> ";
            std::cin >> target;

            binarySearch(routes, routeCount, target);

			break;
        }
		case 4: {
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи\n";
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(&routeCount), sizeof(routeCount));

    for (int i = 0; i < routeCount; ++i) {
        outFile.write(reinterpret_cast<const char*>(&routes[i].number), sizeof(routes[i].number));

        size_t destLength = routes[i].destination.size();
        outFile.write(reinterpret_cast<const char*>(&destLength), sizeof(destLength)); // Длина строки
        outFile.write(routes[i].destination.c_str(), destLength); // Сама строка

        outFile.write(reinterpret_cast<const char*>(&routes[i].duration), sizeof(routes[i].duration));

        size_t dateLength = routes[i].startDate.size();
        outFile.write(reinterpret_cast<const char*>(&dateLength), sizeof(dateLength)); // Длина строки
        outFile.write(routes[i].startDate.c_str(), dateLength); // Сама строка
    }

    outFile.close();
    std::cout << "Маршруты успешно сохранены в бинарном формате\n";
    break;
}

        case 5: {
            std::ifstream inFile(outputFile, std::ios::binary);

            if (!inFile) {
                std::cerr << "Ошибка открытия файла для чтения\n";
                return 1;
            }

            int newRouteCount;
            inFile.read(reinterpret_cast<char*>(&newRouteCount), sizeof(newRouteCount));

            if (routes != nullptr) {
                delete[] routes;
            }

            routes = new Route[newRouteCount];
            routeCount = newRouteCount; 

            for (int i = 0; i < routeCount; ++i) {
                
        inFile.read(reinterpret_cast<char*>(&routes[i].number), sizeof(routes[i].number));

        size_t destSize;
        inFile.read(reinterpret_cast<char*>(&destSize), sizeof(destSize));
        routes[i].destination.resize(destSize);
        inFile.read(&routes[i].destination[0], destSize);

        inFile.read(reinterpret_cast<char*>(&routes[i].duration), sizeof(routes[i].duration));

        size_t startDateSize;
        inFile.read(reinterpret_cast<char*>(&startDateSize), sizeof(startDateSize));
        routes[i].startDate.resize(startDateSize);
        inFile.read(&routes[i].startDate[0], startDateSize);
    }

    inFile.close();
    std::cout << "Данные успешно прочитаны и восстановлены в массив\n";

    printRoutes(routes, routeCount);
    break;
}
		case 6:
			return 0;
		default:
			std::cout << "Неверный ввод\n";
		}
	}
	return 0;
}
