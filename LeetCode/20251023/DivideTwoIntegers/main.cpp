#include <climits>
#include <iostream>
#include <cassert>
#include <stdexcept>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) 
            throw std::runtime_error("Division be zero.");

        bool positive = (dividend > 0) == (divisor > 0); 

        long long a = dividend, b = divisor;

        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        long long result = 0;
 
        while(a >= b) {
            long long temp = b;
            long long shift = 1;

            while((temp << 1) <= a) {
                temp <<= 1;
                shift <<= 1;
            }
                
            a -= temp;
            result += shift;
        }

        if (!positive) result = -result;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};

int main() {
    Solution sol;
    assert(sol.divide(10, 3) == 3);
    assert(sol.divide(7, -3) == -2);
    assert(sol.divide(-2147483648, -1) == 2147483647);
    std::cout << "All tests passed.\n";

    // int a = 3;
    // int b = a << 1; // 6
    // int c = a << 2; // 12
    // int d = a << 3; // 24


    return 0;
}