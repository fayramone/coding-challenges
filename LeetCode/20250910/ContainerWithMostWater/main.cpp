#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        if (height.empty() || height.size() == 1) return 0;

        auto left = height.begin();
        auto right = height.end() - 1;
        int area = 0;
        while(left < right) {
            int currentArea = std::min(*left, *right) * static_cast<int>(right - left);
            area = std::max(area, currentArea);

            *left <= *right ? ++left : --right;
        }

        return area;
    }
};

int main() {
    Solution sol;
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    std::cout << sol.maxArea(height) << std::endl;

    return 0;
}