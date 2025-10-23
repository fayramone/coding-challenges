#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countPartitions(std::string s, int k) {
        int count = 0;

        while(!s.empty()) {

            std::unordered_map<char, int> freq;
            int prefix_len = 0;

            for (auto ch : s) {
                ++freq[ch];
                if (freq.size() > static_cast<size_t>(k)) break;
                ++prefix_len;
            }
            if (prefix_len == 0) prefix_len = 1;

            ++count;
            s = s.substr(static_cast<size_t>(prefix_len));
        }

        return count;
    }

    int maxPartitionsAfterOperations(std::string s, int k) {
        int count = countPartitions(s, k);
        std::unordered_map<char, int> letters;
        for (auto ch : s) {
            ++letters[ch];
        }

        for (size_t i = 0; i < s.size(); ++i) {
            char orig = s[i];
            bool replaced = false;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == orig) continue;
                if (letters.find(c) == letters.end()) {
                    s[i] = c;
                    count = std::max(count, countPartitions(s, k));
                    replaced = true;
                    break;
                }
            }

            if (!replaced && i > 0) {
                // s[i] = std::max_element(
                //     letters.begin(), letters.end(), 
                //     [](auto& a, auto& b){ return a.second < b.second; })->first;
                s[i] = 'a';
                count = std::max(count, countPartitions(s, k));
            }

            s[i] = orig;
        }

        return count;
    }
};

int main() {
    Solution sol;
    std::cout << sol.maxPartitionsAfterOperations("accca", 2) << std::endl;
    std::cout << sol.maxPartitionsAfterOperations("aabbcc", 2) << std::endl;
    std::cout << sol.maxPartitionsAfterOperations("abcabc", 2) << std::endl;
    std::cout << sol.maxPartitionsAfterOperations("aaaa", 1) << std::endl;
    std::cout << sol.maxPartitionsAfterOperations("abca", 1) << std::endl;
    std::cout << sol.maxPartitionsAfterOperations("abcde", 2) << std::endl;

    return 0;
}
