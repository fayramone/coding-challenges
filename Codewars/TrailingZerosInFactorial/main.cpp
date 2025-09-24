// Describe(Sample_Tests)
// {
//     It(Tests)
//     {
//         Assert::That(zeros(0), Equals(0));
//         Assert::That(zeros(6), Equals(1));
//         Assert::That(zeros(30), Equals(7));
//         Assert::That(zeros(100), Equals(24));
//         Assert::That(zeros(1000), Equals(249));
//         Assert::That(zeros(100000), Equals(24999));
//         Assert::That(zeros(1000000000), Equals(249999998));
//     }
// };

#include <iostream>

long zeros(long n) {
    int x = 5;
    long result = 0;
    while(x <= n) {
        result += n / x;
        x *= 5;
    }
    return result;
}

int main() {
    std::cout << zeros(30);
    return 0;
}