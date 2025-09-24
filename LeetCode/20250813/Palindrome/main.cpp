#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        std::string str = std::to_string(x);
        for (size_t i = 0, j = str.size() - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    std::cout << (sol.isPalindrome(134431) ? "YES" : "NO") << std::endl;

    return 0;
}