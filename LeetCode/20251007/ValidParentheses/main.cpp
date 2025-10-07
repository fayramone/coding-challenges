/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <cassert>
#include <stack>
#include <set>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets_stack;
        for (const auto& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                brackets_stack.push(ch);
            } else {
                if (brackets_stack.empty()) return false;
                char top = brackets_stack.top();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
                        return false;
                brackets_stack.pop();
            }
        }
        return brackets_stack.empty();
    }
};

int main() {
    Solution sol;
    
    assert(sol.isValid("()") == 1);
    assert(sol.isValid("()[]{}") == 1);
    assert(sol.isValid("(]") == 0);
    assert(sol.isValid("([])") == 1);
    assert(sol.isValid("([)]") == 0);

    std::cout << "All tests passed.\n";

    return 0;
}
