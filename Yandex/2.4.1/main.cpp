#include <iostream>
#include <string>
#include <cctype>

bool isPasswordValid(const std::string& password) {
    if (password.size() < 8 || password.size() > 14) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasOther = false;

    for (auto c : password) {
        if (static_cast<unsigned char>(c) < 33 || static_cast<unsigned char>(c) > 126) return false;

        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else hasOther = true;
    }

    int categoryCount = hasUpper + hasLower + hasDigit + hasOther;
    return categoryCount >= 3;

}  

int main() {
    std::string pass;
    std::getline(std::cin, pass);
    std::cout << (isPasswordValid(pass) ? "YES" : "NO") << std::endl;

    return 0;
}
