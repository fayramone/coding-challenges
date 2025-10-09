/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;

        std::function<void (int, int, std::string)> backtrack =
                [&](int open, int close, std::string cur) {
                    if (open == n && close == n) {
                        result.push_back(cur);
                    } else {
                        if (open < n) {
                            backtrack(open + 1, close, cur + "(");
                        }
                        if (close < open) {
                            backtrack(open, close + 1, cur + ")");
                        }
                    }
                };

        backtrack(0, 0, "");

        return result;
    }
};

void print(const std::vector<std::string>& vec) {
    for (const auto& v : vec) {
        std::cout << "[ " << v << " ] "; 
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    auto result1 = sol.generateParenthesis(1);
    auto result2 = sol.generateParenthesis(2);
    auto result3 = sol.generateParenthesis(3);

    print(result1);
    print(result2);
    print(result3);   
    
    return 0;
}
 