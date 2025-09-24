#include <iostream>


class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;
        return (int)res;
    }
};

int main() {
    Solution sol;
    int x = 1534236469;
    std::cout << sol.reverse(x) << std::endl;

    return 0;
}