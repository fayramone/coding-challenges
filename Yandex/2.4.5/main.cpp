#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    std::string temp;
    for (auto ch : str) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            temp += static_cast<char>(ch);
        }
    }

    for (size_t i = 0; i < temp.size() / 2; ++i) {
        if (temp[i] != temp[temp.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (isPalindrome(str) ? "YES" : "NO") << std::endl;

    return 0;
}
