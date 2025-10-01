#include <iostream>
#include <string>
#include <vector>


int main() {
    int n = 0;
    std::cin >> n;

    std::vector<int> seats(n);

    for (int guest = 1; guest <= n; ++guest) {
        int seat;
        std::cin >> seat;
        seats[seat - 1] = guest;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << seats[i] << " ";
    }

    return 0;
}