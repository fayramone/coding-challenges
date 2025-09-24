#include <iostream>
#include <vector>
#include <set>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);

    for (auto& el : vec) {
        std::cin >> el;
    }

    auto itFirst = vec.begin();
    auto itSecond = vec.begin() + static_cast<std::ptrdiff_t>(k);

    std::multiset<int> section(itFirst, itSecond);

    while(true) {
        std::cout << *(section.begin()) << "\n";

        if (itSecond == vec.end()) break;

        section.erase(section.find(*itFirst));
        ++itFirst;
        
        section.insert(*itSecond);
        ++itSecond;
    }

    return 0;
}