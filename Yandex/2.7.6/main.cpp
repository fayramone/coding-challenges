#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        int da = a.first * a.first + a.second * a.second;
        int db = b.first * b.first + b.second * b.second;
        return da < db;
    });

    for (const auto& [x, y] : points) {
        std::cout << x << " " << y << std::endl;
    }

    return 0;
}