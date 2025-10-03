/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <cassert>
#include <cstdint>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
    uint64_t sum = a + b;
    if (sum == 0) return "0";

    std::string result;
    while(sum > 0) {
        result += (sum & 1) ? '1' : '0';
        sum >>= 1;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    assert(add_binary(1, 1) == "10");
    assert(add_binary(0, 1) == "1");
    assert(add_binary(1, 0) == "1");
    assert(add_binary(2, 2) == "100");
    assert(add_binary(51, 12) == "111111");
    std::cout << "All tests passed\n";

    return 0;
}
