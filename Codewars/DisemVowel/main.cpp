#include <string>
#include <iostream>

std::string disemvowel(const std::string& str) {
    std::string result;
    for (char l : str) {
        switch (std::tolower(l)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            continue;
        default:
            result += l;
        }
    }
    return result;
}

int main() {
    std::cout << disemvowel("This website is for losers LOL!") << std::endl;

    return 0;
}