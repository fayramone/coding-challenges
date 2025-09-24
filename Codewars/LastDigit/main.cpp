#include <iostream>
#include <string>
#include <unordered_map>

const std::unordered_map<int, int> periods = {
    { 0, 1 }, { 1, 1 }, { 2, 4 }, { 3, 4 }, { 4, 2 }, 
    { 5, 1 }, { 6, 1 }, { 7, 4 }, { 8, 4 }, { 9, 2 } 
};

const std::vector<std::vector<int>> digitCycles = {
    { 0 },      
    { 1 },      
    { 2, 4, 8, 6 },
    { 3, 9, 7, 1 },
    { 4, 6 },    
    { 5 },      
    { 6 },      
    { 7, 9, 3, 1 },
    { 8, 4, 2, 6 },
    { 9, 1 }     
};

int modFromString(const std::string& str, int mod) {
    if (mod == 1) return 0;
    int result = 0;
    for (const auto& ch : str) {
        result = (result * 10 + (ch - '0')) % mod;
    }
    return result;
}

int last_digit(const std::string &str1, const std::string &str2) {
    if (str2 == "0") return 1;
    if (str1 == "0") return 0;
    int lastDigit = str1.back() - '0';
    int period = periods.at(lastDigit);
    int expMod = modFromString(str2, period);
    if (expMod == 0) expMod = period;
    const auto& cycle = digitCycles[static_cast<size_t>(lastDigit)];
    
    return cycle[static_cast<size_t>(expMod - 1)];
}

int main() {
    std::string str1 = "1606938044258990275541962092341162602522202993782792835301376";
    std::string str2 = "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376";

    std::cout << last_digit(str1, str2);

    return 0;
}
