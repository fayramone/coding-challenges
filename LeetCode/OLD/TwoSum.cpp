// #include <iostream>
// #include <vector>
// #include <unordered_map>

// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target) {
//         std::unordered_map<int, int> numMap;

//         for (size_t i = 0; i < nums.size(); ++i) {
//             auto num2 = target - nums[i];

//             if (numMap.find(num2) != numMap.end()) {
//                 return { numMap[num2], int(i) };
//             }

//             numMap[nums[i]] = int(i);
//         }

//         throw std::invalid_argument("no one solution");
//     }
// };

// int main() {
//     Solution sol;
//     std::vector<int> nums = { 10, 1, 5, 6, 7, 8, 9 };
//     int target = 9;
//     std::vector<int> result = sol.twoSum(nums, target);

//     std::cout << "[" << result[0] << "," << result[1] << "]\n";


//     return 0;
// }