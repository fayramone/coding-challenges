#include <iostream>
#include <string>

// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000

class Solution {
public:
    std::vector<std::string> thousands = { "", "M", "MM", "MMM" };
    std::vector<std::string> hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    std::vector<std::string> tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    std::vector<std::string> ones = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    std::string intToRoman(int num) {
        size_t number = static_cast<size_t>(num);
        return  thousands[number / 1000] + 
                hundreds[(number % 1000) / 100] +
                tens[(number % 100) / 10] +
                ones[number % 10];
    }
};

int main() {
    Solution sol;
    std::cout << sol.intToRoman(3749)
            << " " << sol.intToRoman(58)
            << " " << sol.intToRoman(1994)
            << " " << sol.intToRoman(1);

    return 0;
}