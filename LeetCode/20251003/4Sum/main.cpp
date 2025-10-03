/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        size_t n = nums.size();

        if (n < 4) return result;

        for (size_t i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (size_t j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                size_t left = j + 1, right = n - 1;
                while(left < right) {
                    long long current = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (current == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;

                    } else if (current < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = { 1, 0, -1, 0, -2, 2 };
    std::vector<int> nums2 = { 2, 2, 2, 2, 2 };
    auto result1 = sol.fourSum(nums1, 0);
    auto result2 = sol.fourSum(nums2, 8);

    for (auto vec : result1) {
        std::cout << "[ ";
        for (auto num : vec) {
            std::cout << num << ", ";
        }
        std::cout << " ], ";
    }

    std::cout << std::endl;

    for (auto vec : result2) {
        std::cout << "[ ";
        for (auto num : vec) {
            std::cout << num << ", ";
        }
        std::cout << " ], ";
    }


    return 0;
}

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]