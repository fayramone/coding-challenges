#include <iostream>
#include <cmath>

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    while(n % 4 == 0 ) n /= 4;
    return n == 1;
}

int main() {
    std::cout << (isPowerOfFour(64) ? "YES" : "NO") << std::endl;
}