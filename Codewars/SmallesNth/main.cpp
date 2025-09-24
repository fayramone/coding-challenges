#include <iostream>
#include <vector>
#include <algorithm>

int nthSmallest (std::vector<int> passed, int nSmallest) {
    std::sort(passed.begin(), passed.end());
    return passed[static_cast<size_t>(nSmallest - 1)];
}

int main() {
    std::vector<int> passed = {
        177, 225, 243, -169, -12, -5, 2, 92
    };
    std::cout << nthSmallest(passed, 5) << std::endl;
}