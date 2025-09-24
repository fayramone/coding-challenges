#include <iostream>
#include <vector>

// class Solution {
// public:
//     std::vector<std::vector<int>> threeSum(const std::vector<int>& nums) {
//         std::vector<std::vector<int>> result;
//         for (size_t i = 0; i < nums.size() - 2; ++i) {
//             for (size_t j = i + 1; j < nums.size() - 1; ++j) {
//                 for (size_t k = j + 1; k < nums.size(); ++k) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         std::vector<int> temp = { nums[i], nums[j], nums[k] };
//                         result.push_back(temp);
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;

            size_t left = i + 1;
            size_t right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    std::vector<int> temp = {nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    ++left, --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else {
                    (sum < 0) ? ++left : --right;
                }
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    
    std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    //std::vector<int> nums = { 0, 0, 0 };
    auto result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        for (const auto& el : triplet) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}