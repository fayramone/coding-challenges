#include <cstddef>
#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t position = haystack.find(needle, 0);
        return (position != std::string::npos) ? (int)position : -1;

    }
};

int main() {
    Solution sol;
    std::cout << sol.strStr("sadbutsad", "sad") << std::endl;
    std::cout << sol.strStr("leetcode", "leeto") << std::endl;

    return 0;
}
