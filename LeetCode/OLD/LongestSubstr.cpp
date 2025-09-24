// #include <iostream>
// #include <string>
// #include <unordered_set>

// class Solution {
// public:
//     int lengthOfLongestSubstring(std::string s) {
//         std::unordered_set<char> seen;
//         size_t max_len = 0;
//         size_t left = 0;

//         for (size_t right = 0; right < s.length(); ++right) {
//             while (seen.count(s[right])) {
//                 seen.erase(s[left]);
//                 ++left;
//             }
//             seen.insert(s[right]);
//             max_len = std::max(max_len, right - left + 1);
//         }

//         return static_cast<int>(max_len);
//     }
// };

// int main() {

//     Solution s;
//     std::cout << s.lengthOfLongestSubstring("abcabcbb");

//     return 0;

// }