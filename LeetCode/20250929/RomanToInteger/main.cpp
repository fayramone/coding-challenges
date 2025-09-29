#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                                {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = 0, prev = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            int current = roman[*it];
            result += (current >= prev) ? current : -current;
            prev = current;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::cout   << sol.romanToInt("III") 
                << " " << sol.romanToInt("LVIII") 
                << " " << sol.romanToInt("MCMXCIV") 
                << std::endl;

    return 0;
}