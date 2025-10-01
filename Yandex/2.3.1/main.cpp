#include <iostream>

int main() {
    int a1, b1, a2, b2;
    std::cin >> a1;
    std::cin >> b1;
    std::cin >> a2;
    std::cin >> b2;

    if ((a1 == a2 || b1 == b2) || abs(a2 - a1) == abs(b2 - b1)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
