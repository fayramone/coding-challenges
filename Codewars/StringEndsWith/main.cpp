#include <iostream>

#include <string>
bool solution(std::string const &str, std::string const &ending) {
    return (ending.size() <= str.size() 
            && ending == str.substr(str.size() - ending.size(), str.size())); 
}

int main() {

    std::cout << solution("abcde", "cde") << std::endl;
    std::cout << solution("abc", "") << std::endl;
    std::cout << solution("a", "a") << std::endl;
    std::cout << solution("abc", "cbc") << std::endl;
    std::cout << solution("", "") << std::endl;
    return 0;
}

