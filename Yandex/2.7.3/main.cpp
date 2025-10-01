#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    size_t delmitterPos = 0;

    for (size_t i = 0; i <= str.size(); ++i) {
        if (i == str.size() || str[i] == delimiter) {
            result.push_back(str.substr(delmitterPos, i - delmitterPos));
            delmitterPos = i + 1;
        }
    }

    return result;
}