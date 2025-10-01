#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += ((pow((-1),(i + 1)))/i);
    }

    std::cout << sum;

    return 0;
}
