#include <iostream>
#include <stack>


bool parSec(const std::string& str) {
    if (str.size() % 2 != 0) return false;

    std::stack<char> s;

    for (auto ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;
            if ((ch == ')' && s.top() == '(') || 
                    (ch == ']' && s.top() == '[') ||
                    (ch == '}' && s.top() == '{')) {
                s.pop();
            } else return false;
        } else return false;
    }

    return s.empty();
}

int main() {
    std::string input;
    std::cin >> input;
    std::cout << (parSec(input) ? "YES" : "NO") << std::endl;

    return 0;
}