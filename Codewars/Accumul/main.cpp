#include <iostream>
#include <cctype>

class Accumul {
public:
    static std::string accum(const std::string &s) {
        std::string str;
        for (size_t i = 0; i < s.length(); i++) {
            str += static_cast<char>(std::toupper(s[i]));
            str.append(i, static_cast<char>(std::tolower(s[i])));
            if (i + 1 < s.length()) str += '-';
        }
        return str;
    }
};

int main() {
    Accumul newAcc;
    
    std::cout << newAcc.accum("ZpglnRxqenU") << std::endl;
    std::cout << newAcc.accum("NyffsGeyylB") << std::endl;

    return 0;
}
