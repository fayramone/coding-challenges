#include <iostream>
#include <cassert>
#include <cmath>
#include <string>

constexpr auto jumpingNumber(int number) -> std::string {
    if (number < 10) return "Jumping!!";

    while(number > 9) {
        int first = number % 10;
        int second = (number / 10) % 10;
        if (std::abs(first - second) != 1) {
            return "Not!!";
        }

        number /= 10;
    }
    return "Jumping!!";
}

int main() {
    assert(jumpingNumber(9) == "Jumping!!");
    assert(jumpingNumber(1) == "Jumping!!");
    assert(jumpingNumber(7) == "Jumping!!");
    assert(jumpingNumber(23) == "Jumping!!");
    assert(jumpingNumber(32) == "Jumping!!");
    assert(jumpingNumber(79) == "Not!!");
    assert(jumpingNumber(98) == "Jumping!!");
    assert(jumpingNumber(8987) == "Jumping!!");
    assert(jumpingNumber(4343456) == "Jumping!!");
    assert(jumpingNumber(98789876) == "Jumping!!");
    
    std::cout << "All tests passed.\n";

    return 0;
}
