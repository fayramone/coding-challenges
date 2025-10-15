#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        size_t unique = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[unique]) {
                ++unique;
                nums[unique] = nums[i];
            }
        }
        return (int)unique + 1;
    }
};

void printVec(const std::vector<int>& nums) {
    std::cout << "Number of unique elements in the array: " << nums.size() << "\n";
    for (auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> num1 = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5 };
    std::vector<int> num2 = {};

    printVec(num1);
    printVec(num2);

    Solution sol;
    auto size1 = sol.removeDuplicates(num1);
    auto size2 = sol.removeDuplicates(num2);

    std::cout << size1 << " " << size2 << std::endl;

    return 0;
}