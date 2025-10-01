#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void NearestElement(const std::vector<int>& n, const std::vector<int>& k) {
    std::vector<int> result;

    for (const auto& el : k) {
        auto it = std::lower_bound(n.begin(), n.end(), el);
        int candidate;

        if (it == n.end()) candidate = *(it - 1);
        else if (it == n.begin()) candidate = *(it);
        else {
            int left = *(it - 1), 
                right = *(it);
            int distLeft = std::abs(el - left), 
                distRight = std::abs(el - right);

            candidate = (distLeft <= distRight) ? left : right;
        }

        result.push_back(candidate);
    }

    for (const auto& el : result) {
        std::cout << el << std::endl;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nArr;
    std::vector<int> kArr;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nArr.push_back(num);
    }
    for (int i = 0; i < k; ++i) {
        int num;
        std::cin >> num;
        kArr.push_back(num);
    }
    NearestElement(nArr, kArr);

    return 0;
}