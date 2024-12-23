#include <iostream>

double power(double base, int exp) {
    if (exp == 0)
        return 1;

    if (exp < 0)
        return 1 / power(base, -exp);

    return base * power(base, exp - 1);
}

int main() {
    double base;
    int exp;

    std::cout << "Введите основание: ";
    std::cin >> base;

    std::cout << "Введите показатель степени: ";
    std::cin >> exp;

    double result = power(base, exp);
    std::cout << base << " ^ " << exp << " = " << result << std::endl;

    return 0;
}
