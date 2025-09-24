#include <iostream>
#include <string>

class Solution {
public:
    std::string expand(const std::string& s, int left, int right) {
        while(left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            --left, ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }

    std::string longestPalindrome(std::string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        std::string result = "";

        for (int i = 0; i < (int)s.size(); ++i) {
            std::string temp1 = expand(s, i, i);
            std::string temp2 = expand(s, i, i + 1);
            if (temp1.size() > result.size()) result = temp1;
            if (temp2.size() > result.size()) result = temp2;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::string str = "ggbadannadabs";
    std::cout << sol.longestPalindrome(str) << std::endl;

    return 0;
}