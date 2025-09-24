#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        int n = int(nums.size());
        int mid = (n + 1) / 2;
        int left = mid - 1;
        int right = n - 1;
        
        for (size_t i = 0; i < static_cast<size_t>(n); ++i) {
            if (i % 2 == 0) {
                nums[i] = sorted_nums[static_cast<size_t>(left--)];
            } else {
                nums[i] = sorted_nums[static_cast<size_t>(right--)];
            }
        }
    }
};

int main() {
    std::vector<int> nums = { 1, 5, 1, 1, 6, 4 };

    Solution sol;
    sol.wiggleSort(nums);

    for (const auto& el : nums) {
        std::cout << el << ",";
    }

    return 0;
}