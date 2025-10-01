#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> vec;
    std::string str;
    while (std::getline(std::cin, str)) {
        vec.push_back(str);
    }

    // for (size_t i = 0; i < vec.size() - 1; ++i) {
    //     for (size_t j = 0; j < vec.size() - i - 1; ++j) {
    //         if (vec[j] < vec[j + 1]) {
    //             std::swap(vec[j], vec[j + 1]);
    //         }
    //     }
    // }

    std::sort(vec.begin(), vec.end(), std::greater<std::string>());

    for (const auto& st : vec) {
        std::cout << st << std::endl;
    }

    return 0;
}
