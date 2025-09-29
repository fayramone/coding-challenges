#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        auto min_el = std::min_element(strs.begin(), strs.end(), 
            [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
        });
        std::string result;
        for (size_t i = 0; i < min_el->size(); ++i) {
            char current = (*min_el)[i];
            for (const auto& el : strs) {
                if (el[i] != current) return result;
            }
            result += current;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> vec1 = { "flower", "flow", "flight" };
    std::vector<std::string> vec2 = { "dog", "racecar", "car" };

    std::cout << sol.longestCommonPrefix(vec1) << " " 
            << sol.longestCommonPrefix(vec2) << std::endl;


    return 0;
}