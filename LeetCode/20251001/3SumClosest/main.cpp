#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        int result = sorted_nums[0] + sorted_nums[1] + sorted_nums[2];

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            auto left = i + 1;
            auto right = sorted_nums.size() - 1;

            while(left < right) {
                int sum = sorted_nums[i] + sorted_nums[left] + sorted_nums[right];

                if (std::abs(sum - target) < std::abs(result - target)) {
                    result = sum;
                }

                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    return result;
                }
            }
        }      
        return result;
    } 
};

int main() {
    std::vector<int> nums1 = {-1, 2, 1, -4};
    std::vector<int> nums2 = {0, 0, 0};
    Solution sol;

    assert(sol.threeSumClosest(nums1, 1) == 2);
    assert(sol.threeSumClosest(nums2, 1) == 0);

    std::cout << "All tests passed\n";

    return 0;
}