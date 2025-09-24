#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

/*
DIFFICULT AS FUCK
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
    }
};

int main() {
    Solution s;
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    double result = s.findMedianSortedArrays(nums1, nums2);
    std::cout << std::setprecision(5) << std::fixed << result << std::endl;

    return 0;
}
