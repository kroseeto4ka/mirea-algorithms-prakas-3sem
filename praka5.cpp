#include <iostream>
#include <string>
#include <sstream>

const int MAX_WORDS = 100;
const int MAX_LENGTH = 100;

bool isPalindrome(const std::string& word) {
    std::string cleaned;
    for (char ch : word) {
        cleaned += std::tolower(ch);
    }
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return cleaned == reversed && !cleaned.empty();
}

int main() {
    std::string text;
    std::cout << "Введите текст: ";
    std::cin >> text;

    char forbiddenChars[] = {' ', '.', ',', ';', ':', '"', '-', '?', '!', '(', ')'}; 
    size_t size = sizeof(forbiddenChars) / sizeof(forbiddenChars[0]);

    // Замена запрещенных символов на '/'
    for (char& ch : text) {
        for (size_t i = 0; i < size; ++i) {
            if (ch == forbiddenChars[i]) {
                ch = '/';
                break;
            }
        }
    }

    std::string palindromes[MAX_WORDS];
    int count = 0;

    std::stringstream ss(text);
    std::string word;

    while (std::getline(ss, word, '/')) {
        if (isPalindrome(word) && count < MAX_WORDS) {
            palindromes[count] = word;
            count++;
        }
    }

    if (count == 0) {
        std::cout << "Палиндромов не найдено." << std::endl;
    } else {
        std::cout << "Палиндромы: " << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << palindromes[i] << std::endl;
        }
    }
    return 0;
}