#include <iostream>
#include <string>
#include <map>

const std::map<std::string, char> t9 = {
    {"abc", '2'}, {"def", '3'}, {"ghi", '4'}, {"jkl", '5'}, 
    {"mno", '6'}, {"pqrs", '7'}, {"tuv", '8'}, {"wxyz", '9'}
};

std::string unlock (const std::string& str) {
    std::string code;
    for (const auto& ch : str) {
        char lower_ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        for (const auto& [letters, digit] : t9) {
            if (letters.find(lower_ch) != std::string::npos) {
                code += digit;
                break;
            }
        }
    }
    return code;
}

int main() {
    std::string str = "nokia";
    std::cout << unlock(str) << std::endl;

    return 0;
}