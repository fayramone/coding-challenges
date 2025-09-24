#include <iostream>
#include <string>
#include <cctype>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        size_t i = 0;
        size_t n = s.size();

        while(i < n && s[i] == ' ') ++i;

        bool isNegative = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-') ? 1 : 0;
            ++i;
        }

        long long result = 0;
        while (i < n && std::isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            if (isNegative && -result <= INT_MIN) {
                return INT_MIN;
            }
            if (!isNegative && result >= INT_MAX) {
                return INT_MAX;
            }
            
            ++i;
        }

        return isNegative ? -static_cast<int>(result) : static_cast<int>(result);
    }
};

int main() {
    Solution sol;
    std::cout << sol.myAtoi("42")
            << " " << sol.myAtoi("    -42")
            << " " << sol.myAtoi("+42")
            << " " << sol.myAtoi("1337c0d3")
            << " " << sol.myAtoi("0-1") 
            << " " << sol.myAtoi("0000001") 
            << std::endl;

    return 0;
}