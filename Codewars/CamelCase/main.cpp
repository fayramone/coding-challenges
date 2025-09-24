#include <string>
#include <iostream>

std::string to_camel_case(std::string text) {
    std::string result;
    bool isNextCap = false;
    for (const auto& ch : text) {
        if (isalpha(ch)) {
            if (isNextCap) {
                result += static_cast<char>(toupper(ch));
                isNextCap = false;
            } else {
                result += ch;
            }
        } else {
            isNextCap = true;
        }
    }
    return result;
}

int main() {
    std::string text = "This_text_to_camel_case";
    std::cout << to_camel_case(text) << std::endl;
    return 0;
}