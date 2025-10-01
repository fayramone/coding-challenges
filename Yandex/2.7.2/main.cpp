#include <iostream>
#include <vector>
#include <string>

std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty()) return "";
    std::string prefix = words[0];

    for (const auto& w : words) {
        if (w.size() < prefix.size()) prefix = w; 
    }

    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = 0; j < prefix.size(); ++j) {
            if (prefix[j] != words[i][j]) {
                prefix.resize(j);
                break;
            }
        }
    }

    return prefix;
};