#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<size_t> idx_stack;

        for (size_t i = 0; i < temperatures.size(); ++i) {
            while (!idx_stack.empty() && temperatures[i] > temperatures[idx_stack.top()]) {
                size_t idx = idx_stack.top();
                idx_stack.pop();
                result[idx] = int(i - idx);
            }
            idx_stack.push(i);
        }

        return result;
    }
};


int main() {
    Solution solution;
    std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
    std::vector<int> result = solution.dailyTemperatures(temperatures);
    for (const auto& el : result) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    return 0;
}