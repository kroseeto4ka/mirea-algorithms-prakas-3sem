#include <iostream>
#include <regex>

bool isValidEmail(const std::string& email) {
    const std::regex pattern("((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-.]+\\.[a-z]+$))");
    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Введите адрес электронной почты: ";
    std::cin >> email;

    if (isValidEmail(email)) {
        std::cout << "Адрес электронной почты введен правильно." << std::endl;
    } else {
        std::cout << "Адрес электронной почты введен неправильно." << std::endl;
    }

    return 0;
}
