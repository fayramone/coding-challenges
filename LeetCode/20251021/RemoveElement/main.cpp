#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        auto count = nums.size();
        for (size_t i = 0; i < count; ) {
            if (nums[i] == val) {
                std::rotate(nums.begin() + (long)i, nums.begin() + (long)i + 1, nums.end());
                --count;
            } else ++i;
        }
        return (int)count;
    }
};

int main() {
    std::vector<int> test1 = { 3, 2, 2, 3 };
    std::vector<int> test2 = { 0,1,2,2,3,0,4,2 };

    Solution sol;
    std::cout << "Test 1: " << sol.removeElement(test1, 3)
            << "\nTest 2: " << sol.removeElement(test2, 2);

    return 0;
}