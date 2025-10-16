#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findSmallestInteger(std::vector<int>& nums, int value) {
        std::unordered_map<int, int> freq;
        
        for (auto el : nums) {
            ++freq[((el % value) + value) % value];
        }

        auto i = 0;
        while(true) {
            int mod = i % value;
            if (freq[mod] == 0) return i;

            --freq[mod];
            ++i;
        }
    }
};


int main() {
    Solution sol;
    std::vector<int> test1 = { 3,0,3,2,4,2,1,1,0,4 };
    std::vector<int> test2 = { 1,-10,7,13,6,8 };
    
    assert(sol.findSmallestInteger(test1, 5) == 10);
    assert(sol.findSmallestInteger(test2, 5) == 4);
    assert(sol.findSmallestInteger(test2, 7) == 2);

    std::cout << "All tests passed.\n";

    return 0;
}

