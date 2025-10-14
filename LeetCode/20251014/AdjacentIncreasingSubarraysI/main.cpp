#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
        std::set<size_t> index;
        for (size_t i = 0; i + static_cast<size_t>(k) <= nums.size(); ++i) {
            bool increase = true;
            for (size_t j = i + 1; j < i + static_cast<size_t>(k); ++j) {
                if (nums[j - 1] >= nums[j]) {
                    increase = false;
                    break;
                }
            }
            if (increase) index.insert(i);
        }
        for (auto el : index) {
            if (index.find(el + static_cast<size_t>(k)) != index.end())
                return true;
        }
        return false;
    }
};

int main() {
    std::vector<int> test1 = { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 };
    std::vector<int> test2 = { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };

    Solution sol;

    std::cout << (sol.hasIncreasingSubarrays(test1, 3) ? "YES" : "NO") << std::endl;
    std::cout << (sol.hasIncreasingSubarrays(test2, 5) ? "YES" : "NO") << std::endl;

    return 0;
}