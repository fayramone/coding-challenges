/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <cassert>
#include <string>

std::string number_to_string(int num) {
    return std::to_string(num);
}

int main() {
    assert(number_to_string(1+2) == "3");
    assert(number_to_string(67) == "67");
    assert(number_to_string(-5) == "-5");
    assert(number_to_string(0) == "0");
    std::cout << "All tests passed\n";

    return 0;
}