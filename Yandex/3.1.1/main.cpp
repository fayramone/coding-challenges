#include <iostream>
#include <vector>
#include <string>

template <typename Container>
void Print(const Container& container, const std::string& del) {
    auto it = container.begin();
    auto end = container.end();

    for (const auto& elem : container) {
        ++it;
        std::cout << elem;
        if (it != end) {
            std::cout << del;
        } else {
            std::cout << "\n";
        }
    }
}