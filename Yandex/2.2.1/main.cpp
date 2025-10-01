#include <iostream>

int main() {
    double cm, inch = 2.54;
    std::cin >> cm;
    inch = cm / inch;
    std::cout << inch;

    return 0;
}
