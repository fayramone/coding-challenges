#include <iostream>
#include <string>

bool solution(std::string const &str, std::string const &ending) {
    if (ending.length() > str.length()) {
        return false;
    }

    if (ending == str.substr(str.length() - ending.length())) {
        return true;
    }
    
    return false;
}

int main() {
    if (solution("abc", "bc")) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    solution("sgojaoia", "aoiaf") ? std::cout << "Yes" : std::cout << "No";

    return 0;
}
