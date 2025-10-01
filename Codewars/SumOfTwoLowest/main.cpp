#include <iostream>
#include <vector>

long sumTwoSmallestNumbers(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end());
    return long(numbers[0] + numbers[1]);
}

int main() {
    std::vector<int> vec = { 5, 8, 12, 19, 22 };
    std::cout << sumTwoSmallestNumbers(vec) << std::endl;

    return 0;
}