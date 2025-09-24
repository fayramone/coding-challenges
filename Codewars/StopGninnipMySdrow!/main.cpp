#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string spinWords(const std::string &str) {
    std::stringstream ss(str);
    std::string word, result;
    bool first = true;

    while(ss >> word) {
        if (!first) result += " ";
        first = false;

        if (word.size() > 4) {
            auto i = 0;
            if (!word.empty() && !std::isalpha(static_cast<unsigned char>(word.back()))) i = 1;
            std::reverse(word.begin(), word.end() - i);
        }
        result += word;
    }
    return result;
}

int main() {
    std::cout << spinWords("Stop Spinning my Words!") << std::endl;

}