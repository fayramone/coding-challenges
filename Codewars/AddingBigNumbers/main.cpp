#include <iostream>
#include <algorithm>

#include <string>

std::string add(const std::string& a, const std::string& b) {
    int carry = 0;
    std::string result;

    auto it1 = a.rbegin(), it2 = b.rbegin();
    while(it1 != a.rend() || it2 != b.rend()) {
        int digitA = (it1 != a.rend()) ? *it1 - '0' : 0;
        int digitB = (it2 != b.rend()) ? *it2 - '0' : 0;
        int sum = digitA + digitB + carry;

        result += std::to_string(sum % 10);
        carry = sum / 10;

        if (it1 != a.rend()) ++it1;
        if (it2 != b.rend()) ++it2;
    }

    if (carry == 1) result += "1";
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

    std::cout << add("1234569944", "456789") << std::endl;

    return 0;
}