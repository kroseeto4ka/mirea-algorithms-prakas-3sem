#include <iostream>
#include <cmath>
//#include <conio>

bool checkRadius(float x, float y, float radius){
    return (x * x + y * y <= radius * radius);
}

int main(){
    float x, y, innerRadius, externalRadius;
    std::cout << "Введите координату x: \n";
    std::cin >> x;

    std::cout << "Введите координату y: \n";
    std::cin >> y;

    std::cout << "Введите радиус внутренней окружности: \n";
    std::cin >> innerRadius;

    std::cout << "Введите радиус внешней окружности: \n";
    std::cin >> externalRadius;

    if (!checkRadius(x, y, innerRadius) && checkRadius(x, y, externalRadius)) {
        std::cout << "Точка лежит в нужной области";
    } else {
        std::cout << "Точка не лежит в нужной области\n";
    }
}
