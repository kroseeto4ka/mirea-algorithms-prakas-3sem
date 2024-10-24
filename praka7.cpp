#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Подынтегральная функция f(x) = x * e^(-x)
double integralFunc(double x) {
    return x * exp(-x);
}

// Функция для вычисления интеграла методом Симпсона
double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = integralFunc(a) + integralFunc(b);

    // Сумма для нечетных индексов
    for (int i = 1; i < n; i += 2) {
        sum += 4 * integralFunc(a + i * h);
    }
    // Сумма для четных индексов
    for (int i = 2; i < n; i += 2) {
        sum += 2 * integralFunc(a + i * h);
    }
    return (h / 3) * sum;
}

int main() {
    cout << fixed << setprecision(6);

    double a = 0.0;
    
    for (double b = 0.5; b <= 2.0; b += 0.5){

        int n_segments = int(b / 0.1);

        double result = simpson(a, b, n_segments);

        std::cout << "Пределы интегрирования: " << "[" << a << "]" << "[" << b << "]" << std::endl;
        std::cout << "Значение: " << result << std::endl;
        std::cout << "Количество сегментов: " << n_segments << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
